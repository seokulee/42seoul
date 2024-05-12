#ifndef MINIRT_H
# define MINIRT_H

# include "world.h"

# define WIDTH 400
# define HEIGHT 300

void init_world(t_world *world, int argc, char *rt_file);
void rendering(t_world *world);

#endif
