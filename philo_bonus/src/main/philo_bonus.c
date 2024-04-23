#include "philo_bonus.h"

static void	start_processes(t_data *data)
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
			routine(data, i);
			return ;
		}
		else if (pid == -1)
		{
			clean_data(data);
			ft_error("Fork failed\n", 17);
		}
		i++;
	}
	pid = waitpid(0, NULL, 0);
	while (pid != -1)
		pid = waitpid(0, NULL, 0);
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
