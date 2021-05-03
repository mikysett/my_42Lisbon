# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msessa <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/30 12:32:49 by msessa            #+#    #+#              #
#    Updated: 2021/05/03 17:06:19 by msessa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM	debian:buster

EXPOSE 80
EXPOSE 443

RUN	apt-get update && apt-get upgrade -y && apt-get install -y \
	git \
	nginx \
	mariadb-server \
	mariadb-client \
	php-cgi \
	php-common \
	php-fpm \
	php-pear \
	php-mbstring \
	php-zip \
	php-net-socket \
	php-gd \
	php-xml-util \
	php-gettext \
	php-mysql \
	php-bcmath \
	unzip \
	wget

RUN	service mysql start && \
	echo "CREATE DATABASE wpdb;" | mysql -u root && \
	echo "CREATE USER 'wpuser'@'localhost' identified by 'dbpassword';" | mysql -u root && \
	echo "GRANT ALL PRIVILEGES ON wpdb.* TO 'wpuser'@'localhost';" | mysql -u root && \
	echo "FLUSH PRIVILEGES;" | mysql -u root && \
	echo "update mysql.user set plugin='' where user='root';"| mysql -u root && \
	echo "EXIT" | mysql -u root

RUN	cd /var/www/html/ && \
	wget https://wordpress.org/latest.tar.gz && \
	tar -xvzf latest.tar.gz && \
	rm -f latest.tar.gz && \
	rm -f wordpress/wp-config-sample.php

RUN	cd /var/www/html/ && \
	wget https://files.phpmyadmin.net/phpMyAdmin/5.0.1/phpMyAdmin-5.0.1-english.tar.gz && \
	tar -xf phpMyAdmin-5.0.1-english.tar.gz && rm -rf phpMyAdmin-5.0.1-english.tar.gz && \
	mv phpMyAdmin-5.0.1-english wordpress/phpmyadmin

RUN openssl req -newkey rsa:2048 \
	-x509 \
	-nodes \
	-days 365 \
	-subj "/C=PT/ST=Lisbon/L=Lisbon/O=42Lisboa/OU=msessa/CN=localhost" \
	-keyout /etc/ssl/nginx-selfsigned.key \
	-out /etc/ssl/nginx-selfsigned.crt;

COPY	srcs ./root/

RUN	mv ./root/wp-config.php /var/www/html/wordpress/wp-config.php
RUN	mv ./root/config.inc.php /var/www/html/wordpress/phpmyadmin/config.inc.php
RUN chown -R www-data:www-data /var/www/html/wordpress
RUN chmod -R 755 /var/www/*

RUN	mv ./root/wordpress.conf /etc/nginx/sites-available/default
RUN	mv ./root/no-autoindex.conf /etc/nginx/sites-available/no-autoindex

ENV autoindex on

VOLUME /var/lib/mysql
VOLUME /var/www/html/wordpress

WORKDIR	/root/

ENTRYPOINT	["bash", "start_container.sh"]
