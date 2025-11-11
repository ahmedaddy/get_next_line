#ifndef NEXT_LINE_H
#define NEXT_LINE_H
# include <io.h>
# include <stdlib.h>
# include <stddef.h>
# include <fcntl.h>

#ifndef BUFFER_SIZE_h
#define BUFFER_SIZE 10
#endif

char    *get_next_line(int fd);
size_t  ft_strlen(const char *theString);
void    *ft_calloc(size_t elementCount, size_t elementSize);
void    ft_bzero(void *s, size_t n);
char    *ft_strchr(const char *string, int searchedChar);
char    *ft_strjoin(char const *s1, char const *s2);

#endif
