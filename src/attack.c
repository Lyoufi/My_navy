/*
** EPITECH PROJECT, 2018
** .
** File description:
** .
*/

#include "get_next_line.h"
#include "navy.h"
#include "tools.h"

int	check_input(char *input)
{
	if (input == NULL)
		return (84);
	my_clean_str(input);
	if (my_strlen(input) != 2)
		return (84);
	if (input[0] < 'A' || input[0] > 'H')
		return (84);
	if (input[1] < '1' || input[1] > '8')
		return (84);
	return (0);
}

int	send_signal(char *input, int pid)
{
	char	*binary_letter;
	char	*binary_number;

	binary_letter = convert_to_binary_letter(input);
	binary_number = convert_to_binary_number(input);
	for (int i = 0; i != 4; i++) {
		if (binary_letter[i] == '0')
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(1000);
	}
	for (int i = 0; i != 4; i++) {
		if (binary_number[i] == '0')
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(1000);
	}
	return (0);
}

void	attack_next(char *input, map_t *map, int player)
{
	int	verif;
	struct sigaction	action1;
	struct sigaction	action2;

	init_sigaction_sig(&action1, &action2);
	my_putstr(input);
	verif = global;
	while (verif == global) {
		sigaction(SIGUSR1, &action1, NULL);
		sigaction(SIGUSR2, &action2, NULL);
	}
	verif + 1 == global ? missed_attack(map, input, player) :
		hit_attack(map, input, player);
}

int	attack(map_t *map, int pid, int player)
{
	char	*input;

	my_putstr("attack: ");
	input = get_next_line(0);
	if (check_input(input) == 84) {
		my_putstr_back("wrong position");
		attack(map, pid, player);
		return (0);
	}
	send_signal(input, pid);
	attack_next(input, map, player);
	return (0);
}
