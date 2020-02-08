/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 22:45:19 by mbriffau          #+#    #+#             */
/*   Updated: 2017/10/04 02:01:57 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *camion;
	t_list *sav;
	t_list *sav2;

	if (lst == NULL || f == NULL)
		return (NULL);
	sav2 = f(lst);
	if ((camion = ft_lstnew(sav2->content, sav2->content_size)))
	{
		sav = camion;
		lst = lst->next;
		while (lst)
		{
			sav2 = f(lst);
			if (!(sav->next = ft_lstnew(sav2->content, sav2->content_size)))
				return (NULL);
			sav = sav->next;
			lst = lst->next;
		}
	}
	return (camion);
}
