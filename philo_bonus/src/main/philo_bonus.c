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

static int	start_processes(t_data *data)
{
	pid_t	pid;
	int		i;

	i = 0;
	data->start_time = get_time();
	while (i < data->nb_philos)
	{
		pid = fork();
		if (pid == 0)
		{
			routine(data, i + 1);
			return (0);
		}
		else if (pid == -1)
		{
			clean_data(data, 0);//id!!!!
			ft_error("Fork failed\n", 17);
		}
		i++;
	}
	pid = waitpid(0, NULL, 0);
	while (pid != -1)
		pid = waitpid(0, NULL, 0);
	return (1);
}

int	main(int ac, char **av)
{
	t_data	data;
	int		process_id;

	if (check_input(ac, av) != 0)
		return (print_instructions());
	if (init_data(&data, ac, av) != 0)
		return (1);
	process_id = start_processes(&data);
	clean_data(&data, process_id);
	return (0);
}
