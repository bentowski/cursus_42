# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    start.sh                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbaudry </var/mail/bbaudry>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/18 15:37:21 by bbaudry           #+#    #+#              #
#    Updated: 2020/07/18 15:39:28 by bbaudry          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# LAUNCH SERVICES

service mysql start

echo "CREATE DATABASE wordpress;" | mysql -u root
echo "CREATE USER 'admin'@'localhost' IDENTIFIED BY 'admin';" | mysql -u root
echo "GRANT USAGE ON *.* TO 'admin'@'localhost' IDENTIFIED BY 'admin';" | mysql -u root
echo "GRANT ALL privileges ON *.* TO 'admin'@localhost;" | mysql -u root
echo "FLUSH PRIVILEGES;" | mysql -u root

service nginx restart
service mysql restart
service php7.3-fpm restart

bash

