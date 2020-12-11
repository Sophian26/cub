#include <stdlib.h>
#include <stdio.h>
#include "cub3d.h"


int         ft_collect(char **line, t_file *parsmap, int i, char *s)
{
    if (*line[i] == s[0] && *line[i + 1] == s[1])
        {
            if (parsmap->northt == '\0')
            {
                while (*line[i + 2] != '\0')
                {
                    parsmap->northt[i] = *line[i + 2];
                    i++;
                }
            }
            return (1);
        }
    else
        return (0);   
}

void        ft_parsall(int fd, char *line, t_file *parsmap)
{
    int i;
    int j;
    char *s;
    int map;
    int test;
    int error;

    error = 0;
    map = 0;
    while ((get_next_line(fd, &line) > 0) && error == 0)
    {
        i = 0;
        test = 0;
        while (test == 0) //line[i] != '\0')
        {
            printf("%c", line[i + 2]);
            if ((line[i] == 'R') && (line[i + 1] == ' ') && test == 0)
            {
                parsmap->resolution = ft_strjoin(parsmap->resolution, line);
                test = 1;
            }
            if (line[i] == 'N' && line[i + 1] == 'O' && test == 0)
            {
                if (parsmap->northt == '\0')
                {
                    while (line[i + 2] != '\0')
                    {
                        parsmap->northt[i] = line[i + 2];
                        i++;
                    }
                }
                test = 1;
            }
            if (line[i] == 'S' && line[i + 1] == 'O' && test == 0)
            {
                if (parsmap->southt == '\0')
                {
                    while (line[i + 2] != '\0')
                    {
                        parsmap->southt[i] = line[i + 2];
                        i++;
                    }
                }
                test = 1;
            }
            if (line[i] == 'E' && line[i + 1] == 'A' && test == 0)
            {
                if (parsmap->eastt == '\0')
                {
                    while (line[i + 2] != '\0')
                    {
                        parsmap->eastt[i] = line[i + 2];
                        i++;
                    }
                }
                test = 1;
            }
            if (line[i] == 'W' && line[i + 1] == 'E' && test == 0)
            {
                if (parsmap->westt == '\0')
                {
                    while (line[i + 2] != '\0')
                    {
                        parsmap->westt[i] = line[i + 2];
                        i++;
                    }
                }
                test = 1;
            }
            if (line[i] == 'S' && line[i + 1] == ' ' && test == 0)
            {
                if (parsmap->sprite == '\0')
                {
                    while (line[i + 2] != '\0')
                    {
                        parsmap->sprite[i] = line[i + 2];
                        i++;
                    }
                }
                test = 1;
            }
            if (line[i] == 'F' && line[i + 1] == ' ' && test == 0)
            {
                if (parsmap->ground == '\0')
                {
                    while (s[i + 2] != '\0')
                    {
                        parsmap->ground[i] = line[i + 2];
                        i++;
                    }
                }
                test = 1;
            }
            if (line[i] == 'C' && line[i + 1] == ' ' && test == 0)
            {
                if (parsmap->sky == '\0')
                {
                    while (line[i + 2] != '\0')
                    {
                        parsmap->sky[i] = s[i + 2];
                        i++;
                    }
                }
                test = 1;
            }
            if(line[i] == '1' && test == 0)
            {
                j = 0;
                while (j < i)
                {
                    parsmap->map[j] = ' ';
                    j++;
                }
                while (line[i] == '1' || line[i] == ' ')
                {
                    if (line[i] == '1')
                    {
                        parsmap->map[j] = '1';
                        j++;
                    }
                    i++;
                }
                if (line[i] == '\n')
                {
                    parsmap->map[j] = 'l';
                    j++;
                    i++;
                     while (get_next_line(fd, &line) != 0)
                    {
                        while (line[i] == ' ')
                        {
                            parsmap->map[j] = ' ';
                            j++;
                            i++;
                        }
                        if (line[i] != '1')
                            error = 1;
                        else
                        {
                            parsmap->map[j] = '1';
                            j++;
                            i++;
                        }
                        while (line[i] == '0' || line[i] == '2' || line[i] == 'N' 
                                || line[i] == 'S' || line[i] == 'E' || line[i] == 'W' || line[i] == ' ')
                        {
                            if (line[i] != ' ')
                            {
                                parsmap->map[j] = line[i];
                                j++;
                            }
                            i++;
                        }
                        if (line[i] == '1' && line[i + 1] == '\0')
                        {
                            parsmap->map[j] = line[i];
                            parsmap->map[j + 1] = 'l';
                            j += 2;
                        }
                        else
                            error = 1;
                    }
                }
                else 
                    error = 1;
            }
            i++;
        }
    }
}