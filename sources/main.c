#include "../includes/gol.h"

static int	check_line(char **map, int i, int j)
{
	int		contacts;
	char	*extract;
	int		start;
	int		length;

	if (i < 0 || i > 15 || j < 0 || j > 24)
		return (0);
	start = j - 1;
	length = 3;
	while (start < 0)
	{
		length--;
		start++;
	}
	extract = ft_strndup(map[i] + start, length);
	contacts = ft_charcount(extract, '*');
	ft_strdel(&extract);
	return (contacts);
}

static int	count_contacts(char **map, int i, int j)
{
	int		contacts;
	int		k;

	k = -1;
	k++;
	contacts = 0;
	contacts += check_line(map, i - 1, j);
	contacts += check_line(map, i , j);
	contacts += check_line(map, i + 1, j);
	return (contacts);
}

static char	**evolve(char **map)
{
	int		i;
	int		j;
	int		contacts;
	char	**res;

	res = ft_newtab(16);
	i = 0;
	while (map[i])
	{
		j = 0;
		res[i] = ft_strnew(25);
		while (map[i][j])
		{
			contacts = count_contacts(map, i, j);
			res[i][j] = (contacts == 2 || contacts == 3 ? '*' : '.');
			j++;
		}
		i++;
	}
	return (res);
}

int			main(int argc, char **argv)
{
	char	**new_map;
	t_data	*info;

	new_map = NULL;
	info = (t_data *)malloc(sizeof(t_data));
	info->map = NULL;
	info->seed = NULL;
	info = input_options(info, argc, argv);
	ft_putendl("map done");
	while (1)
	{
		system("clear");
		ft_puttab(info->map);
		new_map = evolve(info->map);
		ft_triplestr("\nMap origin seed: ", info->seed, "\n");
		ft_triplestr("\nCurrent map seed: ", map_to_seed(info->map), "\n");
		ft_freetab(info->map);
		info->map = new_map;
		sleep(1);
	}
}
