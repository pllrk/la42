*This project has been created as part of the 42 curriculum by plerick.*

# Inception

## Description

Inception builds a small, self-contained web infrastructure inside a virtual
machine, using Docker Compose. Three services, each in its own container, each
built from a Dockerfile written from scratch on top of a plain Debian base
image:

| Service     | Role                                                  | Port |
|-------------|-------------------------------------------------------|------|
| `nginx`     | TLS termination and reverse proxy, sole public entry   | 443  |
| `wordpress` | WordPress + php-fpm, no web server of its own          | 9000 |
| `mariadb`   | The database backing WordPress                         | 3306 |

Only port 443 is published to the host. `wordpress` and `mariadb` are reachable
only from inside the private `inception` bridge network.

Two named volumes persist state across container removal and VM reboots:
`wordpress_data` (the site files) and `mariadb_data` (the database).

## Instructions

```sh
cp srcs/.env.sample srcs/.env   # then edit DOMAIN_NAME and the usernames
make host                       # adds <login>.42.fr to /etc/hosts (sudo)
make                            # builds the images and starts the stack
```

Then open `https://<login>.42.fr` and accept the self-signed certificate
warning. See `USER_DOC.md` for day-to-day usage and `DEV_DOC.md` for the
developer workflow.

## Project description

### Design choices

* **One process per container.** Each entrypoint script ends with `exec`, so the
  service binary replaces the shell and becomes PID 1. It receives `SIGTERM`
  from `docker stop` directly and shuts down cleanly. No `tail -f`, no
  `sleep infinity`, no backgrounded daemon.
* **Idempotent entrypoints.** Initialisation (creating the MariaDB datadir,
  downloading and installing WordPress) is guarded by a check on the volume
  contents. The second start, and every start after a reboot, skips straight to
  `exec`.
* **Secrets are files, not build arguments.** No password appears in a
  Dockerfile, in `docker-compose.yml`, in `.env`, or in the image history.
* **Configuration is templated at runtime.** `DOMAIN_NAME` is injected into the
  nginx server block with `envsubst` at container start, so the image is not
  tied to one login.

### Virtual Machines vs Docker

A VM virtualises hardware: the hypervisor presents virtual CPU, disk and NICs,
and each guest boots its own full kernel and init system. Isolation is strong
but the overhead is a whole operating system per workload — gigabytes of disk,
hundreds of megabytes of RAM, tens of seconds to boot.

A container virtualises the operating system instead. Every container on a host
shares that host's kernel; isolation comes from kernel features — namespaces
(pid, net, mnt, uts, ipc, user) partition what a process can *see*, and cgroups
limit what it can *consume*. A container image is just a stack of filesystem
layers plus metadata, so starting a container is roughly starting a process.
The trade-off: containers cannot run a different kernel from the host, and a
kernel exploit escapes the isolation boundary in a way it would not escape a
hypervisor.

For this project that trade-off is exactly right — three Linux services on one
Linux host, where startup speed and reproducibility matter far more than
kernel-level isolation.

### Secrets vs Environment Variables

Environment variables are convenient and visible: they show up in
`docker inspect`, in `/proc/<pid>/environ`, in the output of `env` from any
process in the container, and often in crash dumps and logs. They are fine for
non-sensitive configuration — a hostname, a database name, a site title.

Docker secrets are mounted as read-only files under `/run/secrets/<name>` on a
tmpfs. They are not in the image, not in the image history, not in the
container's environment block, and never touch the container's writable layer.
The entrypoint reads the file once, uses the value, and does not re-export it.

This project uses both, deliberately: `.env` carries `DOMAIN_NAME`,
`MYSQL_DATABASE`, `MYSQL_USER` and the WordPress usernames; `secrets/` carries
the three passwords.

### Docker Network vs Host Network

With `network: host` a container shares the host's network namespace outright:
it binds directly to host interfaces, there is no NAT and no isolation, and two
containers cannot both bind port 3306. It is forbidden here, and rightly so —
it would expose MariaDB and php-fpm on the host.

A user-defined bridge network gives the containers a private L2 segment with
their own namespace and IPs. Two properties matter here: Docker runs an
embedded DNS server at 127.0.0.11 that resolves **service names** to container
IPs — which is why the nginx config can say `fastcgi_pass wordpress:9000` and
`wp-config.php` can say `DB_HOST=mariadb` without knowing any IP — and nothing
inside the network is reachable from outside unless the port is explicitly
published. Only nginx publishes one.

The legacy `--link` flag did something similar by writing `/etc/hosts` entries,
but it is one-directional, static, and deprecated; user-defined networks
replaced it.

### Docker Volumes vs Bind Mounts

A bind mount maps an arbitrary host path into the container. The host path must
already exist with the right ownership, permissions and SELinux labels; Docker
does not manage it, does not know about it, and it does not appear in
`docker volume ls`.

A named volume is an object Docker owns: it has a name, a driver, and a
lifecycle managed with `docker volume create/ls/inspect/rm`. It is created
automatically if missing, and it is portable — swap the driver and the same
compose file stores data on NFS or a cloud disk.

The subject asks for named volumes whose data nevertheless lands in
`/home/<login>/data`. That is done with `driver_opts` on the built-in `local`
driver:

```yaml
mariadb_data:
  driver: local
  driver_opts:
    type: none
    o: bind
    device: /home/plerick/data/mariadb
```

The object is a first-class named volume — it shows in `docker volume ls` and
`docker volume inspect` reports the host path — while the `local` driver is
told to back it with a bind of that directory.

## Resources

* Docker documentation — <https://docs.docker.com/>
  (Dockerfile reference, Compose file reference, networking, storage)
* Docker Compose specification — <https://github.com/compose-spec/compose-spec>
* nginx documentation — `ngx_http_ssl_module`, `ngx_http_fastcgi_module`
* PHP-FPM configuration reference — <https://www.php.net/manual/en/install.fpm.configuration.php>
* MariaDB Knowledge Base — `mariadb-install-db`, `mariadbd --bootstrap`
* WP-CLI handbook — <https://make.wordpress.org/cli/handbook/>
* Debian Wiki — Docker, and the Debian releases page for identifying the
  penultimate stable release

### Use of AI

AI (Claude) was used as a documentation-lookup and review tool, specifically:

* to summarise the difference between namespaces/cgroups isolation and
  hypervisor isolation while writing the *Project description* section;
* to sanity-check the `driver_opts` syntax for backing a named volume with a
  host directory;
* to review the entrypoint scripts for shell portability and for accidental
  background processes.

Every generated suggestion was tested against the running stack (`docker
inspect`, `openssl s_client`, `docker compose logs`) before being kept. The
Dockerfiles, the compose file and the configuration files were assembled and
verified by hand; no snippet was retained that I could not explain line by
line.
