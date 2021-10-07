/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 10:27:30 by vbachele          #+#    #+#             */
/*   Updated: 2021/10/07 11:17:45 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_export(t_var *var)
{
	t_envar *new;
	
	var->cmd = &(var->cmd[7]); // changer cette maniere de recup l'argument
	// printf("\n\n\n%s\n\n\n", var->cmd);
	if (var->cmd == NULL)
		ft_env(var); // Permet d'afficher env quand aucun 2 eme argument
	else
	{
		if (var->cmd[0] != '=')
		{
				new = ft_envar_new("salut", var->cmd);
				if (!new)
					return (0);
				ft_envaradd_back(&var->envar, new); // pourquoi mettre var->list ?
		}
		// Ajouter un bloc sur l'avant dernier bloc avec les infos de l'argument apres export
		// Le = ne doit pas etre le premier caractere
	}
	return (0);
}