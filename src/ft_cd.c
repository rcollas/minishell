/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 16:43:47 by vbachele          #+#    #+#             */
/*   Updated: 2021/10/04 11:47:42 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	errors_chdir_handling(int dir)
{
	if (dir < 0)
		perror("cd failed");
	exit(1);
}

int	main(int argc, char **argv)
{
	int		dir;
	char	*s;

	s = argv[1];
	// printf("%s\n", getcwd(s, 100));
	if (ft_strcmp(argv[1], "cd") == 1)
	{
		dir = chdir(var->cd->string_cd);
		if (dir < 0)
			Errors_chdir_handling(dir);
	}
	printf("%s\n", getcwd(s, 100));
	return (0);
}
