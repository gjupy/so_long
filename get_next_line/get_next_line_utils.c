/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjupy <gjupy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 20:12:36 by cboubour          #+#    #+#             */
/*   Updated: 2022/06/13 21:16:24 by gjupy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin2(char **s1, char const *s2)
{
	char	*conc;
	size_t	len;

	if (s2 == NULL)
		return (NULL);
	if (!*s1)
		return (ft_strdup(s2));
	len = ft_strlen((char *)*s1) + ft_strlen((char *)s2) + 1;
	conc = (char *)malloc(sizeof(char) * len);
	if (!conc)
		return (NULL);
	ft_memcpy(conc, (char *)*s1, ft_strlen((char *)*s1));
	ft_memcpy(conc + ft_strlen((char *)*s1), s2, ft_strlen((char *)s2));
	conc[len - 1] = '\0';
	free(*s1);
	return (conc);
}
