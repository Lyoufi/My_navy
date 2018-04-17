/*
** EPITECH PROJECT, 2018
** .
** File description:
** .
*/

#include <fcntl.h>
#include "navy.h"
#include "tools.h"

int	do_help(void)
{
	int	fd;
	char	buff[192];

	fd = open("HELP", O_RDONLY);
	if (fd == -1) {
		my_puterr("ERROR_OPEN");
		return (84);
	}
	if (read(fd, buff, 191) == -1)
		return (84);
	buff[191] = '\0';
	my_putstr(buff);
	return (1);
}

int	check_help(int ac, char **av)
{
	for (int i = 0; i != ac; i++) {
		if (my_strcmp(av[i], "-h") == 0) {
			if (do_help() == 84)
				return (84);
			return (1);
		}
	}
	return (0);
}
