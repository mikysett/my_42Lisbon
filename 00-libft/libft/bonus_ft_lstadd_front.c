/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_ft_lstadd_front.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 15:47:09 by msessa            #+#    #+#             */
/*   Updated: 2021/01/18 16:08:41 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (*lst)
		new->next = *lst;
	else
		new->next = 0;
	*lst = new;
}