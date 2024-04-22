/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_number_meals_had.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:51:03 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/04/22 13:51:06 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	update_number_meals_had(t_philo *philo)
{
	pthread_mutex_lock(&philo->mut_meals_had);
	philo->meals_had++;
	pthread_mutex_unlock(&philo->mut_meals_had);
}
