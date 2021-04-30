# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msessa <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/30 12:32:49 by msessa            #+#    #+#              #
#    Updated: 2021/04/30 17:27:49 by msessa           ###   ########.fr        #
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
	unzip

RUN	service mysql start
RUN	mysql -u root -p
RUN	CREATE DATABASE wpdb;
RUN	CREATE USER 'wpuser'@'localhost' identified by 'dbpassword';
RUN	GRANT ALL PRIVILEGES ON wpdb.* TO 'wpuser'@'localhost';
RUN	FLUSH PRIVILEGES;
RUN	EXIT

COPY	srcs ./root/

RUN	mv ./root/wordpress.conf /etc/nginx/sites-available/wordpress.conf
RUN	ln -s /etc/nginx/sites-available/wordpress.conf /etc/nginx/sites-enabled/

WORKDIR	/root/

ENTRYPOINT	["bash", "start_container.sh"]
