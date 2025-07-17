/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 17:35:10 by nyousfi           #+#    #+#             */
/*   Updated: 2025/07/17 09:37:23 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_step(t_philo *philo, char *color, char *step)
{
	pthread_mutex_lock(philo->dead_mutex);
	if (*(philo->is_dead))
	{
		pthread_mutex_unlock(philo->dead_mutex);
		return ;
	}
	pthread_mutex_unlock(philo->dead_mutex);
	pthread_mutex_lock(philo->print_mutex);
	printf("%s%ld%s %d %s%s%s\n", PURPLE, get_current_time_ms()
		- philo->start_time, RESET, philo->id, color, step, RESET);
	pthread_mutex_unlock(philo->print_mutex);
}

void	usleep_loop(long time_to_sleep)
{
	long	start_time;

	start_time = get_current_time_ms();
	while (get_current_time_ms() - start_time < time_to_sleep)
		usleep(10);
}
