#include <stdio.h>
#include "structure.h"
#include "math_vec.h"
#include "print.h"
#include "scene.h"
#include "trace.h"
#include "error.h"
#include "mlx.h"

t_scene *scene_init(void)
{
	t_scene		*scene;
	t_object	*world;
	t_object	*lights;
	double		ka;

	/* error 처리 */
	if (!(scene = (t_scene *)malloc(sizeof(t_scene))))
		return (NULL);
	scene->canvas = canvas(400, 300);
	scene->camera = camera(&scene->canvas, coord3(0, 0, 0));
	world = object(SP, sphere(coord3(-2, 0, -5), 2), color3(0.5, 0, 0));
	obj_add(&world, object(SP, sphere(coord3(0, -1000, 0), 995), color3(1, 1, 1)));
	obj_add(&world, object(SP, sphere(coord3(2, 0, -5), 2), color3(0, 0.5, 0)));
	// obj_add(&world, object(SP, sphere(coord3(0, -1000, 0), 990), color3(1, 1, 1)));
	scene->world = world;
	lights = object(LIGHT_POINT, light_point(coord3(0, 20, 0), color3(1, 1, 1), 0.5), color3(0, 0, 0));
	// lights = object(LIGHT_POINT, light_point(coord3(0, 5, 0), color3(1, 1, 1), 0.5), color3(0, 0, 0));
	scene->light = lights;
	ka = 0.1;
	scene->ambient = color3(ka, ka, ka);
	return (scene);
}

void	draw(t_scene *scene)
{
	int			i;
	int			j;
	double		u;
	double		v;
	t_color3	pixel_color;

    // 랜더링
    // P3 는 색상값이 아스키코드라는 뜻, 그리고 다음 줄은 캔버스의 가로, 세로 픽셀 수, 마지막은 사용할 색상값
	printf("P3\n%d %d\n255\n", scene->canvas.width, scene->canvas.height);
    j = scene->canvas.height - 1;
    while (j >= 0)
    {
        i = 0;
		while (i < scene->canvas.width)
        {
            u = (double)i / (scene->canvas.width - 1);
            v = (double)j / (scene->canvas.height - 1);
            //ray from camera origin to pixel
            scene->ray = ray_primary(&scene->camera, u, v);
            pixel_color = ray_color(scene);
            write_color(pixel_color);
        ++i;
        }
    --j;
    }
}

int	main(int argc, char *argv[])
{
	t_scene	*scene;
	t_mlx	mlx;

	mlx_init(&mlx);
	if (argc != 2)
		return (err_put_str(ERR_ARGC, 1));
	scene = scene_init(argc, argv);
	draw(scene);

	return (0);
}

// int	parse_file(t_scene *scene, const char *file)
// {
// 	if (ft_strncmp(file + ft_strlen(file) - 3, ".rt", 3) != 0)
// 		return (-1);
// }
