/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:33:31 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/04/30 16:33:32 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	clean_data(t_data *data, int process_id)
{
	sem_close(data->sem_forks);
	sem_close(data->sem_print);
	sem_close(data->sem_data);
	(void)process_id;
//	if (process_id == 1)
//		sem_unlink("/death");
	sem_unlink("/data");
	sem_unlink("/fork");
	sem_unlink("/print");
}
