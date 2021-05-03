# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msessa <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/30 12:32:49 by msessa            #+#    #+#              #
#    Updated: 2021/05/01 12:11:06 by msessa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM	debian:buster

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
	echo "EXIT" | mysql -u root

RUN	cd /var/www/html/ && \
	wget https://wordpress.org/latest.tar.gz && \
	tar -xvzf latest.tar.gz && \
	rm -f latest.tar.gz && \
	rm -f wordpress/wp-config-sample.php

COPY	srcs ./root/

RUN	mv ./root/wp-config.php /var/www/html/wordpress/wp-config.php
RUN chown -R www-data:www-data /var/www/html/wordpress

RUN	mv ./root/wordpress.conf /etc/nginx/sites-available/wordpress.conf
RUN	ln -s /etc/nginx/sites-available/wordpress.conf /etc/nginx/sites-enabled/

WORKDIR	/root/

ENTRYPOINT	["bash", "start_container.sh"]
