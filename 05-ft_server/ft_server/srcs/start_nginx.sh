# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    start_nginx.sh                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msessa <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/30 16:34:16 by msessa            #+#    #+#              #
#    Updated: 2021/05/03 17:54:54 by msessa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

rm -f /etc/nginx/sites-enabled/default

if [ $# == 1 ]
	then
	if [ $1 == 'on' ]
		then
			export autoindex='on'
		elif [ $1 == 'off' ]
			then
				export autoindex='off'
	fi
fi
if [ $autoindex == 'on' ]
	then
		ln -s /etc/nginx/sites-available/default /etc/nginx/sites-enabled/
		echo "autoindex ON"
	else
		ln -s /etc/nginx/sites-available/no-autoindex /etc/nginx/sites-enabled/default
		echo "autoindex OFF"
fi
service nginx restart
