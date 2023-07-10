#include "fdf.h"

void	rotate_x(int *y, int *z, double alpha)
{
	int	prev_y;

	prev_y = *y;
	*y = prev_y * cos(alpha) - (*z) * sin(alpha);
	*z = prev_y * sin(alpha) + (*z) * cos(alpha);
}

void	rotate_y(int *z, int *x, double beta)
{
	int	prev_x;

	prev_x = *x;
	*x = prev_x * cos(beta) + (*z) * sin(beta);
	*z = -prev_x * sin(beta) + (*z) * cos(beta);
}

void	rotate_z(int *x, int *y, double gamma)
{
	int	prev_x;

	prev_x = *x;
	*x = prev_x * cos(gamma) - (*y) * sin(gamma);
	*y = prev_x * sin(gamma) + (*y) * cos(gamma);
}
