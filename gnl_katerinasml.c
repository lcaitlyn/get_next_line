void change_buf_line(char *buf, char **line)
{
	char *n;

	n = ft_strchr(buf, '\n');
	*n = '\0';
	*line = ft_strjoin(*line, buf);
	*line = ft_strjoin(*line, "\n");
	n++;
	ft_strncpy(buf, n, ft_strlen(n) + 1);
}

char *get_next_line(int fd)
{
	static char buf[BUFFER_SIZE + 1];
	char  *line;
	long  count;

	if (read(fd, 0, 0) == -1)
		return (0);
	line = 0;
	count = 1;
	while ((ft_strchr(buf, '\n') == 0) && count > 0)
	{
		line = ft_strjoin(line, buf);
		count = read(fd, buf, BUFFER_SIZE);
		buf[count] = '\0';
	}
	if (count < 0 || (count == 0 && line[0] == '\0'))
	{
		free (line);
		return (0);
	}
	if (ft_strchr(buf, '\n'))
		change_buf_line(buf, &line);
	return (line);
}
