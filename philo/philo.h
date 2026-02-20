/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsantand <nsantand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 15:14:20 by nsantand          #+#    #+#             */
/*   Updated: 2026/02/20 16:59:38 by nsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H



# include <stdio.h>
# include <limits.h>
# include <stdlib.h> 
# include <unistd.h>
#include <stdbool.h>
#include <pthread.h>
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
bool parse_arguments(char **argv);
bool aux_exit_check_number(char **argv, int i, int j);
char    *ft_strdup(const char *s);
int     ft_isdigit(int c);
char	**check_number(char **argv);
bool	check_spaces(char *argv, char *str);
char	*aux_checknumber(char *str, char *argv);
void	*check_sort(char **numbers);
char	**check_long(char *str);
void	ft_putendl_fd(char *s, int fd);
char	*ft_strjoin(char const *s1, char const *s2);
int     ft_atoi(const char *nptr);
void	free_array(char **str);
char	**ft_split(char const *s, char c);
long	ft_atoll(const char *nptr);
size_t	ft_arraylen(char **array);size_t	ft_arraylen(char **array);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
#endif  