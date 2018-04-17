/*
** EPITECH PROJECT, 2018
** .
** File description:
** .
*/

char	*convert_to_binary_letter(char *input)
{
	char	*binary;

	input[0] == 'A' ? binary = "0001" : 0;
	input[0] == 'B' ? binary = "0010" : 0;
	input[0] == 'C' ? binary = "0011" : 0;
	input[0] == 'D' ? binary = "0100" : 0;
	input[0] == 'E' ? binary = "0101" : 0;
	input[0] == 'F' ? binary = "0110" : 0;
	input[0] == 'G' ? binary = "0111" : 0;
	input[0] == 'H' ? binary = "1000" : 0;
	return (binary);
}

char	*convert_to_binary_number(char *input)
{
	char	*binary;

	input[1] == '1' ? binary = "0001" : 0;
	input[1] == '2' ? binary = "0010" : 0;
	input[1] == '3' ? binary = "0011" : 0;
	input[1] == '4' ? binary = "0100" : 0;
	input[1] == '5' ? binary = "0101" : 0;
	input[1] == '6' ? binary = "0110" : 0;
	input[1] == '7' ? binary = "0111" : 0;
	input[1] == '8' ? binary = "1000" : 0;
	return (binary);
}
