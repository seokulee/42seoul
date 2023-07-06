#include "fdf.h"

static int	lerp(int s, int f, int ratio);
static double	get_ratio(int s, int f, int cur);

int	get_color(t_spot *s, t_spot *f, t_spot cur)
{
	int		r;
	int		g;
	int		b;
	double	ratio;


	if (cur.clr == f->clr)
		return (cur.clr);
	if ((f->x - s->x) > (f->y - s->y))
		ratio = get_ratio(s->x, f->x, cur.x);
	else
		ratio = get_ratio(s->y, f->y, cur.y);
	r = lerp((s->clr >> 16) & 0xff, (f->clr >> 16) & 0xff, ratio);
	g = lerp((s->clr >> 8) & 0xff, (f->clr >> 8 & 0xff), ratio);
	b = lerp((s->clr) & 0xff, (f->clr) & 0xff, ratio);
	return ((r << 16) | (g << 8) | (b));
}

static double	get_ratio(int s, int f, int cur)
{
	double	ratio;

	if (s == f)
		return (1.0);
	ratio = (double)(cur - s) / (f - s);
	return (ratio);
}
static int	lerp(int s, int f, int ratio)
{
	int ret;

	ret = (int) (s * (1 - ratio) + f * ratio);
	return (ret);
}
