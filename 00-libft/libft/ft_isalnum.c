/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 11:14:44 by msessa            #+#    #+#             */
/*   Updated: 2021/01/15 13:58:54 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	c = (unsigned char)c;
	return ((c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'));
}

// int main ()
// {
//     printf("************* ft_isalnum **********************\n");
//     int i;
// 	int nb_err;

//     i = -1;
// 	nb_err = 0;
//     while (i < 530)
//     {
//         if ((ft_isalnum(i) == 0 && isalnum(i) != 0)
// 			|| (ft_isalnum(i) != 0 && isalnum(i) == 0))
// 		{
//         	printf("i:%d c:%c| uci: %3d c:%c| %d | %d\n", i, i, (unsigned char)i, (unsigned char)i, ft_isalnum(i), isalnum(i));
// 			nb_err++;
// 		}
//         i++;
//     }
// 	printf("number of errors: %d\n", nb_err);
// 	return (0);
// }
