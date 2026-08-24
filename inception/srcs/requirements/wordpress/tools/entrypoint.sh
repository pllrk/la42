#!/bin/sh
# Entrypoint for the wordpress (php-fpm) container.
set -e

DB_PASSWORD="$(cat /run/secrets/db_password)"
# credentials holds WP_ADMIN_PASSWORD and WP_USER_PASSWORD as shell assignments.
. /run/secrets/credentials

WP_PATH=/var/www/html

# ---------------------------------------------------------------------------
# Wait for MariaDB. compose already gates us behind `condition: service_healthy`
# so this should return on the first try; it is a bounded safety net, NOT an
# infinite loop (which the subject forbids).
# ---------------------------------------------------------------------------
attempt=0
until mariadb -h "$MYSQL_HOST" -u "$MYSQL_USER" -p"$DB_PASSWORD" \
        -e "SELECT 1;" >/dev/null 2>&1; do
    attempt=$((attempt + 1))
    if [ "$attempt" -ge 30 ]; then
        echo "[wordpress] MariaDB unreachable after 30 attempts, aborting." >&2
        exit 1
    fi
    echo "[wordpress] waiting for MariaDB ($attempt/30)..."
    sleep 2
done

# ---------------------------------------------------------------------------
# First run only: install WordPress into the named volume.
# ---------------------------------------------------------------------------
if [ ! -f "$WP_PATH/wp-config.php" ]; then
    echo "[wordpress] no wp-config.php, installing WordPress..."

    wp core download --path="$WP_PATH" --allow-root

    wp config create \
        --path="$WP_PATH" \
        --dbname="$MYSQL_DATABASE" \
        --dbuser="$MYSQL_USER" \
        --dbpass="$DB_PASSWORD" \
        --dbhost="$MYSQL_HOST" \
        --skip-check \
        --allow-root

    wp core install \
        --path="$WP_PATH" \
        --url="https://$DOMAIN_NAME" \
        --title="$WP_TITLE" \
        --admin_user="$WP_ADMIN_USER" \
        --admin_password="$WP_ADMIN_PASSWORD" \
        --admin_email="$WP_ADMIN_EMAIL" \
        --skip-email \
        --allow-root

    wp user create "$WP_USER" "$WP_USER_EMAIL" \
        --path="$WP_PATH" \
        --role=author \
        --user_pass="$WP_USER_PASSWORD" \
        --allow-root

    echo "[wordpress] installation complete."
else
    echo "[wordpress] existing installation found, skipping install."
fi

chown -R www-data:www-data "$WP_PATH"

# -F = run in the foreground. The FPM master becomes PID 1 and receives
# SIGTERM directly from `docker stop`.
echo "[wordpress] starting php-fpm in foreground..."
exec php-fpm8.2 -F
