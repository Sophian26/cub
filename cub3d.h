# include "./minilibx_opengl_20191021/mlx.h"


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
    char *floor;
    char *sky;
}               t_file;