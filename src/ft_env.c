/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:41:31 by vbachele          #+#    #+#             */
/*   Updated: 2021/10/05 14:14:31 by rcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env(t_var *var) //rajouter la structure
{
	t_envar	*tmp;

	tmp = var->envar;
	/*
	if (argv[2][0] != '|' || argv[2][0] != 0) //valeur a changer dynamiquement
	{
		write(2, "Illegal option\n", 15);
		exit(1);
	}
	*/
	if (var->env == FAIL || var->envar == FAIL)
	{
		printf("Error\n");
		//penser a free la liste chainee + builtin
		exit(1);
	}
	while (tmp) //remplacer par la liste
	{
		printf("%s=%s\n", tmp->name, tmp->content);
		tmp = tmp->next;
	}
	return (0);
}
