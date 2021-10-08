#include "minishell.h"

int	list_insert(t_list **list, t_list *new, int pos)
{
	t_list	*start;
	t_list	*tmp;
	int		i;

	start = *list;
	i = 0;
	if (pos < 2 || pos > ft_lstsize(*list))
	{
		free(new);
		return (0);
	}
	while (*list && ++i < pos - 1)
	{
		*list = (*list)->next;
	}
	tmp = (*list)->next;
	(*list)->next = new;
	new->next = tmp;
	*list = start;
	return (1);
}

int	envar_insert(t_envar**envar, t_envar *new, int pos)
{
	t_envar	*start;
	t_envar	*tmp;
	int		i;

	start = *envar;
	i = 0;
	if (pos < 2 || pos > ft_envarsize(*envar))
	{
		free(new);
		return (0);
	}
	while (*envar && ++i < pos - 1)
	{
		*envar = (*envar)->next;
	}
	tmp = (*envar)->next;
	(*envar)->next = new;
	new->next = tmp;
	*envar = start;
	return (1);
}
