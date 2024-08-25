#include "philo.h"

int	ft_check_args(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
			{
				write_err("arguments\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_init_data(t_data *data, char **av)
{
	data->philo_count = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	data->must_eat_count = -1;
	if (av[5])
	{
		data->must_eat_count = ft_atoi(av[5]);
		if (data->must_eat_count < 0)
			return (write_err("number of meals\n"), 1);
	}
	if (data->philo_count < 2 || data->philo_count > 200)
		return (write_err("number of philosophers\n"), 1);
	if (data->time_to_die < 0)
		return (write_err("time to die\n"), 1);
	if (data->time_to_eat < 0)
		return (write_err("time to eat\n"), 1);
	pthread_mutex_init(&data->checker, NULL);
	data->first_timestamp = timestamp();
	return (0);
}

int	ft_init_philos(t_data *data)
{
	int	i;
	int	j;


	j = data->philo_count;
	i = 0;
	while (i < data->philo_count)
	{
		data->philos[i].id = i + 1;
		data->philos[i].data = data;
		data->philos[i].last_meal_time = data->first_timestamp;
		pthread_mutex_init(&data->philos[i].l_fork, NULL);
		data->philos[i].r_fork = &data->philos[(i + 1) % j].l_fork;
		i++;
	}
	return (0);
}

int	ft_init(t_data *data, char **av)
{
	if (ft_check_args(av))
		return (1);
	if (ft_init_data(data, av))
		return (1);
	if (ft_init_philos(data))
		return (1);
	return (0);
}
