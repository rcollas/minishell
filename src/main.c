/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <rcollas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:23:03 by rcollas           #+#    #+#             */
/*   Updated: 2021/10/01 11:17:57 by rcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_echo()
{
	return (0);
}

int	ft_cd()
{
	return (0);
}

int	ft_pwd()
{
	return (0);
}

int	ft_export()
{
	return (0);
}

int	ft_unset()
{
	return (0);
}

int	ft_env()
{
	return (0);
}

int	ft_exit()
{
	return (0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
	{
		if (s2[i + 1] == 0)
			return (1);
		i++;
	}
	return (0);
}

void	init_builtin(t_builtin *builtin)
{
	builtin[0].cmd = "echo";
	builtin[0].func = ft_echo;
	builtin[1].cmd = "cd";
	builtin[1].func = ft_cd;
	builtin[2].cmd = "pwd";
	builtin[2].func = ft_pwd;
	builtin[3].cmd = "export";
	builtin[3].func = ft_export;
	builtin[4].cmd = "unset";
	builtin[4].func = ft_unset;
	builtin[5].cmd = "env";
	builtin[5].func = ft_env;
	builtin[6].cmd = "exit";
	builtin[6].func = ft_exit;
	builtin[7].cmd = NULL;
	builtin[7].func = NULL;
}

int	is_builtin(char *line, t_builtin *builtin)
{
	int	i;

	i = 0;
	while (builtin[i].cmd)
	{
		if (ft_strcmp(line, builtin[i].cmd) == 1)
		{
			return (i);
		}
		i++;
	}
	return (0);
}

int	main(void)
{
	char	*line;
	int	ret;
	int	i;
	t_builtin *builtin;
	
	builtin = malloc(sizeof(t_builtin) * 8);
	init_builtin(builtin);
	i = -1;
	ret = 0;
	while (1)
	{
		line = readline("minishell $> ");
		printf("line = %s\n", line);
		ret = is_builtin(line, builtin);
		printf("%d\n", ret);
	}
	return (0);
}
