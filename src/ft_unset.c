/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 17:29:54 by vbachele          #+#    #+#             */
/*   Updated: 2021/10/05 10:52:05 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/minishell.h"

int	ft_unset(t_var *var)
{
	t_list *tmp;

	tmp = get_env_list //remplacer par le vrai nom
	while(tmp)
	{
		if(strcmp(tmp->content), argv[2] == 1)
		{
			ft_lstdelone(tmp, del);
			On supprime lelement  // 2 manieres pour supprimer de la liste - avec la position ou doublement chainee.
			break;
		} // remplacer par la fonction ft_strcmp
		tmp = tmp->next; 
	}
	return (0);
}