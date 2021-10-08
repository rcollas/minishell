#include "minishell.h"

int	list_remove(t_list **list, int pos)
{
	t_list	*start;
	t_list	*tmp;
	int		i;

	start = *list;
	i = 0;
	if (pos < 1 || pos > ft_lstsize(*list))
		return (0);
	while (*list && ++i < pos - 1)
	{
		*list = (*list)->next;
	}
	if (i == 1)
		*list = (*list)->next;
	else
	{
		tmp = (*list)->next;
		if ((*list)->next->next)
			(*list)->next = (*list)->next->next;
		else
			(*list)->next = NULL;
		free(tmp);
		*list = start;
	}
	return (1);
}

int	envar_remove(t_envar **envar, int pos)
{
	t_envar	*start;
	t_envar	*tmp;
	int		i;

	start = *envar;
	i = 0;
	if (pos < 1 || pos > ft_envarsize(*envar))
		return (0);
	while (*envar && ++i < pos - 1)
	{
		*envar = (*envar)->next;
	}
	if (i == 1)
		*envar = (*envar)->next;
	else
	{
		tmp = (*envar)->next;
		if ((*envar)->next->next)
			(*envar)->next = (*envar)->next->next;
		else
			(*envar)->next = NULL;
		free(tmp);
		*envar = start;
	}
	return (1);
}
