/*
** EPITECH PROJECT, 2017
** .
** File description:
** .
*/

#include <unistd.h>
#include <stdlib.h>

int	my_strlen(char const *);

char	*my_strdup(char const *stc)
{
	char	*str = NULL;
	int	size = my_strlen(src);

	str = malloc(sizeof(char) * (size + 1));
	if (str == NULL || src == NULL)
		return (NULL);
        for (int i = 0; src[i] != '\0'; i++) {
		str[i] = src[i];
	}
	str[size] = '\0';
	return (str);
}
