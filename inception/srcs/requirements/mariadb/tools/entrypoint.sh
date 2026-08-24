#!/bin/sh
# Entrypoint for the mariadb container.
# Runs once as PID 1, initialises the datadir if the named volume is empty,
# then REPLACES ITSELF with the mariadbd daemon via exec.
set -e

DB_ROOT_PASSWORD="$(cat /run/secrets/db_root_password)"
DB_PASSWORD="$(cat /run/secrets/db_password)"

# /var/lib/mysql is a named volume. On the very first run it is empty, so the
# system tables do not exist yet. On every later run (including after a reboot)
# this test is false and we skip straight to exec.
if [ ! -d /var/lib/mysql/mysql ]; then
    echo "[mariadb] empty datadir detected, initialising..."

    mariadb-install-db \
        --user=mysql \
        --datadir=/var/lib/mysql \
        --auth-root-authentication-method=normal \
        --skip-test-db > /dev/null

    cat > /tmp/bootstrap.sql << EOSQL
USE mysql;
FLUSH PRIVILEGES;
DELETE FROM mysql.global_priv WHERE User='';
DROP DATABASE IF EXISTS test;
SET PASSWORD FOR 'root'@'localhost' = PASSWORD('${DB_ROOT_PASSWORD}');
CREATE DATABASE IF NOT EXISTS \`${MYSQL_DATABASE}\`
    CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci;
CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${DB_PASSWORD}';
GRANT ALL PRIVILEGES ON \`${MYSQL_DATABASE}\`.* TO '${MYSQL_USER}'@'%';
FLUSH PRIVILEGES;
EOSQL

    # --bootstrap runs the server in a single-threaded, no-network mode,
    # executes the SQL from stdin, then exits. No background process,
    # no "sleep 5 && mysql -u root" race.
    mariadbd --user=mysql --bootstrap < /tmp/bootstrap.sql
    rm -f /tmp/bootstrap.sql

    echo "[mariadb] initialisation done."
fi

echo "[mariadb] starting server in foreground..."
exec mariadbd --user=mysql --console
