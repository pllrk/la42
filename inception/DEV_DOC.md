# Developer documentation

## Prerequisites

* A Debian virtual machine (this project must run in a VM).
* `docker-ce`, `docker-ce-cli`, `containerd.io` and `docker-compose-plugin`
  from Docker's own repository — Debian's `docker.io` package does not ship
  the `docker compose` v2 plugin.
* `make`, `git`, `openssl`.
* Your user in the `docker` group (`sudo usermod -aG docker $USER`, then log
  out and back in).

Verify with `docker compose version` — v2.x is required for the `name:` key,
`depends_on.condition` and the secrets syntax used here.

## Setting up from scratch

```sh
git clone <repo> inception && cd inception

# 1. Environment (non-secret configuration)
cp srcs/.env.sample srcs/.env
$EDITOR srcs/.env          # set DOMAIN_NAME and the usernames

# 2. Secrets (passwords) — generated locally, never committed
make secrets

# 3. Host resolution
make host

# 4. Build and launch
make
```

`make secrets` generates random passwords only for files that do not already
exist, so it is safe to re-run. It also refuses to continue if `srcs/.env` is
missing.

### Repository layout

```
.
├── Makefile                 entry point for every operation
├── README.md
├── USER_DOC.md
├── DEV_DOC.md
├── .gitignore               ignores srcs/.env and secrets/*.txt
├── secrets/                 gitignored, one password per file
│   ├── credentials.txt
│   ├── db_password.txt
│   └── db_root_password.txt
└── srcs/
    ├── .env                 gitignored
    ├── .env.sample          committed template
    ├── docker-compose.yml
    └── requirements/
        ├── mariadb/  { Dockerfile, .dockerignore, conf/, tools/ }
        ├── nginx/    { Dockerfile, .dockerignore, conf/, tools/ }
        └── wordpress/{ Dockerfile, .dockerignore, conf/, tools/ }
```

Each service directory is self-contained and is used as its own build context,
which is why the `.dockerignore` files sit inside them rather than at the root.

## Build and launch

The Makefile is a thin wrapper over Compose:

```make
COMPOSE := docker compose -f srcs/docker-compose.yml
up: $(DATA_DIR) secrets
	$(COMPOSE) up -d --build
```

Compose resolves `srcs/.env` automatically because it sits next to the compose
file. The `secrets:` block paths are relative to the compose file, hence
`../secrets/...`.

Build order is not something the Makefile controls; Compose does it, and
`depends_on` controls start order:

* `wordpress` waits for `mariadb` to report **healthy**, not merely started.
  The healthcheck runs an actual `SELECT 1;` as root over the unix socket.
* `nginx` waits for `wordpress` to have started (php-fpm has no meaningful
  health probe here, and nginx tolerates a brief 502).

## Useful commands

```sh
# containers
docker compose -f srcs/docker-compose.yml ps
docker compose -f srcs/docker-compose.yml logs -f wordpress
docker exec -it mariadb sh
docker compose -f srcs/docker-compose.yml restart nginx

# rebuild a single service without touching the others
docker compose -f srcs/docker-compose.yml up -d --build nginx

# images
docker images                       # nginx:1.0, wordpress:1.0, mariadb:1.0
docker history mariadb:1.0          # confirm no secret leaked into a layer

# network
docker network ls
docker network inspect inception_inception
docker exec nginx getent hosts wordpress    # embedded DNS resolution

# volumes
docker volume ls
docker volume inspect inception_mariadb_data
docker volume inspect inception_wordpress_data

# database
docker exec -it mariadb mariadb -u root -p"$(cat secrets/db_root_password.txt)"
#   SHOW DATABASES;
#   USE wordpress; SHOW TABLES; SELECT user_login FROM wp_users;
```

## Where the data lives and how it persists

Two named volumes, both backed by a directory under `/home/plerick/data` via
`driver_opts` on the `local` driver:

| Volume            | Container path   | Host path                     |
|-------------------|------------------|-------------------------------|
| `mariadb_data`    | `/var/lib/mysql` | `/home/plerick/data/mariadb`     |
| `wordpress_data`  | `/var/www/html`  | `/home/plerick/data/wordpress`   |

`wordpress_data` is mounted into **two** containers: `wordpress` writes the PHP
files and uploads, `nginx` reads the static assets from the same tree.

Persistence works because both entrypoints are idempotent. `mariadb` runs
`mariadb-install-db` only when `/var/lib/mysql/mysql` is absent; `wordpress`
runs `wp core install` only when `wp-config.php` is absent. On a reboot, or
after `make down && make`, the volumes are still populated, both checks are
false, and the services start against existing data.

`make clean` and `make fclean` remove the volumes. That is the only supported
way to lose data — and the way to test a clean first-run.

### Verifying persistence the way the evaluation does

```sh
# make a change (edit a page or post a comment in the browser), then:
sudo reboot
# after reboot:
cd inception && make
# reload https://plerick.42.fr — the change must still be there
```
