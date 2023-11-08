#include "miniRT.h"
#include "miniRT_defs.h"

void	init_parameters_info(t_data *p)
{
	p->line = 0;
	p->info.ambient_light = 0;
	p->info.camera = 0;
	p->info.cylinders = 0;
	p->info.lights = 0;
	p->info.planes = 0;
	p->info.spheres = 0;
}
