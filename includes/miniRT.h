/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:26:10 by gmacias-          #+#    #+#             */
/*   Updated: 2023/11/06 17:15:53 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "miniRT_defs.h"

void	start_mlx(t_vars *vars, t_mlx_data *data);

// HOOKS
int		key_hook(int keycode, t_vars *vars);
int		finish_execution(void);
