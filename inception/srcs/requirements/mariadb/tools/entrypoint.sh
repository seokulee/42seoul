#!/bin/sh

set -e

mariadbd    --user=mysql            \
            --datadir=/var/lib/mysql\
            --bootstrap << EOF
    FLUSH PRIVILEGES;
    CREATE USER IF NOT EXISTS root@localhost IDENTIFIED BY '$MYSQL_ROOT_PASSWORD';
    SET PASSWORD FOR root@localhost = PASSWORD('$MYSQL_ROOT_PASSWORD');
    GRANT ALL ON *.* TO root@localhost WITH GRANT OPTION;
    CREATE USER IF NOT EXISTS root@'%' IDENTIFIED BY '$MYSQL_ROOT_PASSWORD';
    SET PASSWORD FOR root@'%' = PASSWORD('$MYSQL_ROOT_PASSWORD');
    GRANT ALL ON *.* TO root@'%' WITH GRANT OPTION;
    CREATE DATABASE IF NOT EXISTS $MYSQL_DATABASE;
    CREATE USER IF NOT EXISTS $MYSQL_USER_ID@'%' IDENTIFIED BY '$MYSQL_USER_PASSWORD';
    SET PASSWORD FOR $MYSQL_USER_ID@'%' = PASSWORD('$MYSQL_USER_PASSWORD');
    GRANT ALL ON $MYSQL_DATABASE.* TO $MYSQL_USER_ID@'%' WITH GRANT OPTION;
EOF

exec $@