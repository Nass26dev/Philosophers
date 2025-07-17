/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:39:28 by nyousfi           #+#    #+#             */
/*   Updated: 2025/07/17 09:13:54 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

void create_philos(t_data *data, int argc, char **argv)
{
	int i;

	i = 0;
	while (i < data->nb_philos)
	{
		data->philo[i].id = i + 1;
		data->philo[i].times.die = ft_atoll(argv[2]);
		data->philo[i].times.eat = ft_atoll(argv[3]);
		data->philo[i].times.sleep = ft_atoll(argv[4]);
		if (argc == 6)
			data->philo[i].meal_required = ft_atoll(argv[5]);
		else
			data->philo[i].meal_required = -1;
		data->philo[i].last_meal = 0;
		data->philo[i].start_time = 0;
		data->philo[i].meal_count = 0;
		data->philo[i].is_dead = false;
		data->philo[i].nb_philos = data->nb_philos;
		data->philo[i].left_fork = &data->forks[i];
		data->philo[i].right_fork = &data->forks[(i + 1) % data->nb_philos];
		data->philo[i].print_mutex = &data->print_mutex;
		data->philo[i].dead_mutex = &data->dead_mutex;
		data->philo[i].meal_mutex = &data->meal_mutex;
		data->philo[i].time_mutex = &data->time_mutex;
		data->philo[i].philo_mutex = &data->philo_mutex;
		data->philo[i].l_fork = &data->bool_forks[i];
		data->philo[i].r_fork = &data->bool_forks[(i + 1) % data->nb_philos];
		*(data->philo[i].l_fork) = false;
		*(data->philo[i].r_fork) = false;
		i++;
	}
}
