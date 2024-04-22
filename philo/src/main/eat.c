/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:51:31 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/04/22 13:51:33 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	eat(t_philo *philo)
{
	if (take_forks(philo) != 0)
		return (1);
	set_philo_state(philo, EATING);
	print_message(philo->data, philo->id, EAT);
	update_last_meal_time(philo);
	ft_usleep(get_eat_time(philo->data));
	update_number_meals_had(philo);
	drop_forks(philo);
	return (0);
}
