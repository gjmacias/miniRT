/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:33:50 by gmacias-          #+#    #+#             */
/*   Updated: 2024/01/23 16:09:02 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "miniRT.h"
#include "miniRT_defs.h"

int	main(int words, char **arguments)
{
	t_mlx_data	data;
	t_data		parameters;
	t_hook		hook;

	if (words == 2 || words == 4)
	{
		if (words == 4)
			init_canvas(&parameters, arguments[2], arguments[3]);
		else
			init_canvas(&parameters, "1920", "1080");
		parameters.txt = arguments[1];
		check_format_dotrt(parameters.txt);
		parse_txt(&parameters);
		//print_data(&parameters);
		init_mlx(&data, &parameters);
		hook.data = &data;
		hook.parameters = &parameters;	
		//mlx_key_hook(data.vars.win, key_hook, &(data.vars));
		mlx_key_hook(data.vars.win, key_hook_test, &hook);
		mlx_hook(data.vars.win, 17, 0, finish_execution, &(data.vars));
		render_camera(&parameters, &data, 0, parameters.height);
		mlx_loop(data.vars.mlx);
	}
	else
		write_error("Error: Bad arguments. { Usage: \"./miniRT file.rt\" }\n");
	return (0);
}
