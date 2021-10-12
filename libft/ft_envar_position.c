/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envar_position.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:52:40 by vbachele          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/10/12 11:36:09 by vbachele         ###   ########.fr       */
=======
/*   Updated: 2021/10/12 11:55:21 by vbachele         ###   ########.fr       */
>>>>>>> ccd53bc9a6febf5338715bb1bd146ab3ac57a6c2
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
