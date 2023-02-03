/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwankim <hwankim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:00:41 by hwankim           #+#    #+#             */
/*   Updated: 2023/01/30 13:00:13 by hwankim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	4096
# endif

# include <unistd.h>
# include "so_long.h"

char			*get_next_line(int fd);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s1);
size_t			ft_strlen(const char *str);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);

#endif
