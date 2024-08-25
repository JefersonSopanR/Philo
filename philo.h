#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/time.h>
# include <limits.h>

typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	long long		last_meal_time;
	pthread_t		thread;
	pthread_mutex_t	l_fork;
	pthread_mutex_t	*r_fork;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	int				philo_count;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_count;
	int				ate_count;
	int				is_dead;
	int				all_ate;
	long long		first_timestamp;
	struct s_philo	philos[200];
	pthread_mutex_t	checker;
}	t_data;

int	ft_init(t_data *data, char **av);
int	ft_init_philos(t_data *data);
int	ft_init_data(t_data *data, char **av);
int	ft_check_args(char **av);
int	ft_free_data(t_data *data);
int	ft_print_status(t_philo *philo, char *status);
void	ft_usleep(int ms);
long long	timestamp(void);
int break_condition(t_data *data, int *i);
int	check_death(t_philo *philo);
int	ft_eat(t_philo *philo);
int	ft_routine(t_data *data);
void *ft_philo(void *philo);
void	ft_write(char *s, int fd);
void	write_err(char *s);
long	ft_atoi(const char *s);
int	ft_isdigit(int c);
int	ft_strlen(const char *s);

#endif
