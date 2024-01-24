#include "miniRT_defs.h"

void	init_itsc(t_itsc *itsc)
{
	itsc->type = 0;
	itsc->address = NULL;
	itsc->dist = -1;
	itsc->p = NULL;
	itsc->normal = NULL;
}
