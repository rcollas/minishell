/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 10:57:38 by vbachele          #+#    #+#             */
/*   Updated: 2021/10/05 11:27:07 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h" //remplacer par le vrai path

void	ft_exit(t_var *var, char *line)
{
	if (strcmp(line, "exit") == 0) // remplacer par le vrai ft_strcmp
	{
		// il faut surement free tout ce qu'on a fait.
		free(line);
		exit(EXIT_SUCCESS);
	}
	return (0);
}