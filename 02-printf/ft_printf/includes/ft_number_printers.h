/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number_printers.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 20:08:41 by msessa            #+#    #+#             */
/*   Updated: 2021/03/04 13:56:36 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NUMBER_PRINTERS_H
# define FT_NUMBER_PRINTERS_H
# include "ft_printf.h"

char		*ft_llitoa_len(long long int n, int len, t_arg *arg);
char		*ft_ullitoa_len(unsigned long long int n, int len);
char		*ft_set_hex(unsigned long long int n, int len,
	char c_base, bool alt);
int			ft_set_digits_hex(unsigned long long int n);
void		ft_save_nb_hex(char *res, unsigned long long int n,
	int digits, char c_base);

#endif
