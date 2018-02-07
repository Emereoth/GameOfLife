#include "../includes/gol.h"

void	error(int type)
{
	if (type == 1)
		ft_putstr_err("Must have 1 and only 1 argument.\n");
	else if (type == 2)
		ft_putstr_err("Input file not found.\n");
	else if (type == 3)
		ft_putstr_err("Seed generation error, exiting.\n");
	else if (type == 4)
		ft_putstr_err("Fuck you.\n");
	else if (type == 5)
		ft_putstr_err("Incorrect argument number.\n");
	else if (type == 6)
		ft_putstr_err("Incorrect argument formatting.\n");
	else if (type == 7)
		ft_putstr_err("Seed format incorrect.\n");
	if (type == 5 || type == 6)
		ft_putstr_err("Launch executable with the option -h for help.\n");
	exit(type);
}
