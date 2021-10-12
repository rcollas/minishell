/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 17:29:54 by vbachele          #+#    #+#             */
/*   Updated: 2021/10/11 17:41:35 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_unset(t_var *var)
{
	t_envar *tmp;
	int pos;
	
	pos = 0;
	tmp = var->envar;
	var->cmd = &(var->cmd[6]);
	while (tmp)
	{
		if (ft_strcmp(tmp->name, var->cmd) == 1)
		{
			pos = ft_envar_position(var->envar, tmp->name);
			envar_remove(&var->envar, pos);
		}
		tmp = tmp->next;
	}
	return (0);
}