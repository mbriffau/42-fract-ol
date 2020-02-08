/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 19:43:49 by mbriffau          #+#    #+#             */
/*   Updated: 2017/09/30 14:17:50 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

static t_list	*ft_lst_search(t_list **first, int fd)
{
	t_list		*lst;

	lst = *first;
	while (lst)
	{
		if (fd == (int)lst->content_size)
			return (lst);
		lst = lst->next;
	}
	lst = ft_lstnew("\0", 1);
	lst->content_size = fd;
	ft_lstadd(first, lst);
	return (lst);
}

int				get_next_line(const int fd, char **line)
{
	char			buff[BUFF_SIZE + 1];
	int				ret;
	static t_list	*lst;
	t_list			*first;
	t_list			*tmp;

	ret = 0;
	if (fd < 0 || line == NULL || read(fd, buff, 0) < 0)
		return (-1);
	first = lst;
	lst = ft_lst_search(&first, fd);
	while (!ft_strchr(lst->content, '\n') && (ret = read(fd, buff, BUFF_SIZE)))
		lst->content = ft_strnjoinfree(lst->content, buff, ret, 'L');
	ret = 0;
	while (((char*)lst->content)[ret] && (((char*)lst->content)[ret] != '\n'))
		ret += 1;
	*line = ft_strndup(lst->content, ret);
	(((char *)lst->content)[ret] == '\n') ? (ret += 1) : 0;
	tmp = lst->content;
	lst->content = ft_strdup(((char *)tmp) + ret);
	lst = first;
	free(tmp);
	return (ret ? 1 : 0);
}
