/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:47:01 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/04/22 13:47:02 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "philo_utils.h"

//Validation
int			check_input(int ac, char **av);

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

//GETTERS
uint64_t	get_last_eat_time(t_philo *philo);
t_state		get_philo_state(t_philo *philo);
u_int64_t	get_sleep_time(t_data *data);
u_int64_t	get_start_time(t_data *data);
int			get_nb_philos(t_data *data);
uint64_t	get_die_time(t_data *data);
u_int64_t	get_eat_time(t_data *data);
int			get_nb_meals(t_data *data);
int			can_iterate(t_data *data);
int			can_print(t_data *data);
u_int64_t	get_time(void);

//SETTERS
void		set_philo_state(t_philo *philo, t_state state);
void		update_number_meals_had(t_philo *philo);
void		update_last_meal_time(t_philo *philo);

//MAIN
int			take_right_fork(t_philo *philo);
void		*alive_monitoring(void *data_p);
void		*full_monitoring(void *data_p);
int			take_left_fork(t_philo *philo);
void		stop_processes(t_data *data);
int			philo_sleep(t_philo *philo);
int			take_forks(t_philo *philo);
void		drop_forks(t_philo *philo);
int			philo_died(t_philo *philo);
void		*routine(void *philo_p);
int			think(t_philo *philo);
int			eat(t_philo *philo);

#endif
