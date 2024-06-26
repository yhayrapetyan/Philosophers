/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:47:01 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/05/02 19:18:16 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "philo_utils.h"

//Validation
int			check_input(int ac, char **av);

//HELPERS
void		print_message(t_data *data, int id, char *message);
int			ft_error(char *message);
void		ft_usleep(uint64_t sleep_time);
int			print_instructions(void);
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
int			init_data(t_data *data, int ac, char **av);
int			alive_monitoring(t_data *data);
int			full_monitoring(t_data *data);
void		stop_processes(t_data *data);
void		init_philos(t_data *data);
void		init_forks(t_data *data);
void		clean_data(t_data *data);
void		*routine(void *philo_p);
int			eat(t_philo *philo);

#endif
