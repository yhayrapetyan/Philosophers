/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:52:21 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/04/22 13:52:23 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *philo_p)
{
	t_philo	*philo;

	philo = (t_philo *)philo_p;
	update_last_meal_time(philo);
	if (philo->id % 2 == 0)
		ft_usleep(get_eat_time(philo->data));
	while (get_philo_state(philo) != DEAD)
	{
		eat(philo);
		print_message(philo->data, philo->id, SLEEP);
		ft_usleep(get_sleep_time(philo->data));
		print_message(philo->data, philo->id, THINK);
		// if (eat(philo) != 0)
		// 	break ;
		// if (philo_sleep(philo) != 0)
		// 	break ;
		// if (think(philo) != 0)
		// 	break ;
	}
	return (NULL);
}
