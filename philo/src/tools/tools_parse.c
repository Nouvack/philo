/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsantand <nsantand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 16:42:22 by nsantand          #+#    #+#             */
/*   Updated: 2026/02/23 18:25:08 by nsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo.h"


int j = 0;

void *printas(void *str)
{
	for(int i=0; i< 100000; i++)
	{
		j++;
	}
	printf("Este es el valor de i: %d\n", j);
	printf("Este es el valor de str: %s\n", (char* )str);
	return(NULL);
}
t_restaurant create_restaurant(char **nums)
{
	t_restaurant restaurant;

	restaurant.number_of_philosophers = ft_atoi(nums[0]);
	restaurant.time_to_die = ft_atoi(nums[1]);
	restaurant.time_to_eat = ft_atoi(nums[2]);
	restaurant.time_to_sleep = ft_atoi(nums[3]);
	if(ft_arraylen(nums) == 5)
		restaurant.number_of_timmes_each_philosopher_must_eat = ft_atoi(nums[4]);
	else if (ft_arraylen(nums) == 4)
		restaurant.number_of_timmes_each_philosopher_must_eat = -1;
	return(restaurant);
	
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


bool parse_arguments(char **argv)
{
	char **nums;
	t_philos *philos;
	t_restaurant restaurant;

	
    nums = check_number(argv);
	if(!nums)
		return(false);
	restaurant = create_restaurant(nums);
	philos = create_philos(restaurant.number_of_philosophers);


	// size_t i = 0;
	// while(i < ft_arraylen(nums))
	// {
	// 	printf("este es el nummero: %s\n",  nums[i]);
	// 	i++;
	// }
	// pthread_create(&hilo, NULL, printas, "hola");
	// pthread_create(&hilo2, NULL, printas, "hola");
	// //aprender de los mutex
	// pthread_join(hilo, NULL);
	// pthread_join(hilo2, NULL);
	
	
	return(true);
}
