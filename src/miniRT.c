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

int	main(int words, char **arguments)
{
	t_mlx_data	data;
	t_data		parameters;

	if (words == 2 || words == 4)
	{
		if (words == 2)
			init_canvas(&parameters, arguments[2], arguments[3]);
		else
			init_canvas(&parameters, "1920", "1080");
		parameters.txt = arguments[1];
		check_format_dotrt(parameters.txt);
		parse_txt(&parameters);
		init_mlx(&data, &parameters);
		mlx_key_hook(vars.win, key_hook, &(data.vars));
		mlx_hook(data.vars.win, 17, 0, finish_execution, &(data.vars));
		mlx_loop(data.vars.mlx);
	}
	else
		write(2, "Error : Bad arguments. { Usage : \"./miniRT file.rt\" }\n", 55);
	return (0);
}
