#!/bin/sh
# Entrypoint for the nginx container.
set -e

CERT=/etc/nginx/ssl/inception.crt
KEY=/etc/nginx/ssl/inception.key

if [ ! -f "$CERT" ] || [ ! -f "$KEY" ]; then
    echo "[nginx] generating self-signed certificate for $DOMAIN_NAME..."
    openssl req -x509 -nodes \
        -newkey rsa:2048 \
        -days 365 \
        -keyout "$KEY" \
        -out "$CERT" \
        -subj "/C=FR/ST=Normandie/L=Le Havre/O=42/OU=42/CN=$DOMAIN_NAME"
fi

# Only ${DOMAIN_NAME} is substituted. Listing it explicitly protects nginx's
# own $uri / $args / $document_root variables from being blanked out.
envsubst '${DOMAIN_NAME}' \
    < /etc/nginx/inception.conf.template \
    > /etc/nginx/conf.d/inception.conf

nginx -t

echo "[nginx] starting in foreground..."
exec nginx -g "daemon off;"
