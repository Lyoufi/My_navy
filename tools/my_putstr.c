/*
** EPITECH PROJECT, 2017
** putstr
** File description:
** .
*/

#include <unistd.h>

int	my_strlen(char const *);

void	my_putchar(char c)
{
	write(1, &c, 1);
}

int	my_putstr(char const *str)
{
	if (str == NULL)
		return (84);
	write(1, str, my_strlen(str));
	return (0);
}

int	my_putstr_back(char const *str)
{
	if (str == NULL)
		return (84);
	write(1, str, my_strlen(str));
	write(1, "\n", 1);
	return (0);
}

int	my_puterr(char const *str)
{
	if (str == NULL)
		return (84);
	write(2, str, my_strlen(str));
	return (0);
}
