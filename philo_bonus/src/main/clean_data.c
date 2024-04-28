#include "philo_bonus.h"

void	clean_data(t_data *data, int process_id)
{
	sem_close(data->sem_forks);
	sem_close(data->sem_print);
	sem_close(data->sem_data);
	(void)process_id;
//	if (process_id == 1)
//		sem_unlink("/death");
	sem_unlink("/data");
	sem_unlink("/fork");
	sem_unlink("/print");
}
