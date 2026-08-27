# **************************************************************************** #
#                                  INCEPTION                                   #
# **************************************************************************** #

LOGIN		:= plerick
DATA_DIR	:= /home/$(LOGIN)/data
COMPOSE		:= docker compose -f srcs/docker-compose.yml
SECRETS		:= secrets

.PHONY: all up build down stop start restart re clean fclean logs ps status secrets host

all: up

# ---------------------------------------------------------------------------
# Lifecycle
# ---------------------------------------------------------------------------

up: $(DATA_DIR) secrets
	$(COMPOSE) up -d --build

build: $(DATA_DIR) secrets
	$(COMPOSE) build

down:
	$(COMPOSE) down

stop:
	$(COMPOSE) stop

start:
	$(COMPOSE) start

restart:
	$(COMPOSE) restart

re: fclean all

# ---------------------------------------------------------------------------
# Host preparation
# ---------------------------------------------------------------------------

$(DATA_DIR):
	mkdir -p $(DATA_DIR)/mariadb
	mkdir -p $(DATA_DIR)/wordpress

# Generates the secret files locally if they do not exist yet.
# These files are gitignored and never leave the machine.
secrets:
	@mkdir -p $(SECRETS)
	@test -f $(SECRETS)/db_root_password.txt || \
		openssl rand -base64 24 | tr -d '\n' > $(SECRETS)/db_root_password.txt
	@test -f $(SECRETS)/db_password.txt || \
		openssl rand -base64 24 | tr -d '\n' > $(SECRETS)/db_password.txt
	@test -f $(SECRETS)/credentials.txt || { \
		printf "WP_ADMIN_PASSWORD='%s'\n" "$$(openssl rand -base64 18 | tr -d '\n')" \
			>  $(SECRETS)/credentials.txt ; \
		printf "WP_USER_PASSWORD='%s'\n"  "$$(openssl rand -base64 18 | tr -d '\n')" \
			>> $(SECRETS)/credentials.txt ; \
	}
	@chmod 600 $(SECRETS)/*.txt
	@test -f srcs/.env || { \
		echo "srcs/.env is missing. Copy srcs/.env.sample to srcs/.env first." >&2 ; \
		exit 1 ; \
	}

# Adds the domain to /etc/hosts (needs sudo). Run once per machine.
host:
	@grep -q "$(LOGIN).42.fr" /etc/hosts || \
		echo "127.0.0.1 $(LOGIN).42.fr" | sudo tee -a /etc/hosts

# ---------------------------------------------------------------------------
# Inspection
# ---------------------------------------------------------------------------

ps status:
	$(COMPOSE) ps

logs:
	$(COMPOSE) logs -f

# ---------------------------------------------------------------------------
# Cleaning
# ---------------------------------------------------------------------------

# Stops the containers and removes THIS project's named volumes.
# The database and the site content are lost.
clean:
	$(COMPOSE) down -v --remove-orphans

# clean + removes the three images built by this project + wipes the host
# data directories. Deliberately does NOT run `docker system prune`, which
# would delete images, containers and volumes belonging to other projects.
fclean: clean
	-docker image rm -f nginx:1.0 wordpress:1.0 mariadb:1.0 2>/dev/null || true
	-sudo rm -rf $(DATA_DIR)/mariadb/* $(DATA_DIR)/wordpress/*
