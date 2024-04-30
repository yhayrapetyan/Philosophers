/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   someone_died.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:43:32 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/04/30 17:43:53 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	someone_died(void)
{
	sem_t	*death;

	death = sem_open("/death", AT_EACCESS, 0644, 0);
	if (death == SEM_FAILED)
		return (0);
	sem_close(death);
	return (1);
}
