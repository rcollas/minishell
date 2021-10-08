#include "minishell.h"

int	ft_envarsize(t_envar *envar)
{
	int	i;

	i = 0;
	while (envar)
	{
		envar = envar->next;
		i++;
	}
	return (i);
}
