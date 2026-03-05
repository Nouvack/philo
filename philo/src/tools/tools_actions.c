/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsantand <nsantand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 14:08:26 by nsantand          #+#    #+#             */
/*   Updated: 2026/03/05 18:24:53 by nsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>
void table_actions(t_table *table)
{

}
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
	i =  0;
	while(i < table->number_of_philosophers)
	{
		pthread_join(table->philos[i].thread, NULL);
		i++;
	}
	
}
bool philo_is_dead(t_philos *philo)
{
	if ((get_time_in_ms() - philo->last_meal) > philo->table->time_to_die)
	{
		print_actions(philo, DEAD);
		return(true);
	}
	return(false);
}
void *philo_routine(void *arg)
{
	t_philos *philo;

	philo = (t_philos*)arg;
	while(1)
	{
		if(philo_is_dead(philo) == (true))
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
	pthread_mutex_lock(philo->left_fork);
	print_actions(philo,FORKING);
	// write(1, "HAS TAKEN A FORK\n", 17);
	pthread_mutex_lock(philo->right_fork);
	// write(1, "HAS TAKEN A FORK\n", 17);
	print_actions(philo, FORKING);
	
	return(NULL);
}

void release_forks(t_philos *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void print_actions(t_philos *philo, int action)
{

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