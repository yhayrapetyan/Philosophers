/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:28:26 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/04/30 16:29:35 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_error(char *message, int status)
{
	write(2, RED, 7);
	write(2, "Error\n", 6);
	write(2, YELLOW, 7);
	write(2, message, ft_strlen(message));
	write(2, RESET_COLOR, 4);
	exit(status);
}
