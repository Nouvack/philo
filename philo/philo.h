/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsantand <nsantand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 15:16:20 by nsantand          #+#    #+#             */
/*   Updated: 2026/03/07 15:28:33 by nsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define RED "\033[1;31m"
# define YELLOW "\033[1;33m"
# define CYAN "\033[1;36m"
# define SILVER "\033[1;37m"
# define PURPLE "\033[1;35m"
# define DEF_COLOR "\033[0;39m"

# define COLOR_FORK SILVER "has taken a fork\n" DEF_COLOR
# define COLOR_EAT YELLOW "is eating\n" DEF_COLOR
# define COLOR_SLEEP PURPLE "is sleeping\n" DEF_COLOR
# define COLOR_THINK CYAN "is thinking\n" DEF_COLOR
# define COLOR_DEAD RED "died\n" DEF_COLOR
typedef struct s_table	t_table;

typedef enum e_state
{
	EATING,
	FORKING,
	THINKING,
	SLEEPING,
	DEAD,
}						t_state;

typedef struct s_philos
{
	int					ids;
	pthread_t			thread;
	int					number_eats;
	long				last_meal;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	t_table				*table;
}						t_philos;

typedef struct s_table
{
	pthread_t			monitor_thread;
	long				start_time;
	int					number_of_philosophers;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					number_of_timmes_each_philosopher_must_eat;
	bool				stop;
	pthread_mutex_t		dead_mutex;
	pthread_mutex_t		meal_mutex;
	pthread_mutex_t		*forks;
	pthread_mutex_t		print_mutex;
	t_philos			*philos;
}						t_table;

pthread_mutex_t			*create_forks(t_table *table);

bool					begin_program(char **argv);
bool					aux_exit_check_number(char **argv, int i, int j);
char					*ft_strdup(const char *s);
int						ft_isdigit(int c);
char					**check_number(char **argv);
bool					check_spaces(char *argv, char *str);
char					*aux_checknumber(char *str, char *argv);
void					*check_sort(char **numbers);
char					**check_long(char *str);
void					ft_putendl_fd(char *s, int fd);
char					*ft_strjoin(char const *s1, char const *s2);
int						ft_atoi(const char *nptr);
void					free_array(char **str);
char					**ft_split(char const *s, char c);
long					ft_atoll(const char *nptr);
size_t					ft_arraylen(char **array);
size_t					ft_arraylen(char **array);
size_t					ft_strlen(const char *s);
size_t					ft_strlcpy(char *dst, const char *src, size_t size);
size_t					ft_strlcat(char *dst, const char *src, size_t size);
void					*ft_calloc(size_t nmemb, size_t size);
void					ft_bzero(void *s, size_t n);
void					place_node(t_philos **lst, t_philos *new);
void					philo_actions(t_table *table);
long					get_time_in_ms(void);
void					*philo_routine(void *arg);
void					*philo_is_forkin(t_philos *philo);
void					release_forks(t_philos *philo);
void					print_actions(t_philos *philo, int action);
void					*philo_is_eating(t_philos *philo);
void					*philo_is_sleeping(t_philos *philo);
void					*philo_is_thinking(t_philos *philo);
void					*monitor_routine(void *arg);
void					finish_threads(t_table *table);
bool					check_stop(t_table *table);
void	ft_usleep(unsigned time, t_table *table);
bool	philo_is_dead(t_philos *philo);
#endif