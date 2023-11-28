#include "print.h"

void	write_color(t_color3 color)
{
	printf("%d %d %d\n", (int)(255.999 * color.x),
						(int)(255.999 * color.y),
						(int)(255.999 * color.z));
}
