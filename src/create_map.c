/*
** EPITECH PROJECT, 2018
** .
** File description:
** .
*/

#include <fcntl.h>
#include <stdlib.h>
#include "navy.h"
#include "tools.h"

void	fill_map_dot(char *map)
{
	for (int i = 0; i != 8; i++) {
		map[i] = '.';
	}
	map[8] = '\0';
}

int	fill_pos(char *str, char **pos)
{
	int	fd = 0;
	char	buf[32];
	int	j = 0;
	int	k = 0;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (84);
	if (read(fd, buf, 31) == -1)
		return (84);
	buf[31] = '\0';
	for (int i = 0; buf[i] != '\0'; i++) {
		if (buf[i] == '\n') {
			i = i + 1;
			k = 0;
			j = j + 1;
		}
		pos[j][k++] = buf[i];
	}
	return (0);
}

int	fill_map_player(map_t *map, char *str, int player)
{
	char	**pos = malloc(sizeof(char *) * 4);

	if (pos == NULL)
		return (84);
	for (int i = 0; i != 4; i++) {
		pos[i] = malloc(sizeof(char) * 9);
		if (pos[i] == NULL)
			return (84);
		pos[i][7] = '\0';
	}
	if (fill_pos(str, pos) == 84)
		return (84);
	if (fill_map_with_pos(map, pos, player) == 84)
		return (84);
	return (0);
}

int	init_map(map_t *map, char *str, int player)
{
	map->win = 0;
	map->loose = 0;
	map->map1 = malloc(sizeof(char *) * 8);
	map->map2 = malloc(sizeof(char *) * 8);
	if (map->map1 == NULL || map->map2 == NULL)
		return (84);
	for (int i = 0; i != 8; i++) {
		map->map1[i] = malloc(sizeof(char) * 9);
		map->map2[i] = malloc(sizeof(char) * 9);
		if (map->map1[i] == NULL || map->map2[i] == NULL)
			return (84);
		fill_map_dot(map->map1[i]);
		fill_map_dot(map->map2[i]);
	}
	if (fill_map_player(map, str, player) == 84) {
		my_puterr("Wrong map\n");
		return (84);
	}
	return (0);
}
