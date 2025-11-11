#include "get_next_line.h"

char *read_file(int fd, char *buf)
{
}

char *get_next_line(int fd)
{
    static char *buffer;
    char *line;
    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
        return (NULL);

    buffer = read_file(fd, buffer);
}
int main(void)
{
    int fd;
    char *line;

    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
        return (1);

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    close(fd);
    return (0);
}
