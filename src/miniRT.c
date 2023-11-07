/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:33:50 by gmacias-          #+#    #+#             */
/*   Updated: 2023/11/06 17:13:31 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "miniRT.h"
#include "miniRT_defs.h"

int  main(int words, char **arguments)
{
	t_vars		vars;
	t_mlx_data	data;

	if (words == 2)
	{
		checker_main(arguments);
		start_mlx(&vars, &data);
		mlx_key_hook(vars.win, key_hook, &vars);
		mlx_hook(vars.win, 17, 0, finish_execution, &vars);
		mlx_loop(vars.mlx);
	}
	else
		write(2, "Error: Bad arguments\n", 22);
	return (0);
}
