/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envarsize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 15:22:24 by vbachele          #+#    #+#             */
/*   Updated: 2021/10/08 15:22:29 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_envarsize(t_envar *envar)
{
	int	i;

	i = 0;
	while (envar)
	{
		envar = envar->next;
		i++;
	}
	return (i);
}
