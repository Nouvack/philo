/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsantand <nsantand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 16:54:11 by nsantand          #+#    #+#             */
/*   Updated: 2026/03/07 15:56:15 by nsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philos_is_full(t_table *table)
{
	int	i;
	int	philos_full;

	i = 0;
	philos_full = 0;
	if (table->number_of_timmes_each_philosopher_must_eat != -1)
	{
		while (i < table->number_of_philosophers)
		{
			pthread_mutex_lock(&table->meal_mutex);
			if (table->philos[i].number_eats
				>= table->number_of_timmes_each_philosopher_must_eat)
				philos_full++;
			pthread_mutex_unlock(&table->meal_mutex);
			i++;
		}
		if (philos_full == table->number_of_philosophers)
		{
			pthread_mutex_lock(&table->dead_mutex);
			table->stop = true;
			pthread_mutex_unlock(&table->dead_mutex);
			return (NULL);
		}
	}
	return ((void *)1);
}

void	*monitor_routine(void *arg)
{
	t_table	*table;
	int		i;

	table = (t_table *)arg;
	while (1)
	{
		ft_usleep(1, table);
		i = 0;
		while (i < table->number_of_philosophers)
		{
			if (!philos_is_full(table))
				return (NULL);
			if (philo_is_dead(&table->philos[i]) == (true))
				return (NULL);
			i++;
		}
	}
	return (NULL);
}

void	*philo_routine(void *arg)
{
	t_philos	*philo;

	philo = (t_philos *)arg;
	while (1)
	{
		if (check_stop(philo->table) == true)
			return (NULL);
		if (!philo_is_eating(philo))
			break ;
		release_forks(philo);
		if (!philo_is_sleeping(philo))
			break ;
		if (!philo_is_thinking(philo))
			break ;
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		printf("hola");
		return (1);
	}
	if (!begin_program(argv))
	{
		printf("ERROR");
		return (1);
	}
	return (0);
}
