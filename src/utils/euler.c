#include "miniRT.h"

void    move_euler(t_camera *c, double ang)
{
    double steps;
    double rads;
    double where;

    steps = 5.0;
    rads = ang * ( M_PI /180);
    where = c->euler->x + ang;
    c->center->x += (acos(ang) * steps);
    c->center->z += (asin(ang) * steps);
}
