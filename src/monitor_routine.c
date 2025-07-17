/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 18:05:51 by nyousfi           #+#    #+#             */
/*   Updated: 2025/07/17 09:17:19 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

bool	all_meals_reached(t_philo *philos)
{
	int	i;

	i = 0;
	pthread_mutex_lock(philos[0].meal_mutex);
	if (philos[0].meal_required == -1)
	{
		pthread_mutex_unlock(philos[0].meal_mutex);
		return (false);
	}
	pthread_mutex_unlock(philos[0].meal_mutex);
	while (i < philos[0].nb_philos)
	{
		pthread_mutex_lock(philos[i].meal_mutex);
		if (philos[i].meal_count >= philos[i].meal_required)
		{
			pthread_mutex_unlock(philos[i].meal_mutex);
			i++;
		}
		else
		{
			pthread_mutex_unlock(philos[i].meal_mutex);
			return (false);
		}
	}
	return (true);
}

void stop_routine(t_philo *philos)
{
	int	i;

	i = 0;
	pthread_mutex_lock(philos[0].philo_mutex);
	pthread_mutex_lock(philos[0].dead_mutex);
	while (i < philos[0].nb_philos)
	{
		philos[i].is_dead = true;
		i++;
	}
	pthread_mutex_unlock(philos[0].dead_mutex);
	pthread_mutex_unlock(philos[0].philo_mutex);
}
