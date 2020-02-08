/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 21:49:52 by mbriffau          #+#    #+#             */
/*   Updated: 2017/09/30 14:14:44 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlen_c(char const *str, char cmp)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == cmp)
			return (i);
		i++;
	}
	return (0);
}
