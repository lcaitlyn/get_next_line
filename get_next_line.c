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

void	buf_next_line(char *buf, char **s)
{
	char	*n;

	n = ft_strchr(buf, '\n');
	*n++ = '\0';
	printf("[1XXX%p]", &s);
	*s = ft_strjoin(*s, buf);
	printf("[2XXX%p]", &s);
	*s = ft_strjoin(*s, "\n");
	printf("[3XXX%p]", &s);
	ft_strncpy(buf, n, ft_strlen(n) + 1);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char	*s;
	long	last;
	char	*tmp;

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
		buf_next_line(buf, &s);
	return (s);
}

int	main()
{
	int		fd;

/*	fd = open("../text_new_line.txt", O_RDONLY);
	printf ("%s", get_next_line(fd));
	close(fd);*/
	fd = open("../text.txt", O_RDONLY);
	printf ("%s", get_next_line(fd));
/*	printf ("%s", get_next_line(fd));
	printf ("%s", get_next_line(fd));
	printf ("%s", get_next_line(fd));
	printf ("%s", get_next_line(fd));
	printf ("%s", get_next_line(fd));
	printf ("%s", get_next_line(fd));
	printf ("%s", get_next_line(fd));*/
	close(fd);
/*	printf ("\n\n\n");
	fd = open("../text_empty.txt", O_RDONLY);
	printf ("%s", get_next_line(fd));
	close(fd);
	printf ("\n\n\n");
	fd = open("../text_short.txt", O_RDONLY);
	printf ("%s", get_next_line(fd));
	printf ("%s", get_next_line(fd));
	printf ("%s", get_next_line(fd));
	close(fd);*/
	return 0;
}
