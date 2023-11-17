/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:01:50 by gmacias-          #+#    #+#             */
/*   Updated: 2023/11/17 15:53:32 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft_defs.h"
#include "miniRT_defs.h"
# define cRED "\033[0;31m"
# define cGREEN "\033[0;32m"
# define cYELLOW "\033[0;33m"
# define cBLUE "\033[0;34m"
# define cPURPLE "\033[0;35m"
# define cCYAN "\033[0;36m"
# define cWHITE "\033[0;37m"

void	printaux(void)
{
	printf("paso por aqui\n");
}

void	printpp(char **arguments)
{
	int	i;

	i = 0;
	if (arguments)
	{
		while (arguments[i])
		{
			printf("%s", arguments[i++]);
			if (arguments[i])
				printf("\t\t");
			else
				printf("(null)\n");
		}
	}
	else
		printf("(null)");
}

void	print_data(t_data *d)
{
	t_list		*iter[4];
	t_light		*aux;
	t_plane		*aux1;
	t_sphere	*aux2;
	t_cylinder	*aux3;

	printf("\nINFO\n");
	printf("\tCamera:\t\t%li\n", d->info.camera);
	printf("\tAmbient:\t%li\n", d->info.ambient_light);
	printf("\tLights:\t\t%li\n", d->info.lights);
	printf("\tPlanes:\t\t%li\n", d->info.planes);
	printf("\tSpheres:\t%li\n", d->info.spheres);
	printf("\tCylinders:\t%li\n", d->info.cylinders);
	printf("\n");
	printf(cRED"Camera\n"cWHITE);
	printf("\tFOV:\t\t%.2f\n", d->camera.fov);
	printf("\tPosition:\t[ X %.2f ]\t", d->camera.center.x);
	printf("[ Y %.2f ]\t", d->camera.center.y);
	printf("[ Z %.2f ]\n", d->camera.center.z);
	printf("\tNormal:\t\t[ X %.2f ]\t", d->camera.n_vector.x);
	printf("[ Y %.2f ]\t", d->camera.n_vector.y);
	printf("[ Z %.2f ]\n", d->camera.n_vector.z);
	printf("\n");
	printf(cCYAN"Ambiental\n"cWHITE);
	printf("\tBrightness:\t%.2f\n", d->ambient_light.brightness);
	printf("\tColor:\t\t[ R %d ]", d->ambient_light.color.r);
	printf("[ G %d ]", d->ambient_light.color.g);
	printf("[ B %d ]", d->ambient_light.color.b);
	printf("[ A %d ]\n", d->ambient_light.color.a);
	printf("\n");
	printf("\t-\t-\t-\t-\t-\t-\t-\t-\n");
	printf("\t|\t\t\t  LISTS\t\t\t\t|\n");
	printf("\t-\t-\t-\t-\t-\t-\t-\t-\n\n");
	iter[0] = (t_list *)d->lights;
	while (iter[0])
	{
		printf(cYELLOW"Lights\n"cWHITE);
		aux = (t_light *)iter[0]->content;
		printf("\tBrightness:\t%.2f\n", aux->brightness);
		printf("\tPosition:\t[ X %.2f ]\t", aux->center.x);
		printf("[ Y %.2f ]\t", aux->center.y);
		printf("[ Z %.2f ]\n", aux->center.z);
		printf("\tColor:\t\t[ R %d ]", aux->color.r);
		printf("[ G %d ]", aux->color.g);
		printf("[ B %d ]", aux->color.b);
		printf("[ A %d ]\n", aux->color.a);
		printf("\n");
		iter[0] = iter[0]->next;
	}
	iter[1] = (t_list *)d->planes;
	while (iter[1])
	{
		printf(cGREEN"Planes\n"cWHITE);
		aux1 = (t_plane *)iter[1]->content;
		printf("\tPosition:\t[ X %.2f ]\t", aux1->center.x);
		printf("[ Y %.2f ]\t", aux1->center.y);
		printf("[ Z %.2f ]\n", aux1->center.z);
		printf("\tNormal:\t\t[ X %.2f ]\t", aux1->n_vector.x);
		printf("[ Y %.2f ]\t", aux1->n_vector.y);
		printf("[ Z %.2f ]\n", aux1->n_vector.z);
		printf("\tColor:\t\t[ R %d ]", aux1->material.color.r);
		printf("[ G %d ]", aux1->material.color.g);
		printf("[ B %d ]", aux1->material.color.b);
		printf("[ A %d ]\n", aux1->material.color.a);
		printf("\n");
		iter[1] = iter[1]->next;
	}
	iter[2] = (t_list *)d->spheres;
	while (iter[2])
	{
		printf(cBLUE"Spheres\n"cWHITE);
		aux2 = (t_sphere *)iter[2]->content;
		printf("\tDiameter:\t%.2f\n", aux2->diameter);
		printf("\tPosition:\t[ X %.2f ]\t", aux2->center.x);
		printf("[ Y %.2f ]\t", aux2->center.y);
		printf("[ Z %.2f ]\n", aux2->center.z);
		printf("\tColor:\t\t[ R %d ]", aux2->material.color.r);
		printf("[ G %d ]", aux2->material.color.g);
		printf("[ B %d ]", aux2->material.color.b);
		printf("[ A %d ]\n", aux2->material.color.a);
		printf("\n");
		iter[2] = iter[2]->next;
	}
	printf("\n");
	iter[3] = (t_list *)d->cylinders;
	while (iter[3])
	{
		printf(cPURPLE"Cylinders\n"cWHITE);
		aux3 = (t_cylinder *)iter[3]->content;
		printf("\tDiameter:\t%.2f\n", aux3->diameter);
		printf("\tHeight:\t\t%.2f\n", aux3->height);
		printf("\tPosition:\t[ X %.2f ]\t", aux3->center.x);
		printf("[ Y %.2f ]\t", aux3->center.y);
		printf("[ Z %.2f ]\n", aux3->center.z);
		printf("\tNormal:\t\t[ X %.2f ]\t", aux3->n_vector.x);
		printf("[ Y %.2f ]\t", aux3->n_vector.y);
		printf("[ Z %.2f ]\n", aux3->n_vector.z);
		printf("\tColor:\t\t[ R %d ]", aux3->material.color.r);
		printf("[ G %d ]", aux3->material.color.g);
		printf("[ B %d ]", aux3->material.color.b);
		printf("[ A %d ]\n", aux3->material.color.a);
		printf("\n");
		iter[3] = iter[3]->next;
	}
	printf("Lines: %li\n", d->line);
	printf("Filename: %s\n", d->txt);
	printf("\n");
}
