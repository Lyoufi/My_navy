/*
** EPITECH PROJECT, 2018
** .
** File description:
** .
*/

#include <stdlib.h>
#include "navy.h"
#include "tools.h"

void	init_sigaction_sig(struct sigaction *action1, struct sigaction *action2)
{
	action1->sa_sigaction = (void *) success1;
	action1->sa_flags = SA_SIGINFO;
	sigemptyset(&action1->sa_mask);
	action2->sa_sigaction = (void *) success2;
	action2->sa_flags = SA_SIGINFO;
	sigemptyset(&action2->sa_mask);
}

char	*defend(void)
{
	struct sigaction	action1;
	struct sigaction	action2;
	char		*str = malloc(sizeof(char) * 9);
	int		verif;

	if (str == NULL)
		return (NULL);
	str[8] = '\0';
	global = 0;
	init_sigaction_sig(&action1, &action2);
	for (int i = 0; i != 8; i++) {
		verif = global;
		while (global == verif) {
			sigaction(SIGUSR1, &action1, NULL);
			sigaction(SIGUSR2, &action2, NULL);
		}
		check_signal(str, i, verif);
	}
	convert_bin_ascii(str);
	return (str);
}

void	hit_player1(map_t *map, char *str, int pid)
{
	if (map->map1[str[1] - '1'][str[0] - '1'] != '.' &&
	    map->map1[str[1] - '1'][str[0] - '1'] != 'x' &&
	    map->map1[str[1] - '1'][str[0] - '1'] != 'o') {
		my_putstr(": hit\n");
		(map->map1[str[1] - '1'][str[0] - '1'] = 'x');
		usleep(10000);
		kill(pid, SIGUSR2);
		map->loose = map->loose + 1;
	} else {
		my_putstr_back(": missed\n");
		(map->map1[str[1] - '1'][str[0] - '1'] = 'o');
		usleep(10000);
		kill(pid, SIGUSR1);
	}
}

void	hit_player2(map_t *map, char *str, int pid)
{
	if (map->map2[str[1] - '1'][str[0] - '1'] != '.' &&
	    map->map2[str[1] - '1'][str[0] - '1'] != 'x' &&
	    map->map2[str[1] - '1'][str[0] - '1'] != 'o') {
		my_putstr_back(": hit\n");
		(map->map2[str[1] - '1'][str[0] - '1'] = 'x');
		usleep(10000);
		kill(pid, SIGUSR2);
		map->loose = map->loose + 1;
	} else {
		my_putstr_back(": missed\n");
		(map->map2[str[1] - '1'][str[0] - '1'] = 'o');
		usleep(10000);
		kill(pid, SIGUSR1);
	}
}

int	hit_or_not_defence(map_t *map, char *str, int pid, int player)
{
	my_putchar(str[0] - '0' + 'A' - 1);
	my_putchar(str[1]);
	if (player == PLAYER1) {
		hit_player1(map, str, pid);
	} else {
		hit_player2(map, str, pid);
	}
	return (0);
}
