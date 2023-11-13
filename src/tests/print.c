#include <stdio.h>
# include "libft_defs.h"
# include "miniRT_defs.h"

void	printaux()
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
	t_list	*iter[4];

	printf("Leido del archivo: %s\n", d->txt);
	printf("lineas: %li\n", d->line);
	printf("\n");
	printf("INFO : \n");
	printf("ambient	: %li\n", d->info.ambient_light);
	printf("camara	: %li\n", d->info.camera);
	printf("lights	: %li\n", d->info.lights);
	printf("planes	: %li\n", d->info.planes);
	printf("spheres	: %li\n", d->info.spheres);
	printf("cylinder: %li\n", d->info.cylinders);
	printf("\n");
	printf("Ambiental : \n");
	printf("brightness: %f\n", d->ambient_light.brightness);
	printf("colors r: %d,", d->ambient_light.color.r);
	printf("colors g: %d,", d->ambient_light.color.g);
	printf("colors b: %d,", d->ambient_light.color.b);
	printf("colors a: %d\n", d->ambient_light.color.a);
	printf("\n");
	printf("Camera : \n");
	printf("FOV: %f\n", d->camera.fov);
	printf("center x: %f,", d->camera.center.x);
	printf("center y: %f,", d->camera.center.y);
	printf("center z: %f\n", d->camera.center.z);
	printf("n_vector x: %f,", d->camera.n_vector.x);
	printf("n_vector y: %f,", d->camera.n_vector.y);
	printf("n_vector z: %f\n", d->camera.n_vector.z);
	printf("\n");
	printf("\n");
	printf("_____________LIST________________ : \n");
	iter[0] = (t_list *)d->lights;
	while (iter[0])
	{
		printf("Lights : \n");
		t_light *aux = (t_light *)iter[0]->content;
		printf("center x: %f,", aux->center.x);
		printf("center y: %f,", aux->center.y);
		printf("center z: %f\n", aux->center.z);
		printf("brightness: %f\n", aux->brightness);
		printf("colors r: %d,", aux->color.r);
		printf("colors g: %d,", aux->color.g);
		printf("colors b: %d,", aux->color.b);
		printf("colors a: %d\n", aux->color.a);
		iter[0] = iter[0]->next;
	}
	printf("\n");
	iter[1] = (t_list *)d->planes;
	while (iter[1])
	{
		printf("Planes : \n");
		t_plane *aux1 = (t_plane *)iter[1]->content;
		printf("center x: %f,", aux1->center.x);
		printf("center y: %f,", aux1->center.y);
		printf("center z: %f\n", aux1->center.z);
		printf("n_vector x: %f,", aux1->n_vector.x);
		printf("n_vector y: %f,", aux1->n_vector.y);
		printf("n_vector z: %f\n", aux1->n_vector.z);
		printf("colors r: %d,", aux1->material.color.r);
		printf("colors g: %d,", aux1->material.color.g);
		printf("colors b: %d,", aux1->material.color.b);
		printf("colors a: %d\n", aux1->material.color.a);
		iter[1] = iter[1]->next;
	}
	printf("\n");
	iter[2] = (t_list *)d->spheres;
	while(iter[2])
	{
		printf("Spheres : \n");
		t_sphere *aux2 = (t_sphere *)iter[2]->content;
		printf("center x: %f,", aux2->center.x);
		printf("center y: %f,", aux2->center.y);
		printf("center z: %f\n", aux2->center.z);
		printf("Diameter: %f\n", aux2->diameter);
		printf("colors r: %d,", aux2->material.color.r);
		printf("colors g: %d,", aux2->material.color.g);
		printf("colors b: %d,", aux2->material.color.b);
		printf("colors a: %d\n", aux2->material.color.a);
		iter[2] = iter[2]->next;
	}
	printf("\n");
	iter[3] = (t_list *)d->cylinders;
	while (iter[3])
	{
		printf("Cylinders : \n");
		t_cylinder *aux3 = (t_cylinder *)iter[3]->content;
		printf("center x: %f,", aux3->center.x);
		printf("center y: %f,", aux3->center.y);
		printf("center z: %f\n", aux3->center.z);
		printf("n_vector x: %f,", aux3->n_vector.x);
		printf("n_vector y: %f,", aux3->n_vector.y);
		printf("n_vector z: %f\n", aux3->n_vector.z);
		printf("Diameter: %f\n", aux3->diameter);
		printf("Height: %f\n", aux3->height);
		printf("colors r: %d,", aux3->material.color.r);
		printf("colors g: %d,", aux3->material.color.g);
		printf("colors b: %d,", aux3->material.color.b);
		printf("colors a: %d\n", aux3->material.color.a);
		iter[3] = iter[3]->next;
	}
	printf("\n");
}