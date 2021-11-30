#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
    char    *s;
    int        i;
    int        j;

    if (!s1 && !s2)
        return (NULL);
    s = malloc((ft_strlen(s1)
                   + ft_strlen(s2) + 1) * sizeof(char));
    if (!s)
        return (NULL);
    i = 0;
    j = 0;
    if (ft_strlen(s1) > 0)
    {
        while (i < ft_strlen(s1) && s1[i] != '\0')
        {
            s[i] = s1[i];
            i++;
        }
    }
    if (ft_strlen(s2) > 0)
        while (j < ft_strlen(s2) && s2[j] != '\0')
            s[i++] = s2[j++];
    s[i] = '\0';
    return (s);
}

int main() {
  char *str;
  str = NULL;
  str = ft_strjoin(str,"zxc");
  str = ft_strjoin(str, "qwe");
  printf ("%s\n", str);
  return 0;
}
