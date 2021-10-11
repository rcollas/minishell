/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 10:57:38 by vbachele          #+#    #+#             */
/*   Updated: 2021/10/11 16:38:43 by rcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h" //remplacer par le vrai path

int	ft_exit(t_var *var)
{
	//Rajouter ce qu'on doit free ailleurs
	free_envar(var->envar);
	rl_clear_history();
	exit (EXIT_SUCCESS);
	return (0);
}
