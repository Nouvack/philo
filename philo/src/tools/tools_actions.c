/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsantand <nsantand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 14:08:26 by nsantand          #+#    #+#             */
/*   Updated: 2026/03/06 19:35:54 by nsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	philo_actions(t_table *table)
{
	int i;

	i =  0;
	while(i < table->number_of_philosophers)
	{
		if(pthread_create(&table->philos[i].thread, NULL, philo_routine, &table->philos[i]) != 0)
			break;
		i++;
	}
	
	if(pthread_create(&table->monitor_thread, NULL, monitor_routine, table) != 0)
	{
		finish_threads(table);
		return;
	}
	finish_threads(table);
	
	
	
}

void finish_threads(t_table *table)
{
	int i;
	
	i =  0;
	if(table->monitor_thread)
		pthread_join(table->monitor_thread, NULL);
	if(table->philos)
	{
		while(i < table->number_of_philosophers)
		{
			pthread_join(table->philos[i].thread, NULL);
			i++;
		}
	}
	
}
bool philo_is_dead(t_philos *philo)
{
	pthread_mutex_lock(&philo->table->meal_mutex);
	
	if ((get_time_in_ms() - philo->last_meal) > philo->table->time_to_die)
	{
		pthread_mutex_lock(&philo->table->dead_mutex);
		philo->table->stop = true;
		pthread_mutex_unlock(&philo->table->dead_mutex);
		print_actions(philo, DEAD);
		pthread_mutex_unlock(&philo->table->meal_mutex);

		return(true);
	}
	pthread_mutex_unlock(&philo->table->meal_mutex);
	
	return(false);
}

bool check_stop(t_table * table)
{
	pthread_mutex_lock(&table->dead_mutex);
	if(table->stop == true)
		return(pthread_mutex_unlock(&table->dead_mutex), true);
	pthread_mutex_unlock(&table->dead_mutex);
	return(false);
}
void *monitor_routine(void *arg)
{
	t_table *table;
	int i;

	table = (t_table*)arg;
	while(1)
	{
		usleep(1000);
		i = 0;
		while(i < table->number_of_philosophers)
		{
			if(philo_is_dead(&table->philos[i]) == (true))
				return(NULL);
			i++;
		}
	}
	return(NULL);
}
void *philo_routine(void *arg)
{
	t_philos *philo;

	philo = (t_philos*)arg;
	while(1)
	{	
		if(check_stop(philo->table) == true)
			return(NULL);
		
		philo_is_eating(philo);
		release_forks(philo);
		philo_is_sleeping(philo);
		philo_is_thinking(philo);
	}
	return(NULL);
}

void	*philo_is_forkin(t_philos *philo)
{
	if (philo->ids % 2 == 1)
	{
		pthread_mutex_lock(philo->left_fork);
		print_actions(philo,FORKING);
		pthread_mutex_lock(philo->right_fork);
		print_actions(philo, FORKING);
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		print_actions(philo,FORKING);
		pthread_mutex_lock(philo->left_fork);
		print_actions(philo, FORKING);
	}
	return(NULL);
}

void release_forks(t_philos *philo)
{
	if(philo->left_fork)
		pthread_mutex_unlock(philo->left_fork);
	if(philo->right_fork)
		pthread_mutex_unlock(philo->right_fork);
}

void print_actions(t_philos *philo, int action)
{
	// if(check_stop(philo->table) == true && action != DEAD)
	// 	return;
	pthread_mutex_lock(&philo->table->print_mutex);
	if(action == FORKING)
		printf("[%ld] %d " COLOR_FORK, (get_time_in_ms() - philo->table->start_time), philo->ids);
	else if(action == THINKING)
		printf("[%ld] %d " COLOR_THINK, (get_time_in_ms() - philo->table->start_time), philo->ids);
	else if(action == EATING)
		printf("[%ld] %d " COLOR_EAT, (get_time_in_ms() - philo->table->start_time), philo->ids);
	else if(action == SLEEPING)
		printf("[%ld] %d "COLOR_SLEEP, (get_time_in_ms() - philo->table->start_time), philo->ids);
	else if(action == DEAD)
		printf("[%ld] %d " COLOR_DEAD, (get_time_in_ms() - philo->table->start_time), philo->ids);
	pthread_mutex_unlock(&philo->table->print_mutex);

}
void philo_is_eating(t_philos *philo)
{
	philo_is_forkin(philo);
	pthread_mutex_lock(&philo->table->meal_mutex);
	philo->number_eats++;
	philo->last_meal = get_time_in_ms();
	print_actions(philo, EATING);
	pthread_mutex_unlock(&philo->table->meal_mutex);
	usleep(philo->table->time_to_eat * 1000);
}
void philo_is_sleeping(t_philos *philo)
{
	print_actions(philo, SLEEPING);
	usleep(philo->table->time_to_sleep * 1000);
}
void philo_is_thinking(t_philos *philo)
{
	print_actions(philo, THINKING);
}