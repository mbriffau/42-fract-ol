/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 22:55:08 by mbriffau          #+#    #+#             */
/*   Updated: 2017/09/30 14:13:24 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strcat(char *s1, char *s2)
{
	size_t		start;
	size_t		len;
	size_t		i;

	i = 0;
	len = ft_strlen(s2);
	start = ft_strlen(s1);
	while (i <= len)
	{
		s1[start + i] = s2[i];
		i++;
	}
	return (s1);
}
