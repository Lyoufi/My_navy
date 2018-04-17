/*
** EPITECH PROJECT, 2017
** getnbr
** File description:
** .
*/

void	check_neg(char const *str, int *nb, char *binary)
{
	if (str[0] == '-') {
		*nb = *nb * -1;
		*binary = 1;
	}
}

int	take_nbr(char const *str, int nb)
{
	long	tmp = 1;
	long	nb_tmp = 0;
	char	binary = 0;

	for (int i = 1; str[i] >= '0' && str[i] <= '9'; i++)
		tmp = tmp * 10;
	tmp = tmp / 10;
	check_neg(str, &nb, &binary);
	for (int i = 1; str[i] >= '0' && str[i] <= '9'; i++) {
		nb_tmp = tmp * (str[i] - '0') + nb;
		if ((((((nb_tmp > 2147483648 && binary == 1) ||
			(nb_tmp > 2147483647 && binary == 0)))))) {
			return (0);
		}
		nb = tmp * (str[i] - '0') + nb;
		tmp = tmp / 10;
	}
	check_neg(str, &nb, &binary);
	return (nb);
}

int	my_getnbr(char const *str)
{
	int	nb = 0;

	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			nb = take_nbr(str + i - 1, nb);
				break ;
		}
	}
	return (nb);
}
