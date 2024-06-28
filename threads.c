/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduarte- <dduarte-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 08:26:35 by dduarte-          #+#    #+#             */
/*   Updated: 2024/06/28 08:26:35 by dduarte-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	join_threads(t_global_var *data)
{
	int	i;

	i = 0;
	while (i < data->nbr_phils)
	{
		if (pthread_join(data->all[i].thread_philo, NULL))
			return (-1);
		i++;
	}
	return (0);
}

int	thread_init(t_global_var *data)
{
	int	i;

	i = 0;
	data->time_ms = start_time();
	while (i < data->nbr_phils)
	{
		data->all[i].last_eat = start_time();
		if (pthread_create(&(data->all[i].thread_philo), NULL,
				thread_start, &data->all[i]))
		{
			clean_program(data, 3);
			return (-1);
		}
		i++;
	}
	philo_monitor(data);
	if (join_threads(data) == -1)
		printf("Error joining threads\n");
	clean_program(data, 3);
	return (0);
}
