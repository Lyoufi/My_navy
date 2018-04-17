/*
** EPITECH PROJECT, 2018
** .
** File description:
** .
*/

#include "navy.h"
#include "tools.h"

void	missed_attack(map_t *map, char *str, int player)
{
	my_putstr_back(": missed\n");
	if (player == PLAYER1)
		map->map2[str[1] - '1'][str[0] - 'A'] = 'o';
	else
		map->map1[str[1] - '1'][str[0] - 'A'] = 'o';
}

void	hit_attack(map_t *map, char *str, int player)
{
	my_putstr_back(": hit\n");
	if (player == PLAYER1)
		map->map2[str[1] - '1'][str[0] - 'A'] = 'x';
	else
		map->map1[str[1] - '1'][str[0] - 'A'] = 'x';
	map->win = map->win + 1;
}
