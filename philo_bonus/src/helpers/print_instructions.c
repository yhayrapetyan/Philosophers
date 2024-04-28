#include "philo_bonus.h"

int	print_instructions(void)
{
	printf( RED);
	printf("\t\tWRONG INPUT!\n\n");
	printf( YELLOW);
	printf("./philo nb_philos die_t ");
	printf("eat_t sleep_t ");
	printf("[nb_meals]\n\n");
	printf("Example:\n");
	printf("\t./philo 4 800 200 200 5\n\n");
	printf( GREEN);
	printf("nb_philos: 1-200\n");
	printf("time_to_die: 60+\n");
	printf("time_to_eat: 60+\n");
	printf("time_to_sleep: 60+\n");
	printf("nb_of_times_each_philo_must_eat: 0+\n");
	printf( RESET_COLOR);
	return (1);
}