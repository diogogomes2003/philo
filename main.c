#include "philo.h"

void	*lone_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->data->forks[0]);
	put_msg(philo, 'L');
	usleep(philo->data->time_to_die * 1000);
	put_msg(philo, 'D');
	pthread_mutex_unlock(&philo->data->forks[0]);
	return (NULL);
}

int	one_philo(t_global_var *data)
{
	int	i;

	i = 0;
	data->time_ms = start_time();
	data->all[i].last_eat = start_time();
	if (pthread_create(&(data->all[0].thread_philo), NULL,
			lone_philo, &data->all[0]))
	{
		clean_program(data, 3);
		return (-1);
	}
	philo_monitor(data);
	if (join_threads(data) == -1)
		printf("Error joining threads\n");
	clean_program(data, 3);
	return (0);
}

int	main(int ac, char **av)
{
	t_philo			*philo;
	t_global_var	data;

	if (ac == 5 || ac == 6)
	{
		if (data_init(&data, av) == -1)
			return (-1);
		if (philo_init(&philo, &data) == -1)
		{
			clean_program(&data, 0);
			return (-1);
		}
		if (mutex_init(&data) == -1)
			return (-1);
		if (data.nbr_phils == 1)
			one_philo(&data);
		else if (thread_init(&data) == -1)
		{
			clean_program(&data, 3);
			return (-1);
		}
	}
	else
		printf("Invalid number of arguments\n");
	return (0);
}