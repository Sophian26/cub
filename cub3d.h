# include "./mlx/mlx.h"
# include "get_next_line.h"

typedef struct s_file
{
    void *mlx;
    char *map;
    int mapsize;
    void *window;
    void *image;
    int playerx;
    int playery;
    int rotation;
    char *resolution;
    char *northt;
    char *southt;
    char *eastt;
    char *westt;
    char *sprite;
    char *ground;   
    char *sky;
}               t_file;

int		    ft_isdigit(int c);
void        ft_parsall(int fd, char *line, t_file *parsmap);