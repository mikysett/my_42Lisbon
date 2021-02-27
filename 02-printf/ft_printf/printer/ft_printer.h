/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 20:08:41 by msessa            #+#    #+#             */
/*   Updated: 2021/02/26 16:20:03 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTER_H
# define FT_PRINTER_H
# include "../ft_printf.h"

bool		ft_print_padding(size_t len, bool is_zero);
char		*ft_get_padding(int len, char c);
int			ft_print_arg(t_str_part *sp, t_str_arg str_arg);
char		*ft_set_hex(unsigned long long int n, int len, char c_base, bool alt);

#endif