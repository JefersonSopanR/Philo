#include "philo.h"

long long	timestamp(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

void	ft_usleep(int ms)
{
	long int	time;

	time = timestamp();
	while (timestamp() - time < ms)
		usleep(333);
}

int	ft_print_status(t_philo *philo, char *status)
{
	pthread_mutex_lock(&(philo->data->checker));
	if (philo->data->is_dead || philo->data->all_ate)
	{
		pthread_mutex_unlock(&(philo->data->checker));
		return (1);
	}
	printf("%lli ", timestamp() - philo->data->first_timestamp);
	printf("%d %s\n", philo->id, status);
	pthread_mutex_unlock(&(philo->data->checker));
	return (0);
}

