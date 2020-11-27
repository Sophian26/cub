#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "cub3d.h"

t_file      *ft_initfile()
{
    t_file *file;
    if (!(file = malloc(sizeof(t_file))))
		return (NULL);
    file->mapsize = 0;
    file->playerx = 0;
    file->playery = 0;
    file->rotation = 0;
    file->resolution = NULL;
    file->northt = NULL;
    file->southt = NULL;
    file->eastt = NULL;
    file->westt = NULL;
    file->sprite = NULL;
    file->floor = NULL;
    file->sky = NULL;
    return file;
}

int        ft_raygen(t_file *file)
{
    mlx_put_image_to_window(file->mlx, file->window, file->image, 0, 0);
    return (1);
}

void        ft_usemlx(t_file *file)
{
    mlx_new_window(file->mlx, 1000, 1000, "Cube4D");
    file->image = mlx_new_image(file->mlx, 1000, 1000);
    file->window = mlx_loop_hook(file->mlx, ft_raygen, (void *)file);
    mlx_loop(file->mlx);
}

char 		*ft_parsing(int fd)
{
    char *s;
    char *line;
    t_file *file;
    file = ft_initfile();
    while (get_next_line(fd, &line) > 0)
        file->map = ft_strjoin(file->map, line);
    file->map = ft_strjoin(file->map, line);
    file->mapsize = ft_strlen(line);
    file->playerx = 2;
    file->playery = 3;
    file->rotation = 0;
    file->mlx = mlx_init();
    ft_usemlx(file);
    return (file->map);
}

int main()
{
    int fd;
    char *map;
    fd = open("./map", 'r');
    map = ft_parsing(fd);
    printf("%s", map);
}