#include <unistd.h>
#include <stdio.h>
#include <strings.h>
#include <fcntl.h>
#include <stdlib.h>

#define BUFFER_SIZE 10

char    *ft_strjoin(char const *s1, char const *s2)
{
    char        *s;
    size_t        i;
    size_t        j;

    if (!s1 && !s2)
        return (NULL);
    s = malloc((strlen(s1)
                   + strlen(s2) + 1) * sizeof(char));
    if (!s)
        return (NULL);
    i = 0;
    j = 0;
    if (strlen(s1) > 0)
    {
        while (i < strlen(s1) && s1[i] != '\0')
        {
            s[i] = s1[i];
            i++;
        }
    }
    if (strlen(s2) > 0)
        while (j < strlen(s2) && s2[j] != '\0')
            s[i++] = s2[j++];
    s[i] = '\0';
    return (s);
} 

void    go_next_line(char *buf, char **s)
{
    char    *n;

    n = strchr(buf, '\n');
    *n++ = '\0';
    *s = ft_strjoin(*s, buf);
    *s = ft_strjoin(*s, "\n");
    n++;
    strncpy(buf, n, strlen(n) + 1);
}

char    *get_next_line(int fd)
{
    static char    buf[BUFFER_SIZE + 1];
    char    *s;
    int        last;

    if (fd == -1)
      return (NULL);
    if (read(fd, s, 0) == -1 || BUFFER_SIZE < 1)
        return (NULL);
    last = 1;
    s = NULL;
    while (!(strchr(buf, '\n')) && last > 0)
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
    if (strchr(buf, '\n'))
        go_next_line(buf, &s);
    return (s);
}

int    main()
{
    int   fd;
    char  *s1 = ">qwe<\n>zxc<";
//    char  *s2 = ">zxcvbnm<";
  printf("%lu", strlen(s1));
    write (fd, s1, strlen(s1));
//    write (fd, s2, strlen(s2));
//    fd = open("text.txt", O_RDONLY);
    printf ("%s", get_next_line(fd));
    close(fd);
    return 0;
}
