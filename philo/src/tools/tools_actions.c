/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsantand <nsantand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 14:08:26 by nsantand          #+#    #+#             */
/*   Updated: 2026/03/02 18:23:40 by nsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	philo_actions(t_table *table)
{
	while (true)
	{
		table;
	}
}

void	philo_is_eating(t_philos *philo)
{
	pthread_mutex_lock(philo->left_fork);
	write(1, "HAS TAKEN A FORK", 17);
	pthread_mutex_lock(philo->right_fork);
	write(1, "HAS TAKEN A FORK", 17);
}