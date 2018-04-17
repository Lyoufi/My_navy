/*
** EPITECH PROJECT, 2018
** .
** File description:
** .
*/

#include "navy.h"
#include "tools.h"

void	my_putstr_back_navy(char *str)
{
	for (int i = 0; str[i] != '\0'; i++) {
		my_putchar(str[i]);
		if (str[i + 1] != '\0')
			my_putchar(' ');
	}
	my_putchar('\n');
}

void	print_map(map_t *map, int player)
{
	char	carac = '1';

	my_putstr_back(MY_POSITION);
	for (int i = 0; i != 8; i++) {
		my_putchar(carac);
		my_putchar('|');
		player == PLAYER1 ? my_putstr_back_navy(map->map1[i]) :
			my_putstr_back_navy(map->map2[i]);
		carac = carac + 1;
	}
	carac = '1';
	my_putstr_back(ENEMY_POSITION);
	for (int i = 0; i != 8; i++) {
		my_putchar(carac);
		my_putchar('|');
		player == PLAYER2 ? my_putstr_back_navy(map->map1[i]) :
			my_putstr_back_navy(map->map2[i]);
		carac = carac + 1;
	}
	my_putchar('\n');
}
