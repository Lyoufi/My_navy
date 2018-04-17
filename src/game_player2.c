/*
** EPITECH PROJECT, 2018
** .
** File description:
** .
*/

#include <stdlib.h>
#include <signal.h>
#include "navy.h"
#include "tools.h"

void	check_signal(char *str, int i, int verif)
{
	if (verif + 1 == global)
		str[i] = '0';
	if (verif + 2 == global)
		str[i] = '1';
}

int	game_player2(map_t *map, int pid)
{
	char	*input;

	while (map->win != 14 && map->loose != 14) {
		print_map(map, PLAYER2);
		input = defend();
		if (input == NULL)
			return (84);
		if (hit_or_not_defence(map, input, pid, PLAYER2) == 84)
			return (84);
		if (attack(map, pid, PLAYER2) == 84)
			return (84);
	}
	print_map(map, PLAYER2);
	map->win == 14 ? my_putstr("I won") : my_putstr("Enemy won");
	return (0);
}
