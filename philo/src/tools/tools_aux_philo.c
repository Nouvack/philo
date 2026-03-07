/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_aux_philo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsantand <nsantand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 15:21:11 by nsantand          #+#    #+#             */
/*   Updated: 2026/03/07 15:24:43 by nsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(unsigned time, t_table *table)
{
	unsigned long	start;
	unsigned long	end;
	unsigned long	current;

	start = get_time_in_ms();
	end = start + time;
	while (1)
	{
		current = get_time_in_ms();
		if (current >= end || check_stop(table) == true)
			break ;
		else
			usleep(200);
	}
}

void	finish_threads(t_table *table)
{
	int	i;

	i = 0;
	if (table->monitor_thread)
		pthread_join(table->monitor_thread, NULL);
	if (table->philos)
	{
		while (i < table->number_of_philosophers)
		{
			pthread_join(table->philos[i].thread, NULL);
			i++;
		}
	}
}

bool	check_stop(t_table *table)
{
	pthread_mutex_lock(&table->dead_mutex);
	if (table->stop == true)
		return (pthread_mutex_unlock(&table->dead_mutex), true);
	pthread_mutex_unlock(&table->dead_mutex);
	return (false);
}

void	print_actions(t_philos *philo, int action)
{
	if (check_stop(philo->table) == true && action != DEAD)
		return ;
	pthread_mutex_lock(&philo->table->print_mutex);
	if (action == FORKING)
		printf("[%ld] %d " COLOR_FORK, (get_time_in_ms()
				- philo->table->start_time), philo->ids);
	else if (action == THINKING)
		printf("[%ld] %d " COLOR_THINK, (get_time_in_ms()
				- philo->table->start_time), philo->ids);
	else if (action == EATING)
		printf("[%ld] %d " COLOR_EAT, (get_time_in_ms()
				- philo->table->start_time), philo->ids);
	else if (action == SLEEPING)
		printf("[%ld] %d " COLOR_SLEEP, (get_time_in_ms()
				- philo->table->start_time), philo->ids);
	else if (action == DEAD)
		printf("[%ld] %d " COLOR_DEAD, (get_time_in_ms()
				- philo->table->start_time), philo->ids);
	pthread_mutex_unlock(&philo->table->print_mutex);
}

void	philo_actions(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->number_of_philosophers)
	{
		if (pthread_create(&table->philos[i].thread, NULL, philo_routine,
				&table->philos[i]) != 0)
			break ;
		i++;
	}
	if (pthread_create(&table->monitor_thread, NULL, monitor_routine,
			table) != 0)
	{
		finish_threads(table);
		return ;
	}
	finish_threads(table);
}