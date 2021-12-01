#include <stdio.h>
#include <stdlib.h>

char    *ft_strdup(char *src)
{
    char    *str;
    char    *p;

    str = (char *)malloc(sizeof(*src) * (ft_strlen(src) + 1));
    if (!str)
        return (NULL);
    p = str;
    while (*src)
    {
        *str++ = *src++;
    }
    *str = '\0';
    return (p);
}

int    ft_strlen(const char *s)
{
    int    i;

    i = 0;
    if (s == NULL)
        return (0);
    while (s[i] != '\0')
        i++;
    return (i);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
    char            *dest;
    char*    p;
    void            *tmp;

    tmp = (void *)s1;
    p = dest;
    if (s1 == NULL && s2 == NULL)
        return (NULL);
    printf ("[2*<%s> {%s}*2]\n", s1, s2);
    dest = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
    if (dest == NULL)
        return (NULL);
    while (*s1 != '\0')
        *dest++ = *s1++;
    while (*s2 != '\0')
        *dest++ = *s2++;
    *dest++ = '\0';
    free (tmp);
    return (p);
}

int main ()
{
  printf ("%s", ft_strjoin( ft_strdup(""), "qwe"));
  return 0;
}
