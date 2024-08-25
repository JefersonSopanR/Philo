#include "philo.h"

int	ft_routine(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_count)
	{
		if (pthread_create(&data->philos[i].thread, NULL, ft_philo, &data->philos[i]))
			return (1);
		i++;
	}
	i = -1;
	while (++i < data->philo_count && !break_condition(data, &i))
		i = i + 0;
	i = 0;
	while (i < data->philo_count)
	{
		if (pthread_join(data->philos[i].thread, NULL))
			return (1);
		i++;
	}
	return (0);
}

void	*ft_philo(void *void_philo)
{
	t_philo	*philo;

	philo = (t_philo *)void_philo;
	if (philo->id % 2 == 0)
		ft_usleep(10);
	while (1)
	{
		if (ft_eat(philo))
			return (NULL);
		pthread_mutex_lock(&philo->data->checker);
		if (philo->meals_eaten == philo->data->must_eat_count && philo->data->must_eat_count != -1)
			philo->data->ate_count++;
		pthread_mutex_unlock(&philo->data->checker);
		pthread_mutex_unlock(&philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		if (ft_print_status(philo, "is sleeping"))
			return (NULL);
		ft_usleep(philo->data->time_to_sleep);
		if (ft_print_status(philo, "is thinking"))
			return (NULL);
	}
	return (NULL);
}

int	ft_eat(t_philo *philo)
{
	if (check_death(philo))
		return (1);
	pthread_mutex_lock(&philo->l_fork);
	if (ft_print_status(philo, "has taken a fork"))
		return (pthread_mutex_unlock(&philo->l_fork), 1);
	if (check_death(philo))
		return (1);
	pthread_mutex_lock(philo->r_fork);
	if (ft_print_status(philo, "has taken a fork"))
	{
		pthread_mutex_unlock(&philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		return (1);
	}
	pthread_mutex_lock(&philo->data->checker);
	philo->meals_eaten++;
	philo->last_meal_time = timestamp();
	pthread_mutex_unlock(&philo->data->checker);
	ft_print_status(philo, "is eating");
	ft_usleep(philo->data->time_to_eat);
	return (0);
}

int	check_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->checker);
	if (philo->data->is_dead || philo->data->all_ate)
	{
		pthread_mutex_unlock(&philo->data->checker);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->checker);
	return (0);
}

int break_condition(t_data *data, int *i)
{
	pthread_mutex_lock(&data->checker);
	if (timestamp() - data->philos[*i].last_meal_time >= data->time_to_die || data->ate_count == data->philo_count)
	{
		if (data->ate_count == data->philo_count && data->must_eat_count != -1)
		{
			data->all_ate = 1;
			pthread_mutex_unlock(&data->philos[*i].l_fork);
		}
		else
		{
			data->is_dead = 1;
			pthread_mutex_unlock(&data->philos[*i].l_fork);
			printf("%lli %d died\n", timestamp() - data->first_timestamp, data->philos[*i].id);
		}
		pthread_mutex_unlock(&data->checker);
		return (1);
	}
	if (*i == data->philo_count - 1)
		*i = -1;
	pthread_mutex_unlock(&data->checker);
	return (0);
}