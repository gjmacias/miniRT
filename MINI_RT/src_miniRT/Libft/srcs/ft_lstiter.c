/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:17:19 by ffornes-          #+#    #+#             */
/*   Updated: 2023/07/26 17:24:03 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft_defs.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*last_elem;

	if (!lst || !f)
		return ;
	last_elem = NULL;
	if (lst->next == NULL)
		f (lst->content);
	else
	{
		while (lst)
		{
			last_elem = lst;
			lst = lst->next;
			f(last_elem->content);
		}
	}
}
