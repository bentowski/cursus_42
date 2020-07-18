# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbaudry </var/mail/bbaudry>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/18 15:37:02 by bbaudry           #+#    #+#              #
#    Updated: 2020/07/18 15:37:09 by bbaudry          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:buster

COPY	./srcs/start.sh ./
COPY	./srcs/ ./srcs/

RUN	apt-get update\
&&	apt-get upgrade -y\
&&	apt-get -y install wget nginx mariadb-server mariadb-client\
&& 	apt-get -y install php7.3-fpm php7.3-mysql php-mbstring php-zip\
&& 	apt-get clean

#CONFIG NGINX
RUN	mkdir -p /var/www/localhost
COPY	/srcs/nginx.conf /etc/nginx/sites-available/localhost
RUN	ln -s /etc/nginx/sites-available/localhost /etc/nginx/sites-enabled/localhost

#CONFIG PHP
RUN	service php7.3-fpm start

#CONFIG SSL
RUN	mkdir ~/mkcert\
&&	cd ~/mkcert\
&& 	wget https://github.com/FiloSottile/mkcert/releases/download/v1.4.1/mkcert-v1.4.1-linux-amd64\
&& 	mv mkcert-v1.4.1-linux-amd64 mkcert\
&& 	chmod 755 mkcert\
&& 	./mkcert -install\
&& 	./mkcert localhost

#CONFIG WORDPRESS
RUN	wget https://fr.wordpress.org/latest-fr_FR.tar.gz\
&& 	mkdir -p /var/www/localhost/wordpress\
&& 	tar -zxvf *.tar.gz --strip-components=1 -C /var/www/localhost/wordpress\
&& 	chown -R www-data:www-data /var/www/localhost/wordpress\
&& 	chmod 755 -R /var/www/localhost/wordpress/
COPY	/srcs/wp-config.php /var/www/localhost/wordpress

#CONFIG PHPMYADMIN
RUN	mkdir -p /var/www/localhost/phpmyadmin\
&&	wget https://files.phpmyadmin.net/phpMyAdmin/4.9.4/phpMyAdmin-4.9.4-all-languages.tar.gz\
&& 	tar -zxvf phpMyAdmin-4.9.4-all-languages.tar.gz --strip-components=1 -C /var/www/localhost/phpmyadmin\
&& 	mkdir -p /var/www/localhost/phpmyadmin/tmp\
&&	chown -R www-data:www-data /var/www/localhost/phpmyadmin

#COPY FICHIERS CONFIG
COPY	/srcs/config.inc.php /var/www/localhost/phpmyadmin/
COPY	/srcs/index.php /var/www/localhost/index.php

CMD		bash start.sh
