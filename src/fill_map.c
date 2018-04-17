/*
** EPITECH PROJECT, 2018
** .
** File description:
** .
*/

#include "navy.h"
#include "tools.h"

int	fill_vertical(char **map, char *pos, int nb)
{
	int	i = 0;
	char	carac = 'A';
	char	fill = '.';

	while (carac != pos[0]) {
		carac = carac + 1;
		i = i + 1;
	}
	map[pos[1] - '0' - 1][i] = nb + '0';
	map[pos[4] - '0' - 1][i] = nb + '0';
	for (int k = 0; k != 8; k++) {
		if (map[k][i] == nb + '0')
			fill = (fill == '.' ? nb + '0' : '.');
		if (map[k][i] == '.')
			map[k][i] = fill;
	}
	return (0);
}

int	fill_horizontal(char **map, char *pos, int nb)
{
	int	i = 0;
	char	carac = '1';
	char	fill = '.';

	while (carac != pos[1]) {
		carac = carac + 1;
		i = i + 1;
	}
	map[i][pos[0] - 'A'] = nb + '0';
	map[i][pos[3] - 'A'] = nb + '0';
	for (int k = 0; k != 8; k++) {
		if (map[i][k] == nb + '0')
			fill = (fill == '.' ? nb + '0' : '.');
		if (map[i][k] == '.')
			map[i][k] = fill;
	}
	return (0);
}

int	fill_map_pos(char **map, char *pos, int nb)
{
	if (pos[0] == pos[3]) {
		if (fill_vertical(map, pos, nb) == 84)
			return (84);
	} else
		if (fill_horizontal(map, pos, nb) == 84)
			return (84);
	return (0);
}

int	fill_map_with_pos(map_t *map, char **pos, int player)
{
	int	nb = 2;

	if (map == NULL || pos == NULL || (player != 0 && player != 1))
		return (84);
	for (int i = 0; i != 4; i++) {
		if (player == PLAYER1) {
			if (fill_map_pos(map->map1, pos[i] + 2, nb) == 84)
				return (84);
		} else if (player == PLAYER2)
			if (fill_map_pos(map->map2, pos[i] + 2, nb) == 84)
				return (84);
		nb = nb + 1;
	}
	return (0);
}
