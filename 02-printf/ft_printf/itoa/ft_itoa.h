/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 20:08:41 by msessa            #+#    #+#             */
/*   Updated: 2021/02/24 12:18:58 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ITOA_H
# define FT_ITOA_H
# include "../libft/libft.h"
# include "../ft_printf.h"

char		*ft_citoa(char n);
char		*ft_sitoa(short n);
char		*ft_litoa(long int n);
char		*ft_llitoa(long long int n);
char		*ft_ucitoa(unsigned char n);
char		*ft_usitoa(unsigned short n);
char		*ft_uitoa(unsigned int n);
char		*ft_ulitoa(unsigned long int n);
char		*ft_ullitoa(unsigned long long int n);

#endif