
#ifndef PHILO_BONUS_H
#define PHILO_BONUS_H

# include "philo_bonus_utils.h"

//Validation
int	check_input(int ac, char **av);

//HELPERS
void		print_message(t_data *data, int id, char *message);
void		init_data(t_data *data, int ac, char **av);
void		ft_error(char *message, int status);
void		ft_usleep(uint64_t sleep_time);
void		init_philos(t_data *data);
int			print_instructions(void);
void		init_forks(t_data *data);
void		clean_data(t_data *data);
int			ft_strlen(char *str);
int			ft_atoi(char *str);

#endif
