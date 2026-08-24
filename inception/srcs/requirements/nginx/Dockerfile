FROM debian:bookworm

RUN apt-get update && \
    apt-get install -y --no-install-recommends \
        nginx \
        openssl \
        gettext-base && \
    rm -rf /var/lib/apt/lists/*

COPY conf/inception.conf.template /etc/nginx/inception.conf.template
COPY tools/entrypoint.sh /usr/local/bin/entrypoint.sh

# Debian's default site listens on :80. Remove it so 443 is the only entrypoint.
RUN chmod +x /usr/local/bin/entrypoint.sh && \
    rm -f /etc/nginx/sites-enabled/default && \
    mkdir -p /etc/nginx/ssl /var/www/html

EXPOSE 443

ENTRYPOINT ["/usr/local/bin/entrypoint.sh"]
