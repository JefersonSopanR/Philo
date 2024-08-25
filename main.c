#include "philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	memset(&data, 0, sizeof(t_data));
	if (ac != 5 && ac != 6)
	{
		write_err("number of arguments\n");
		return (1);
	}
	if (ft_init(&data, av))
		return (1);
	if (ft_routine(&data))
	{
		ft_free_data(&data);
		return (1);
	}
	ft_free_data(&data);
	return (0);
}