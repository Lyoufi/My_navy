/*
** EPITECH PROJECT, 2018
** .
** File description:
** .
*/

#include "tools.h"

char	convert_binary_to_number(char *str)
{
	char	number;

	my_strcmp(str, "0001") == 0 ? number = '1' : 0;
	my_strcmp(str, "0010") == 0 ? number = '2' : 0;
	my_strcmp(str, "0011") == 0 ? number = '3' : 0;
	my_strcmp(str, "0100") == 0 ? number = '4' : 0;
	my_strcmp(str, "0101") == 0 ? number = '5' : 0;
	my_strcmp(str, "0110") == 0 ? number = '6' : 0;
	my_strcmp(str, "0111") == 0 ? number = '7' : 0;
	my_strcmp(str, "1000") == 0 ? number = '8' : 0;
	return (number);
}

void	convert_bin_ascii(char *str)
{
	char	carac1 = str[4];
	char	carac2 = str[4];

	my_putstr_back("waiting for enemy's attack...");
	str[4] = '\0';
	carac1 = convert_binary_to_number(str);
	str[4] = carac2;
	carac2 = convert_binary_to_number(str + 4);
	str[0] = carac1;
	str[1] = carac2;
	for (int i = 2; i != 8; i++)
		str[i] = '\0';
}
