# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    start_nginx.sh                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msessa <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/30 16:34:16 by msessa            #+#    #+#              #
#    Updated: 2021/05/03 16:16:43 by msessa           ###   ########.fr        #
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
	else
		ln -s /etc/nginx/sites-available/no-autoindex /etc/nginx/sites-enabled/default
fi
service nginx restart
