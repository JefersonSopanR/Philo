#include "philo.h"

void ft_write(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

void	write_err(char *s)
{
	ft_write("Error: Invalid ", 2);
	ft_write(s, 2);
}

long	ft_atoi(const char *s)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*s == ' ' || *s == '\t' || *s == '\n' || \
			*s == '\r' || *s == '\f' || *s == '\v')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (ft_isdigit(*s))
		result = result * 10 + (*s++ - '0');
	return (result * sign);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

