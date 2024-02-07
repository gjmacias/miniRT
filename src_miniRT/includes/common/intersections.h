/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:15:23 by ffornes-          #+#    #+#             */
/*   Updated: 2024/02/05 19:21:24 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTIONS_H
# define INTERSECTIONS_H

# include "miniRT_defs.h"

void		rayhit_pl(t_vector *o, t_vector *r, t_plane *pl, t_itsc *itsc);
void		rayhit_sp(t_vector *o, t_vector *r, t_sphere *sp, t_itsc *itsc);
void		rayhit_cy(t_vector *o, t_vector *r, t_cylinder *cy, t_itsc *itsc);
double		cy_caps(t_vector *o, t_vector *r, t_cylinder *cy, t_itsc *itsc);
t_vector	get_itsc_p(t_vector *ray_dir, t_vector *ray0, double t);
void		get_itsc_normal(t_itsc *itsc);

#endif
