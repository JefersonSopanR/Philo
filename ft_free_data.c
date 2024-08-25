#include "philo.h"

int	ft_free_data(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_count)
	{
		pthread_mutex_destroy(&data->philos[i].l_fork);
		i++;
	}
	return (0);
}
