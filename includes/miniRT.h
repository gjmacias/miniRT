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

// CHECKERS
void	check_format_dotrt(char *txt);
void	checker_main(char **arguments);

// EXIT
int		ft_exit(t_data *data);

// HOOKS
int		key_hook(int keycode, t_vars *vars);
int		finish_execution(void);

//  INITS
void	init_mlx(t_vars *vars, t_mlx_data *data);
void    init_parameters(t_data *parameters);

//  PARSE
void	parse_txt(t_data *p);

//  UTILS
int		is_space(int c);