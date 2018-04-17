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

int	player2_bis(map_t *map, char *str)
{
	my_putstr("my_pid:   ");
	my_put_nbr(getpid());
	my_putstr("\nsuccessfully connected\n\n");
	if (game_player2(map, my_getnbr(str)) == 84)
		return (84);
	return (0);
}

int	player2(char *str, char *str1)
{
	map_t	*map = malloc(sizeof(map_t));

	if (map == NULL)
		return (84);
	if (init_map(map, str1, PLAYER2) == 84)
		return (84);
	global = 0;
	str1 = str1;
	while (global == 0) {
		if (kill(my_getnbr(str), SIGUSR1) == -1) {
			my_putstr("Bad token\n");
			return (84);
		} else {
			global = global + 1;
		}
	}
	if (player2_bis(map, str) == 84)
		return (84);
	return (0);
}
