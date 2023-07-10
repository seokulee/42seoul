#include "fdf.h"

int	key_pressed(int key, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (key == 53)
		exit(0);
	else if (key == 24 || key == 27)
		change_zoom(key, fdf);
	printf("%d\n", key);
	return (0);
}
