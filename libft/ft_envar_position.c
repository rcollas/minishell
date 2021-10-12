/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envar_position.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:52:40 by vbachele          #+#    #+#             */
/*   Updated: 2021/10/11 17:30:58 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_envar_position(t_envar *envar, char *str)
{
	t_envar	*tmp;
	int		i;

	i = 0;
	tmp = envar;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, str))
		{
			i++;
			return (i);
		}
		i++;
		tmp = tmp->next;
	}
	return (0);
}