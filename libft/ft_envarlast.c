/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envarlast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 16:49:12 by rcollas           #+#    #+#             */
/*   Updated: 2021/10/01 15:03:24 by rcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_envar	*ft_envarlast(t_envar *envar)
{
	if (!envar)
		return (NULL);
	while (envar)
	{
		if (envar->next == NULL)
			return (envar);
		envar = envar->next;
	}
	return (envar);
}
