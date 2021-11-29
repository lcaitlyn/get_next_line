/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaitlyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:28:43 by lcaitlyn          #+#    #+#             */
/*   Updated: 2021/11/20 15:28:44 by lcaitlyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	go_next_line(char *buf, char **s)
{
	char	*n;

	n = ft_strchr(buf, '\n');
	printf ("[%s]\n", n);
	*n++ = '\0';
	*s = ft_strjoin(*s, buf);
	*s = ft_strjoin(*s, "\n");
	ft_strncpy(buf, n, ft_strlen(n) + 1);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char	*s;
	int		last;

	last = 1;
	s = NULL;
	if (read(fd, s, 0) == -1 || BUFFER_SIZE < 1)
		return (NULL);
	while (!(ft_strchr(buf, '\n')) && last > 0)
	{
		s = ft_strjoin(s, buf);
		last = read(fd, buf, BUFFER_SIZE);
		buf[last] = '\0';
	}
	if (last < 0 || (last == 0 && s[0] == '\0'))
	{
		free (s);
		return (NULL);
	}
	if (ft_strchr(buf, '\n'))
		go_next_line(buf, &s);
	return (s);
}/*

int	main()
{
	int		fd;

	fd = open("../text.txt", O_RDONLY);
	printf ("%s", get_next_line(fd));
	printf ("%s", get_next_line(fd));
	printf ("%s", get_next_line(fd));
	printf ("%s", get_next_line(fd));
	printf ("%s", get_next_line(fd));
	printf ("%s", get_next_line(fd));
	printf ("%s", get_next_line(fd));
	printf ("%s", get_next_line(fd));
	close(fd);
	printf ("\n\n\n");
	fd = open("../text_empty.txt", O_RDONLY);
	printf ("%s", get_next_line(fd));
	close(fd);
	printf ("\n\n\n");
	fd = open("../text_short.txt", O_RDONLY);
	printf ("%s", get_next_line(fd));
	printf ("%s", get_next_line(fd));
	printf ("%s", get_next_line(fd));
	close(fd);
	return 0;
}*/
