#include "philo_bonus.h"

int	think(t_data *data)
{
	if (print_message(data, THINK))
		return (1);
	return (0);
}
