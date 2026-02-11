/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsantand <nsantand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 15:14:20 by nsantand          #+#    #+#             */
/*   Updated: 2026/02/11 17:38:10 by nsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H



# include <stdio.h>

typedef struct s_restaurant
{
    size_t number_of_philosophers;
    size_t time_to_die;
    size_t time_to_eat;
    size_t time_to_sleep;
    size_t number_of_timmes_each_philosopher_must_eat;
} t_restaurant;

typedef struct s_philos
{
    char* name;
} t_philos;

typedef struct s_table
{
    char* name;
} t_table;

#endif  