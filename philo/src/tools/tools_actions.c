/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsantand <nsantand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 14:08:26 by nsantand          #+#    #+#             */
/*   Updated: 2026/03/04 19:01:11 by nsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	philo_actions(t_table *table)
{
	
	pthread_create(&table->philos->thread, NULL, philo_routine, table->philos);
	
	pthread_join(table->philos->thread, NULL);

}

void *philo_routine(void *arg)
{
	t_philos *philo;

	philo = (t_philos*)arg;
	philo_is_eating(philo);
	release_forks(philo);
	philo_is_sleeping(philo);
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
		printf("[%ld] %d has taken a fork\n", (get_time_in_ms() - philo->table->start_time), philo->ids);
	else if(action == THINKING)
		printf("[%ld] %d is thinking\n", (get_time_in_ms() - philo->table->start_time), philo->ids);
	else if(action == EATING)
		printf("[%ld] %d is eating\n", (get_time_in_ms() - philo->table->start_time), philo->ids);
	else if(action == SLEEPING)
		printf("[%ld] %d is sleeping\n", (get_time_in_ms() - philo->table->start_time), philo->ids);
	else if(action == DEAD)
		printf("[%ld] %d is died\n", (get_time_in_ms() - philo->table->start_time), philo->ids);
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