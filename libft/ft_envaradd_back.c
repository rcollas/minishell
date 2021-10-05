/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envaradd_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 16:48:31 by rcollas           #+#    #+#             */
/*   Updated: 2021/10/05 13:53:13 by rcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_envaradd_back(t_envar **alst, t_envar *new)
{
	t_envar	*last;

	if (!alst || !new)
		return ;
	if (*alst)
	{
		last = ft_envarlast(*alst);
		last->next = new;
	}
	else
		*alst = new;
}
