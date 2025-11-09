#include "get_next_line.h"

char *ft_strjoin(char const *s1, char const *s2)
{
  char *nstr;
  size_t s1l;
  size_t s2l;
  size_t i;

  if (!s1 || !s2)
    return (NULL);
  s1l = ft_strlen(s1);
  s2l = ft_strlen(s2);
  nstr = (char *)malloc(s1l + s2l + 1);
  if (!nstr)
    return (NULL);
  i = 0;
  while (i < s1l)
  {
    nstr[i] = s1[i];
    i++;
  }
  while (i < s1l + s2l)
  {
    nstr[i] = s2[i - s1l];
    i++;
  }
  nstr[i] = '\0';
  return (nstr);
}
char *ft_strchr(const char *s, int c)
{
  while (*s)
  {
    if (*s == ((char)c))
    {
      return ((char *)s);
    }
    s++;
  }
  if (((char)c) == '\0')
    return ((char *)s);
  return (0);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*p;

	p = s;
	i = 0;
	while (i < n)
	{
		p[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	p = malloc(nmemb * size);
	if (!p)
		return (NULL);
	ft_bzero(p, nmemb * size);
	return (p);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}
