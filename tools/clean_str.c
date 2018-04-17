/*
** EPITECH PROJECT, 2018
** .
** File description:
** .
*/

#include <unistd.h>
#include "tools.h"

int	check_space(char *str, int i)
{
	int	j = i;

	if (str == NULL)
		return (84);
	while (str[j] == ' ') {
		j = j + 1;
	}
	if (i == j)
		return (0);
	while (str[j] != '\0') {
		str[i] = str[j];
		str[j] = ' ';
		i = i + 1;
		j = j + 1;
	}
	return (0);
}

int	remove_space(char *str)
{
	if (str == NULL)
		return (84);
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == ' ')
			if (check_space(str, i + 1) == 84)
				return (84);
	}
	return (0);
}

int	remove_last_space(char *str)
{
	if (str == NULL)
		return (84);
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == ' ' && str[i + 1] == ' '){
			str[i] = '\0';
			break;
		} else if (str[i] == ' ' && str[i + 1] == '\0') {
			str[i] = '\0';
			break;
		}
	}
	return (0);
}

int delete_back_t_ascii(char *str)
{
	if (str == NULL)
		return (84);
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == '\t')
			str[i] = ' ';
	}
	return (0);
}

int	my_clean_str(char *str)
{
	int	i = 0;

	if (str == NULL)
		return (84);
	if (delete_back_t_ascii(str) == 84)
		return (84);
	while (str[i] != '\0' && (str[i] == ' '))
		i = i + 1;
	str = str + i;
	i = 0;
	if (remove_space(str) == 84)
		return (84);
	if (remove_last_space(str) == 84)
		return (84);
	return (0);
}
