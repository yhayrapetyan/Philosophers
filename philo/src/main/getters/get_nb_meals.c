/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nb_meals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:49:51 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/04/22 13:49:53 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_nb_meals(t_data *data)
{
	int	nb_meals;

	pthread_mutex_lock(&data->mut_nb_meals);
	nb_meals = data->nb_meals;
	pthread_mutex_unlock(&data->mut_nb_meals);
	return (nb_meals);
}
