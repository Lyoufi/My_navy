/*
** EPITECH PROJECT, 2018
** .
** File description:
** .
*/

#include "navy.h"
#include "tools.h"

int	main(int ac, char **av)
{
	if (ac == 1 || ac > 3) {
		my_puterr(ERROR_ARG);
		return (0);
	}
	if (check_help(ac, av) == 1)
		return (0);
	if (ac == 2) {
		if (player1() == 84)
			return (84);
	} else if (ac  == 3)
		if (player2(av[1], av[2]) == 84)
			return (84);
	return (0);
}
