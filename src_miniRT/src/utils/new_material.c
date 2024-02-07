/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_material.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:23:57 by ffornes-          #+#    #+#             */
/*   Updated: 2023/12/12 11:25:51 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_defs.h"

t_material	new_material(t_color color, double specular)
{
	t_material	out;

	out.color = color;
	out.specular = specular;
	return (out);
}
