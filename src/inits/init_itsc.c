/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_itsc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:35:34 by ffornes-          #+#    #+#             */
/*   Updated: 2024/02/05 13:35:36 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_defs.h"

void	init_itsc(t_itsc *itsc)
{
	itsc->type = 0;
	itsc->address = NULL;
	itsc->dist = -1;
	itsc->p = NULL;
	itsc->normal = NULL;
}
