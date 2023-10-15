#include "minirt.h"

int	main(int argc, char *argv[])
{
	t_scene	*scene;
	t_data	*data;

	if (argc != 2)
		return (err_put_str(ERR_ARGC, 1));
	scene = init_scene();
	if (read_rt_file(scene, argv[1]) == -1)
		return (err_put_str(ERR_FILE, 1));
	data = init_data();
	if (data == NULL)
		return (err_put_str(ERR_INIT, 1));
	/* free */
	draw(data, scene);
}
