/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsantand <nsantand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 15:14:20 by nsantand          #+#    #+#             */
/*   Updated: 2026/02/27 18:54:45 by nsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H



# include <stdio.h>
# include <limits.h>
# include <stdlib.h> 
# include <unistd.h>
# include <stdbool.h>
# include <pthread.h>
# include <stdint.h>
# include <sys/time.h>
typedef enum e_state
{
	EATING,
    THINKING,
    SLEEPING,
    DEAD,
}	t_state;
typedef struct s_table 
{
    long    start_time;
    int number_of_philosophers;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int number_of_timmes_each_philosopher_must_eat;
    pthread_mutex_t *forks;
    pthread_mutex_t print_mutex;

} t_table;

typedef struct s_philos
{
    int ids;
    pthread_t thread;
    int number_eat;
    long last_meal;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
    t_table *table;
} t_philos;


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
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
void	place_node(t_philos **lst, t_philos *new);
#endif  