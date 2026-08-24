FROM debian:bookworm

# php8.2-cli is required by wp-cli (the wp phar is executed by the CLI SAPI).
# php8.2-mysql provides both mysqli and pdo_mysql, which WordPress needs.
RUN apt-get update && \
    apt-get install -y --no-install-recommends \
        php8.2-fpm \
        php8.2-cli \
        php8.2-mysql \
        php8.2-curl \
        php8.2-gd \
        php8.2-mbstring \
        php8.2-xml \
        php8.2-zip \
        php8.2-intl \
        curl \
        ca-certificates \
        mariadb-client && \
    rm -rf /var/lib/apt/lists/*

# wp-cli: a PHP archive, not a Docker image. Fetching it is allowed.
RUN curl -fsSL https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
        -o /usr/local/bin/wp && \
    chmod +x /usr/local/bin/wp

COPY conf/www.conf /etc/php/8.2/fpm/pool.d/www.conf
COPY tools/entrypoint.sh /usr/local/bin/entrypoint.sh

RUN chmod +x /usr/local/bin/entrypoint.sh && \
    mkdir -p /run/php /var/www/html && \
    chown -R www-data:www-data /var/www/html

WORKDIR /var/www/html

EXPOSE 9000

ENTRYPOINT ["/usr/local/bin/entrypoint.sh"]
