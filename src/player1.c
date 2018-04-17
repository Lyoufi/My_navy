/*
** EPITECH PROJECT, 2018
** .
** File description:
** .
*/

#include <stdlib.h>
#include <signal.h>
#include <navy.h>
#include "tools.h"

void	recuppid(int sig, siginfo_t *info)
{
	sig = sig;
	global = info->si_pid;
}

void	init_sigaction(struct sigaction *action)
{
	action->sa_sigaction = (void *) recuppid;
	action->sa_flags = SA_SIGINFO;
	sigemptyset(&action->sa_mask);
}

int	my_getpid(void)
{
	struct sigaction	action;

	action.sa_sigaction = (void *) recuppid;
	action.sa_flags = SA_SIGINFO;
	sigemptyset(&action.sa_mask);
	global = 0;
	while (global == 0)
		sigaction(SIGUSR1, &action, NULL);
	return (global);
}

void	first_print(void)
{
	my_putstr("my_pid:  ");
	my_put_nbr(getpid());
	my_putstr("\nwaiting for enemy connexion...\n");
}

int	player1(char *str)
{
	int	pid;
	map_t	*map = malloc(sizeof(map_t));

	if (str == NULL || map == NULL)
		return (84);
	if (init_map(map, str, PLAYER1) == 84)
		return (84);
	first_print();
	global = 0;
	while (global == 0)
		pid = my_getpid();
	my_putstr("\nenemy connected\n\n");
	game_player1(map, pid);
	return (0);
}
