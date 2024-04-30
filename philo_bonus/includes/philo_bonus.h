/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:32:09 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/04/30 16:32:09 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include "philo_bonus_utils.h"

//Validation
int			check_input(int ac, char **av);

//HELPERS
int			print_message(t_data *data, char *message);
char		*ft_strjoin(char *s1, char *s2);
void		ft_error(char *message, int status);
void		ft_usleep(uint64_t sleep_time);
int			print_instructions(void);
int			ft_strlen(char *str);
int			ft_atoi(char *str);
char		*ft_itoa(int n);

//SETTERS
void		set_philo_state(t_data *data, t_state state);
void		update_last_meal_time(t_data *data);

//GETTERS
uint64_t	get_last_eat_time(t_data *data);
t_state		get_philo_state(t_data *data);
uint64_t	get_start_time(t_data *data);
uint64_t	get_die_time(t_data *data);
u_int64_t	get_time(void);

//MAIN
int			init_data(t_data *data, int ac, char **av);
char		*init_philo(t_data *data, int id);
void		clean_data(t_data *data, int process_id);
int			routine(t_data *data, int id);
void		*alive_monitoring(void *data_p);
int			should_stop(t_state	state);
int			philo_sleep(t_data *data);
int			take_forks(t_data *data);
int			drop_forks(t_data *data);
int			think(t_data *data);
int			someone_died(void);
int			eat(t_data *data);

#endif
