/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsantand <nsantand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 14:08:26 by nsantand          #+#    #+#             */
/*   Updated: 2026/03/03 19:06:43 by nsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	philo_actions(t_table *table)
{
	
	pthread_create(&table->philos->thread, NULL, philo_is_eating, table->philos);
	
	pthread_join(table->philos->thread, NULL);

}

void	*philo_is_eating(void *arg)
{
	t_philos *philo;

	philo = (t_philos*)arg;
	pthread_mutex_lock(philo->left_fork);
	write(1, "HAS TAKEN A FORK\n", 17);
	pthread_mutex_lock(philo->right_fork);
	write(1, "HAS TAKEN A FORK\n", 17);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	return(NULL);
}