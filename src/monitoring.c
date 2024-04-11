#include "philo.h"

void	*alive_monitoring(void *data_p)
{
	(void)data_p;
	printf("alive monitoring\n");
	return (NULL);
}

void	*full_monitoring(void *data_p)
{
	(void)data_p;
	printf("full monitoring\n");
	return (NULL);
}