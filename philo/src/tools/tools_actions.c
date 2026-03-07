/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsantand <nsantand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 14:08:26 by nsantand          #+#    #+#             */
/*   Updated: 2026/03/07 15:27:56 by nsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>








void	*philo_is_forkin(t_philos *philo)
{
	if (check_stop(philo->table) == true)
		return (NULL);
	if (philo->ids % 2 == 1)
	{
		pthread_mutex_lock(philo->left_fork);
		print_actions(philo, FORKING);
		pthread_mutex_lock(philo->right_fork);
		print_actions(philo, FORKING);
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		print_actions(philo, FORKING);
		pthread_mutex_lock(philo->left_fork);
		print_actions(philo, FORKING);
	}
	return ((void *)1);
}

void	release_forks(t_philos *philo)
{
	if (philo->left_fork)
		pthread_mutex_unlock(philo->left_fork);
	if (philo->right_fork)
		pthread_mutex_unlock(philo->right_fork);
}


void	*philo_is_eating(t_philos *philo)
{
	if (check_stop(philo->table) == true)
		return (NULL);
	philo_is_forkin(philo);
	pthread_mutex_lock(&philo->table->meal_mutex);
	philo->number_eats++;
	philo->last_meal = get_time_in_ms();
	print_actions(philo, EATING);
	pthread_mutex_unlock(&philo->table->meal_mutex);
	ft_usleep(philo->table->time_to_eat, philo->table);
	return ((void *)1);
}
void	*philo_is_sleeping(t_philos *philo)
{
	if (check_stop(philo->table) == true)
		return (NULL);
	print_actions(philo, SLEEPING);
	ft_usleep(philo->table->time_to_sleep, philo->table);
	return ((void *)1);
}
void	*philo_is_thinking(t_philos *philo)
{
	if (check_stop(philo->table) == true)
		return (NULL);
	print_actions(philo, THINKING);
	return ((void *)1);
}