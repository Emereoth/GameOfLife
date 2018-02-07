#include "../includes/gol.h"

static char		*check_seed(char *seed)
{
	int		i;

	i = -1;
	while (++i)
		if (seed[i] < 33 || seed[i] > 96)
			error(7);
	if (i != 51)
		error(7);
	return (ft_strdup(seed));
}

static char	**deploy_seed(char *seed)
{
	int		i;
	int		j;
	int		k;
	int		dec_seed_index;;
	char	**map;
	char	*tmp;

	map = ft_newtab(16);
	i = 0;
	k = 0;
	dec_seed_index = 0;
	while (i < 16)
	{
		j = 0;
		map[i] = ft_strnew(24);
		while (j < 24)
		{
			tmp = dec_to_bin(seed[dec_seed_index]);
			k++;
			ft_strncpy(map[i] + j, tmp, 8);
			free(tmp);
			j += 8;
			dec_seed_index++;
		}
		i++;
	}
	return (map);
}

t_data		*input_options(t_data *info, int argc, char **argv)
{
	if (argc > 3 || argc < 2 || (ft_strchr(argv[1], 'h') && argv[2]))
		error(5);
	else if (argv[1][0] != '-' || ft_strlen(argv[1]) > 2)
		error(6);
	switch (argv[1][1])
	{
		case 'h':
			printf("%s", HELP_FILE);
			exit(0);
		case 'g':
			info->seed = seed_generate();
			break;
		case 's':
			info->seed = check_seed(argv[2]);
			break;
//		case 'f':
//			info->map = read_map(argv[2]);
//			break;
		default:
			printf("%s", HELP_FILE);
			exit(0);
	}
	if (!(info->map))
		info->map = deploy_seed(info->seed);
	return (info);
}
