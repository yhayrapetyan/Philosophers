/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:42:01 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/04/30 16:42:01 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	wait_for_philos(t_data *data)
{
	int	i;
	int	exit;

	i = -1;
	while (++i <= data->nb_philos)
	{
		waitpid(-1, &exit, 0);
		if (((exit >> 8) & 0xFF) > 0)
		{
			i = -1;
			while (++i < data->nb_philos)
				kill(data->philos[i], SIGKILL);
			break ;
		}
	}
}

static int	start_processes(t_data *data)
{
	int		i;

	i = 0;
	data->start_time = get_time();
	while (i < data->nb_philos)
	{
		data->philos[i] = fork();
		if (data->philos[i] == 0)
		{
			routine(data, i + 1);
			return (0);
		}
		else if (data->philos[i] == -1)
		{
			clean_data(data);
			ft_error("Fork failed\n", 17);
		}
		i++;
	}
	wait_for_philos(data);
	return (1);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (check_input(ac, av) != 0)
		return (print_instructions());
	if (init_data(&data, ac, av) != 0)
		return (1);
	start_processes(&data);
	clean_data(&data);
	return (0);
}
