/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 16:33:06 by msessa            #+#    #+#             */
/*   Updated: 2021/02/14 11:21:34 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_del_return(t_list *lst, void (*del)(void *))
{
	t_list	*next;

	while (lst)
	{
		next = lst->next;
		del(lst->content);
		free(lst);
		lst = next;
	}
	return (0);
}

t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
	void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_prev;
	t_list	*new_curr;

	new_lst = 0;
	while (lst)
	{
		if (!(new_curr = ft_lstnew(f(lst->content))))
			return (ft_del_return(new_lst, del));
		if (!new_lst)
		{
			new_lst = new_curr;
			new_prev = new_curr;
		}
		else
			new_prev->next = new_curr;
		new_prev = new_curr;
		lst = lst->next;
	}
	return (new_lst);
}