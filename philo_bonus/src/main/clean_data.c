/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:33:31 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/05/04 15:03:13 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	clean_data(t_data *data)
{
	sem_close(data->sem_forks);
	sem_close(data->sem_print);
	sem_close(data->sem_data);
	sem_unlink("/data");
	sem_unlink("/fork");
	sem_unlink("/print");
}
