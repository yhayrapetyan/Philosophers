#ifndef PHILO_H
# define PHILO_H

# include "philo_utils.h"

//Validation
int	check_input(int ac, char **av);

//HELPERS
int			print_instructions(void);
u_int64_t	get_time(void);
int			ft_strlen(char *str);
int			ft_atoi(char *str);
void		init_philos(t_data *data);
void		init_forks(t_data *data);
void		init_data(t_data *data, int ac, char **av);
void		ft_error(char *message, int status);
void		*routine(void *data_p);
void		*alive_monitoring(void *data_p);
void		*full_monitoring(void *data_p);
void		clean_data(t_data *data);

#endif