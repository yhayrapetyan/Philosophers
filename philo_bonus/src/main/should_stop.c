/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   should_stop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:44:48 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/04/30 17:46:42 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	should_stop(t_state	state)
{
	if (state == DEAD)
		return (1);
	if (state == FINISH)
		return (1);
	if (state == FULL)
		return (1);
	return (0);
}
