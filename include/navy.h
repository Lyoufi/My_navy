/*
** EPITECH PROJECT, 2017
** include
** File description:
** include for projets
*/

#ifndef	NAVY_H
#define NAVY_H_

			/******* INCLUDE *******/

#include <signal.h>

			/******* GLOBAL *******/

int	global;

			/******* MESSAGE *******/

#define MY_POSITION	"my positions:\n |A B C D E F G H\n-+---------------"
#define ENEMY_POSITION	"\nenemy's positions:\n |A B C D E F G H\n-+---------------"
#define ERROR_ARG	"Wrong argument\nTry ./navy -h\n"
#define ERROR_OPEN	"Error with open function\n"

			/******* DEFINE *******/

#define PLAYER1	0
#define PLAYER2	1

			/******* STRUCTURE *******/

typedef struct	map_s{
	char	**map1;
	char	**map2;
	int	win;
	int	loose;
}		map_t;

			/******* INCLUDE *******/

int	check_help(int , char **);
int	player1();
int	player2(char *, char *);
int	init_map(map_t *, char *, int);
int	fill_map_with_pos(map_t *, char **, int);
int	game_player1(map_t *, int);
int	game_player2(map_t *, int);
void	print_map(map_t *, int);
void	success1(void);
void	success2(void);
void	init_sigaction(struct sigaction *);
void	convert_bin_ascii(char *);
void	init_sigaction_sig(struct sigaction *, struct sigaction *);
void	missed_attack(map_t *, char *, int);
void	hit_attack(map_t *, char *, int);
char	*defend(void);
int	hit_or_not_defence(map_t *, char *, int, int);
int	attack(map_t *, int, int );
void	check_signal(char *, int, int);
int	check_map(char **);
char	*convert_to_binary_letter(char *);
char	*convert_to_binary_number(char *);

			/******* INCLUDE ERROR *******/


#endif /* !NAVY_H */
