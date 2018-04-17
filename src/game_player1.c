/*
** EPITECH PROJECT, 2018
** .
** File description:
** .
*/

#include <signal.h>
#include <unistd.h>
#include "get_next_line.h"
#include "navy.h"
#include "tools.h"

int	game_player1(map_t *map, int pid)
{
	char	*input;

	while (map->win != 14 && map->loose != 14) {
		print_map(map, PLAYER1);
		attack(map, pid, PLAYER1);
		input = defend();
		hit_or_not_defence(map, input, pid, PLAYER1);
	}
	print_map(map, PLAYER1);
	map->win == 14 ? my_putstr("I won") : my_putstr("Enemy won");
	return (0);
}
