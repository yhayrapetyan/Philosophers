#include "philo.h"

static int	check_args(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac == 6 && ft_atoi(av[5]) <= 0)
		return (1);
	if (ft_atoi(av[i]) < 1 || ft_atoi(av[i]) > 200)
		return (1);
	while (++i < 5)
	{
		if (ft_atoi(av[i]) < 60)
			return (1);
	}
	return (0);
}

static int	is_digit(int ac, char **av)
{
	int	i;
	int	k;

	i = 1;
	while (i < ac)
	{
		k = 0;
		while (av[i][k] != '\0')
		{
			if (av[i][k] < '0' || av[i][k] > '9')
				return (1);
			k++;
		}
		i++;
	}
	return (0);
}

int	check_input(int ac, char **av)
{
	(void)av;
	if (ac > 6 || ac < 5)
		return (1);
	if (is_digit(ac, av) != 0)
		return (1);
	if (check_args(ac, av) != 0)
		return (1);
	return (0);
}