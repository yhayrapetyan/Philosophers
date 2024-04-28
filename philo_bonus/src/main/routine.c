#include "philo_bonus.h"

int	should_stop(t_state	state)
{
	if (state == DEAD)
		return (1);
	if (state == FINISH)
		return (1);
	if (state == FULL)
		return (1);
	return (0);
}

int	routine(t_data *data, int id, int pid)
{
	char	*philo_id;
	// printf("✅✅✅ i = %d\n", id);

	philo_id = init_philo(data, id);
	if (data->philo.id % 2 == 0)
		ft_usleep(data->eat_time);
	if (pthread_create(&data->monitor, NULL, &alive_monitoring, data))
	{
		clean_data(data, 0);//id!!
		ft_error("Thread create failed\n", 19);
	}
	while (!someone_died())
	{
		if (eat(data) || should_stop(get_philo_state(data)))
			break ;
		if (philo_sleep(data) || should_stop(get_philo_state(data)))
			break ;
		if (think(data) || should_stop(get_philo_state(data)))
			break ;
	}
	if (pthread_join(data->monitor, NULL))
	{
		clean_data(data, 0);//id~~
		ft_error("Thread join failed\n", 19);
	}
	int state = get_philo_state(data);
	sem_close(data->philo.sem_philo);
	sem_unlink(philo_id);
	free(philo_id);
	printf("END ROUTINE id = %d\n", pid);
	if (state == DEAD) {
		return (1);
	}
	return (0);
}
