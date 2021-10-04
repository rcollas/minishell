/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 11:39:06 by vbachele          #+#    #+#             */
/*   Updated: 2021/10/04 11:56:53 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(t_var *var)
{
	int dir;
	if (dir = access(var->pwd->string_pwd, F_OK))
		ft_putendl_fd(var->pwd->string_pwd, 1);
	if (dir < 0)
		perror("path is invalid");
}