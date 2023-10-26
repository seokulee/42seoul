#include "minirt.h"

static int	key_pressed(int keycode, void *param);

void	event_handler(t_data *data, t_scene *scene)
{
	void	*param;

	param = (void *)scene;
	mlx_hook(data->mlx_win, 2, 0, key_pressed, param);
}

static int	key_pressed(int keycode, void *param)
{
	if (keycode == KEY_ESC)
		free_all((t_scene *)param);
	return (0);
}
