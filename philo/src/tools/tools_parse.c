/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsantand <nsantand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 16:42:22 by nsantand          #+#    #+#             */
/*   Updated: 2026/02/27 18:34:25 by nsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo.h"


int j = 0;
pthread_mutex_t mutel;
pthread_mutex_t mutel2;
long get_time_in_ms(void)
{
    struct timeval time;

    gettimeofday(&time, NULL);
	printf("ESte es el momento de inicio: %ld", time.tv_sec);
	
    return (time.tv_sec * 1000L + time.tv_usec / 1000L);
}
void *printas(void *str)
{
	for(int i=0; i< 100000; i++)
	{
		pthread_mutex_lock(&mutel);
		j++;
		pthread_mutex_unlock(&mutel);
	}
	pthread_mutex_lock(&mutel2);
	
	printf("Este es el valor de i: %d\n", j);
	printf("Este es el valor de str: %s\n", (char* )str);
	pthread_mutex_unlock(&mutel2);
	
	return(NULL);
}
t_table create_table(char **nums)
{
	t_table table;

	table.number_of_philosophers = ft_atoi(nums[0]);
	table.time_to_die = ft_atoi(nums[1]);
	table.time_to_eat = ft_atoi(nums[2]);
	table.time_to_sleep = ft_atoi(nums[3]);
	if(ft_arraylen(nums) == 5)
		table.number_of_timmes_each_philosopher_must_eat = ft_atoi(nums[4]);
	else if (ft_arraylen(nums) == 4)
		table.number_of_timmes_each_philosopher_must_eat = -1;
	return(table);
	
}

void	*create_node(t_philos **lst, int content)
{
	t_philos	*new;

	new = ft_calloc(1, sizeof(t_philos));
	if (!new)
		return (NULL);
	new->ids = content;
	new->next = NULL;
	place_node(lst, new);
	return ((void *)0);
}

void	place_node(t_philos **lst, t_philos *new)
{
	t_philos	*current;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	current = *lst;
	while (current->next != NULL)
		current = current->next;
	current->next = new;
}


t_philos *create_philos(int number_philos)
{
	t_philos *philos;
	int i;
	
	i = 0;
	philos = NULL;
	while(i != number_philos)
	{
		create_node(&philos, i);
		i++;
	}
	return(philos);
}


void philos_actions()

bool parse_arguments(char **argv)
{
	char **nums;
	t_philos *philos;
	t_table table;

	
    nums = check_number(argv);
	if(!nums)
		return(false);
	table = create_table(nums);
	philos = create_philos(table.number_of_philosophers);
	t_philos *tmp = philos;

	while (tmp != NULL)
	{
		printf("id de los hilos: %d\n", tmp->ids);
		tmp = tmp->next;
	}

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
	
	return(true);
}
