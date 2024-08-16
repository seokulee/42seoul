FROM alpine:3.19

RUN apk upgrade --no-cache &&               \
    apk add --no-cache  openssl             \
                        nginx               \
                        curl &&             \
    adduser -u 1000 -D -h /var/www www &&   \
    chown -R www:www /var/www

COPY --chmod=644 ./conf/nginx.conf /etc/nginx/nginx.conf

EXPOSE 443

ENTRYPOINT ["nginx", "-g", "daemon off;"]

STOPSIGNAL SIGQUIT
