/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:41:31 by vbachele          #+#    #+#             */
/*   Updated: 2021/10/04 17:17:43 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include <string.h>

int	ft_env(char **envp, char **argv) //rajouter la structure
{
	int i;

	i = 0;
	if (argv[2][0] != '|' || argv[2][0] != 0) //valeur a changer dynamiquement
	{
		write(2, "Illegal option\n", 15);
		exit(1);
	}
	if (!envp)
	{
		printf("Error\n");
		exit(1);
	}
	while (envp[i]) //remplacer par la liste
	{
		printf("%s\n", envp[i]);
		i++;
	}
	return (0);
}

int main(int argc, char **argv, char **envp)
{
	(void) argc;
	if (strcmp(argv[1], "env") == 0)
		ft_env(envp, argv);
	return (0);
}
