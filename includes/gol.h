#ifndef GOL_H
# define GOL_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <math.h>
# include <string.h>
# include <termios.h>
# include "../libft/libft.h"

# define HELP_FILE "Usage: ./GameOfLife [options] [SEED || SOURCE_FILE]\n\nOptions:\n\t-h : Displays the help window (Yeah, this one).\n\t-g : Generates a random seed for the map initialization.\n\t-s : Tells the program to wait for a user input seed (= SEED, must be 50 characters long and composed of ASCII values between 33 and 96).\n\t-f : Tells the program to load the map from a file (= SOURCE_FILE).\n\t     The map must be a 25*32 square, with '.' characters as empty spaces and '*' as living cells. Any deviation from this model will cause a parsing error.\n"

enum	e_options
{
	HELP,
	GENERATE,
	PLAIN_SEED,
	SOURCE_FILE
};

typedef struct		s_data
{
	char			**map;
	char			*seed;
	struct termios	term;
}					t_data;

void	error(int type);
t_data	*input_options(t_data *info, int argc, char **argv);
char	*seed_generate();
char	*dec_to_bin(int value);
char	*map_to_seed(char **map);

#endif
