/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sberbagu <sberbagu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/05 14:47:33 by sberbagu     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/22 16:25:33 by sberbagu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"
#include <sys/uio.h>
#include <string.h>

char			*ft_substr(char *s, int start, int len)
{
	int		i;
	char	*str;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	if (start > i)
	{
		if (!(str = (char *)malloc(sizeof(char) * 2)))
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	if (i < len)
	{
		if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
			return (NULL);
	}
	else if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (s[start] && len > i)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}

int				ft_gnlnext(char **line, char **stock, char *s2)
{
	int		i;
	char	*tmp;

	i = 0;
	while (s2[i] && s2[i] != '\n')
		i++;
	*line = ft_substr(s2, 0, i);
	tmp = ft_substr(s2, i + 1, BUFFER_SIZE);
	if (*stock)
		free(*stock);
	*stock = ft_strdup(tmp);
	free(tmp);
	free(s2);
	return (1);
}

void			gnl_end(char **line, char *temp, int i)
{
	if (i < 0)
		*line = ft_strdup("");
	else
		*line = ft_strdup(temp);
	free(temp);
}

int				get_next_line(int fd, char **line)
{
	int			i;
	static char	*stock;
	char		buffer[BUFFER_SIZE + 1];
	char		*temp;

	i = 1;
	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, buffer, 0) < 0 || !line)
		return (-1);
	stock == NULL ? stock = ft_strdup("") : NULL;
	temp = ft_strdup(stock);
	while (!ft_strchr(temp, '\n')
		&& (i = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[i] = '\0';
		temp = ft_strjoin(temp, buffer);
	}
	if (!ft_strchr(temp, '\n'))
	{
		gnl_end(line, temp, i);
		free(stock);
		stock = NULL;
		return (0);
	}
	return (ft_gnlnext(line, &stock, temp));
}
