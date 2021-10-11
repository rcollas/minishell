/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 10:57:38 by vbachele          #+#    #+#             */
/*   Updated: 2021/10/06 02:04:43 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h" //remplacer par le vrai path

int	ft_exit(t_var *var)
{
	//Rajouter ce qu'on doit free ailleurs
	(void) var;
	exit (EXIT_SUCCESS);
	return (0);
}
