/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_excve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 12:13:38 by vbachele          #+#    #+#             */
/*   Updated: 2021/10/08 14:47:33 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_excve(t_var *var, char **argv)
{
	char 	*path_final;
	char	**path_fromenvp;
	t_envar	*tmp;

	tmp = var->envar;
	path_final = ft_envar_find_content(tmp, "PATH");
	if (var->cmd == 0)
	{
		ft_putendl_fd("command not found", 2);
		return (0);
	}
	path_fromenvp = ft_split(path_final, ':');
	path_final = get_path(var, path_fromenvp, argv);
	if (execve(path_final, &var->cmd, 0) == -1)
		execve_error(var, path_final);
	return (0);
}

char	*get_path(t_var *var, char **path_fromenvp, char **argv)
{
	char	*path_final;
	char	*path_semi_final;
	int		i;

	i = 0;
	(void) argv;
	while (path_fromenvp[i])
	{
		path_final = 0;
		path_semi_final = ft_strjoin(path_fromenvp[i], "/");
		path_final = ft_strjoin(path_semi_final, var->cmd);
		if (access(path_final, F_OK) == 0)
			return (path_final);
		if (path_final)
			free (path_final);
		i++;
	}
	// if (var->cmd[0] == '/'
	// 	&& access(&var->cmd[0], F_OK) == 0)
	// 	return (&var->cmd[0]);
	return (NULL);
}

void	execve_error(t_var *var, char *path_final)
{
	(void) var;
	if (path_final)
		free(path_final);
	ft_putendl_fd("Command not found", 2);
	exit(EXIT_FAILURE);
	// FREE DES FONCTIONS ICI
}