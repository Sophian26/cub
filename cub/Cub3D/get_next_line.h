/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sberbagu <sberbagu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/21 18:21:04 by sberbagu     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/18 15:13:47 by sberbagu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 32
# include <unistd.h>
# include <stdlib.h>
# include <string.h>


char				*ft_strjoin(char *s1, char *s2);
int					ft_strlen(char *s);
char				*ft_strchr(char *s, int c);
int					get_next_line(int fd, char **line);
char				*ft_strdup(char *src);
char				*ft_substr(char *s, int start, int len);

#endif
