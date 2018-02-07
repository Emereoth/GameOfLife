#include "libft.h"

int		ft_charcount(char *str, char c)
{
	int		i;
	int		res;

	i = -1;
	res = 0;
	while (str[++i])
		if (str[i] == c)
			res++;
	return (res);
}
