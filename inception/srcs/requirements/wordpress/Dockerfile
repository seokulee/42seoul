FROM alpine:3.19

RUN apk upgrade --no-cache &&               \
    apk add --no-cache  curl                \
                        php81               \
                        php81-fpm           \
                        php81-mysqli        \
                        php81-curl          \
                        php81-phar          \
                        php81-iconv         \
                        php81-tokenizer     \
                        mariadb-client      \
                        fcgi &&             \
    adduser -u 1000 -D -h /var/www www &&   \
    chown -R www:www /var/www

RUN ln -s /usr/bin/php81 /usr/bin/php

WORKDIR /var/www

ADD --chmod=755 https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar /usr/local/bin/wp

COPY --chmod=644 conf/www.conf /etc/php81/php-fpm.d/www.conf
COPY --chmod=755 tools/entrypoint.sh /

ENTRYPOINT ["/entrypoint.sh"]

STOPSIGNAL SIGQUIT
