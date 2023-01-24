/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjupy <gjupy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 04:09:14 by cboubour          #+#    #+#             */
/*   Updated: 2022/08/19 12:48:17 by gjupy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "../includes/so_long.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

// char	*get_next_line(int fd);
char	*get_next_line_with_exiting(int fd);
char	*get_next_line_without_exiting(int fd);
char	*ft_strjoin2(char **s1, char const *s2);

#	endif
