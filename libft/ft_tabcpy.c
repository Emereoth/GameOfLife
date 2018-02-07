#include "libft.h"

char	**ft_tabcpy(char **source)
{
	int		i;
	int		j;
	char	**res;

	i = 0;
	while (source[i])
		i++;
	j = 0;
	while (source[i - 1][j])
		j++;
	res = ft_newtab(i);
	i = 0;
	while (source[i++])
		res[i] = ft_strdup(source[i]);
	return (res);
}
