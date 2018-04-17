/*
** EPITECH PROJECT, 2018
** .
** File description:
** .
*/

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

int	my_strlen(char *str)
{
	int	i = 0;

	while (str != NULL && str[i] != '\0')
		i = i + 1;
	return (i);
}

char	*my_strcat(char *old, char *buf)
{
	char	*new;
	int	i = 0;

	new = malloc(sizeof(char) * (my_strlen(old) + my_strlen(buf) + 1));
	if (new == NULL)
		return (NULL);
	while (old != NULL && old[i] != '\0') {
		new[i] = old[i];
		i = i + 1;
	}
	for (int j = 0; buf != NULL && buf[j] != '\0'; j++) {
		new[i] = buf[j];
		i = i + 1;
	}
	free(old);
	new[i] = '\0';
	return (new);
}

char	*my_new_static_dup(char *str, int i)
{
	char	*new = malloc(sizeof(char) * my_strlen(str + i) + 1);
	int	j = 0;

	if (str == NULL || new == NULL)
		return (NULL);
	while (str[i + j] != '\0') {
		new[j] = str[j + i];
		j = j + 1;
	}
	new[j] = '\0';
	free(str);
	return (new);
}

char	verif_line(char **str, char **line)
{
	int	i = 0;

	if (*str == NULL || my_strlen(*str) == 1 || my_strlen(*str) == 0)
		return (84);
	while (*str != NULL && (*str)[i] != '\0' && (*str)[i] != '\n')
		i = i + 1;
	if ((*str)[i] == '\0')
		return (0);
	*line = malloc(sizeof(char) * (i + 1));
	if (*line == NULL)
		return (84);
	i = 0;
	while (*str != NULL && (*str)[i] != '\0' && (*str)[i] != '\n') {
		(*line)[i] = (*str)[i];
		i = i + 1;
	}
	(*line)[i] = '\0';
	i = i + 1;
	*str = my_new_static_dup(*str, i);
	return (*str == NULL ? 84 : 1);
}

char	*get_next_line(const int fd)
{
	static char	*str = NULL;
	char		*line = NULL;
	char		buf[READ_SIZE + 1];
	int		nb = read(fd, buf, READ_SIZE);

	if (fd < 0)
		return (NULL);
	while (nb > 0) {
		buf[nb] = '\0';
		str = my_strcat(str, buf);
		if (str == NULL)
			return (NULL);
		nb = verif_line(&str, &line);
		if (nb == 1 || nb == 84)
			return (nb == 1 ? line : NULL);
		nb = read(fd, buf, READ_SIZE);
	}
	nb = verif_line(&str, &line);
	return (nb == 1 ? line : nb == 84 ? NULL : str);
}
