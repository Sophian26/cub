#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

char 		*ft_parsing(int fd)
{
    char *s;
    char *line;
    char *map = NULL;
    dprintf(1, "tg fdp4\n");
    while (get_next_line(fd, &line) > 0)
    {
        dprintf(1, "%s\ntg fdp2\n", line);
        map = ft_strjoin(map, line);
        dprintf(1, "tg fdp3\n");
    }
    map = ft_strjoin(map, line);
    return (map);
}

int main()
{
    dprintf(1, "tg fdp1\n");
    int fd;
    char *map;
    fd = open("./map", 'r');
    map = ft_parsing(fd);
    printf("%s", map);
}