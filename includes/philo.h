#ifndef PHILO_H
# define PHILO_H

# include "philo_utils.h"

//Validation
int	check_input(int ac, char **av);

//HELPERS
int			print_instructions(void);
int			ft_strlen(char *str);
int			ft_atoi(char *str);
void		init_philos(t_data *data);
void		init_forks(t_data *data);
void		init_data(t_data *data, int ac, char **av);
void		ft_error(char *message, int status);
void		clean_data(t_data *data);
void		update_last_meal_time(t_philo *philo);

//GETTERS
t_state		get_philo_state(t_philo *philo);
u_int64_t	get_time(void);

//SETTERS
void	set_philo_state(t_philo *philo, t_state state);

//MAIN
int			 eat(t_philo *philo);
void		*routine(void *philo_p);
void		*alive_monitoring(void *data_p);
void		*full_monitoring(void *data_p);
int 		philo_sleep(t_philo *philo);
int 		think(t_philo *philo);

#endif