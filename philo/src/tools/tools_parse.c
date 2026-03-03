/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsantand <nsantand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 16:42:22 by nsantand          #+#    #+#             */
/*   Updated: 2026/03/03 18:07:48 by nsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time_in_ms(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	printf("ESte es el momento de inicio: %ld", time.tv_sec);
	return (time.tv_sec * 1000L + time.tv_usec / 1000L);
}

t_table	*create_table(char **nums)
{
	t_table	*table;

	table = ft_calloc(1, sizeof(t_table));
	if (!table)
		return (NULL);
	table->start_time = get_time_in_ms();
	table->number_of_philosophers = ft_atoi(nums[0]);
	table->time_to_die = ft_atoi(nums[1]);
	table->time_to_eat = ft_atoi(nums[2]);
	table->time_to_sleep = ft_atoi(nums[3]);
	if (ft_arraylen(nums) == 5)
		table->number_of_timmes_each_philosopher_must_eat = ft_atoi(nums[4]);
	else if (ft_arraylen(nums) == 4)
		table->number_of_timmes_each_philosopher_must_eat = -1;
	table->forks = create_forks(table);
	if (!table->forks)
		return (NULL);
	return (table);
}

pthread_mutex_t	*create_forks(t_table *table)
{
	int	i;

	i = 0;
	table->forks = ft_calloc(sizeof(pthread_mutex_t),
			table->number_of_philosophers);
	if (!table->forks)
		return (NULL);
	while (i != table->number_of_philosophers)
	{
		pthread_mutex_init(table->forks, NULL);
		i++;
	}
	return (table->forks);
}

bool create_philos(t_table *table)
{
	int i;
	
	i = 0;
	table->philos = ft_calloc(table->number_of_philosophers ,sizeof(t_philos ));
	if(!table->philos)
		return(false);
	while(i < table->number_of_philosophers)
	{
		table->philos[i].ids = i;
		table->philos[i].last_meal = get_time_in_ms();
		table->philos[i].left_fork = &table->forks[i];
		table->philos[i].right_fork = &table->forks[(i + 1) % table->number_of_philosophers];
		table->philos[i].number_eats = 0;
		table->philos[i].table = table;
		i++;
	}
	return(true);
}

bool	begin_program(char **argv)
{
	char		**nums;
	t_table		*table;

	nums = check_number(argv);
	if (!nums)
		return (false);
	table = create_table(nums);
	if (!table)
		return (false);
	create_philos(table);
	philo_actions(table);
	// t_philos *tmp = philos;
	// pthread_t hilo;
	// pthread_t hilo2;
	// size_t i = 0;
	// while(i < ft_arraylen(nums))
	// {
	// 	printf("este es el nummero: %s\n",  nums[i]);
	// 	i++;
	// }
	// get_time_in_ms();
	// pthread_mutex_init(&mutel, NULL);
	// pthread_mutex_init(&mutel2, NULL);
	// pthread_create(&hilo, NULL, printas, "hola");
	// pthread_create(&hilo2, NULL, printas, "hola");
	// //aprender de los mutex
	// pthread_join(hilo, NULL);
	// pthread_join(hilo2, NULL);
	// pthread_mutex_destroy(&mutel);
	// pthread_mutex_destroy(&mutel2);
	return (true);
}
