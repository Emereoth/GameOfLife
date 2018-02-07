#include "../includes/gol.h"

static int	bin_to_dec(char *bin)
{
	int		res;
	int		i;

	res = 0;
	i = -1;
	printf("Translating : %s\n", bin);
//	ft_triplestr("Translating : ", bin, "\n");
	while (bin[++i])
	{
		if (bin[i] == '*')
		{
		//	ft_triplestr("Value detected in position ", ft_itoa(i), ": ");
			printf("Value detected in position %d : value equals 2 to the power of %d, equals %d\n", i, 7 - i, ft_power(2, 7 - i));
			res += ft_power(2, 7 - i) + 33;
		//	ft_triplestr( , , )
		}
	}
	ft_strdel(&bin);
//	ft_triplestr("Result : ", ft_itoa(res), "\n");
	printf("Result : %d\n", res);
	return (res);
}

char		*map_to_seed(char **map)
{
	char	*res;
	int		i;
	int		j;
	int		k;

	res = ft_strnew(50);
	i = -1;
	k = -1;
	while (map[++i])
	{
		j = 0;
		while (map[i][j])
		{
			res[++k] = bin_to_dec(ft_strndup(map[i] + j, 8));
			j += 8;
		}
	}
	return (res);
}

char		*seed_generate()
{
	char	*seed;
	int		i;

	seed = ft_strnew(50);
	srandom(time(NULL));
	ft_putstr("Generating seed : ");
	for (i = 0; i < 50; i++)
	{
		seed[i] = rand() % 64 + 33;
		if (i % 10 == 0 && i != 0)
		{
			ft_putstr(seed + i - 10);
		//	sleep(1);
		}
	}
	ft_putchar('\n');
	return (seed);
}

char		*dec_to_bin(int value)
{
	int		tier;
	int		tier_max_val;
	int		i;
	char	*res;

	tier = 8;
	i = 0;
	res = ft_strnew(8);
	value -= 33;
	while (tier > 0)
	{
		tier_max_val = ft_power(2, tier - 1);
		if (value >= tier_max_val)
		{
			value -= tier_max_val;
			res[i] = '*';
//			res[i] = (rand() % 2 == 1 ? '*' : '.');
		}
		else
			res[i] = '.';
		tier--;
		i++;
	}
	return (res);
}
