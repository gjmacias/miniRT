/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fail_alloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:48:35 by ffornes-          #+#    #+#             */
/*   Updated: 2024/02/05 18:48:58 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	fail_check(void *content, t_data *p)
{
	if (!content)
		clean_exit(p, 12);
}
