/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:33:56 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/04/30 16:34:01 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	philo_sleep(t_data *data)
{
	set_philo_state(data, SLEEPING);
	if (print_message(data, SLEEP))
		return (1);
	ft_usleep(data->sleep_time);
	return (0);
}
