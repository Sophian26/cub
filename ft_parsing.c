#include <stdlib.h>
#include "cub3d.h"

typedef struct          s_parsmap
{
    char* resolution;
    char* north;
    char* south;
    char* east;
    char* west;
    char* sprite;
    char* ground;
    char* sky;
    char* map;
}                       t_parsmap;

void        ft_parsall(int fd, char **line, t_file *parsmap)
{
    int i;
    int j;
    char *s;
    int map;
    int test;
    int error;

    error = 0;
    map = 0;
    while ((map != 1) && ((s = get_next_line(fd, line)) != 0 || s == -1))
    {
        i = 0;
        test = 0;
        while (test != 1 && s[i] != '\0')
        {
            if (s[i] == 'R')
            {
                if (parsmap->resolution[0] == '\0')
                {
                    while (s[i + 2] != '\0' || (ft_isdigit(s[i + 2]) != 0))
                    {
                        parsmap->resolution[i] = s[i + 2];
                        i++;
                    }
                }
                test = 1;
            }
            if (s[i] == 'N' && s[i + 1] == 'O')
            {
                if (parsmap->northt == '\0')
                {
                    while (s[i + 2] != '\0')
                    {
                        parsmap->northt[i] = s[i + 2];
                        i++;
                    }
                }
                test = 1;
            }
            if (s[i] == 'S' && s[i + 1] == 'O')
            {
                if (parsmap->southt == '\0')
                {
                    while (s[i + 2] != '\0')
                    {
                        parsmap->southt[i] = s[i + 2];
                        i++;
                    }
                }
                test = 1;
            }
            if (s[i] == 'E' && s[i + 1] == 'A')
            {
                if (parsmap->eastt == '\0')
                {
                    while (s[i + 2] != '\0')
                    {
                        parsmap->eastt[i] = s[i + 2];
                        i++;
                    }
                }
                test = 1;
            }
            if (s[i] == 'W' && s[i + 1] == 'E')
            {
                if (parsmap->westt == '\0')
                {
                    while (s[i + 2] != '\0')
                    {
                        parsmap->westt[i] = s[i + 2];
                        i++;
                    }
                }
                test = 1;
            }
            if (s[i] == 'S' && s[i + 1] == ' ')
            {
                if (parsmap->sprite == '\0')
                {
                    while (s[i + 2] != '\0')
                    {
                        parsmap->sprite[i] = s[i + 2];
                        i++;
                    }
                }
                test = 1;
            }
            if (s[i] == 'F' && s[i + 1] == ' ')
            {
                if (parsmap->ground == '\0')
                {
                    while (s[i + 2] != '\0')
                    {
                        parsmap->ground[i] = s[i + 2];
                        i++;
                    }
                }
                test = 1;
            }
            if (s[i] == 'C' && s[i + 1] == ' ')
            {
                if (parsmap->sky == '\0')
                {
                    while (s[i + 2] != '\0')
                    {
                        parsmap->sky[i] = s[i + 2];
                        i++;
                    }
                }
                test = 1;
            }
            if(s[i] == '1')
            {
                j = 0;
                while (j < i)
                {
                    parsmap->map[j] = ' ';
                    j++;
                }
                while (s[i] == '1' || s[i] == ' ')
                {
                    if (s[i] == '1')
                    {
                        parsmap->map[j] = '1';
                        j++;
                    }
                    i++;
                }
                if (s[i] == '\n')
                {
                    parsmap->map[j] = 'l';
                    j++;
                    i++;
                     while ((s = get_next_line(fd, line)) != 0 || s == -1)
                    {
                        while (s[i] == ' ')
                        {
                            parsmap->map[j] = ' ';
                            j++;
                            i++;
                        }
                        if (s[i] != '1')
                            error = 1;
                        else
                        {
                            parsmap->map[j] = '1';
                            j++;
                            i++;
                        }
                        while (s[i] == '0' || s[i] == '2' || s[i] == 'N' || s[i] == 'S' ||s[i] == 'E' ||s[i] == 'W' || s[i] == ' ')
                        {
                            if (s[i] != ' ')
                            {
                                parsmap->map[j] = s[i];
                                j++;
                            }
                            i++;
                        }
                        if (s[i] == '1' && s[i + 1] == '\0')
                        {
                            parsmap->map[j] = s[i];
                            parsmap->map[j + 1] = 'l';
                            j += 2;
                        }
                        else
                            error = 1;
                    }
                    map = 1;
                }
                else 
                    error = 1;
                
            }
            i++;
        }
    }
}