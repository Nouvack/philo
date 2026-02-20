/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsantand <nsantand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 16:42:22 by nsantand          #+#    #+#             */
/*   Updated: 2026/02/20 18:51:38 by nsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo.h"

static long	aux_atoll(long long sig)
{
	if (sig == -1)
		return (LONG_MIN);
	else
		return (LONG_MAX);
}

long	ft_atoll(const char *nptr)
{
	long	i;
	long	sig;
	long	res;

	i = 0;
	sig = 1;
	res = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || (nptr[i] == ' '))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sig = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		if (res > (LONG_MAX / 10) || (res == (LONG_MAX / 10) && (nptr[i]
					- '0') > (LONG_MAX % 10)))
			return (aux_atoll(sig));
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	return (sig * res);
}
int	ft_atoi(const char *nptr)
{
	int		i;
	int		sig;
	int		res;

	i = 0;
	sig = 1;
	res = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || (nptr[i] == ' '))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sig = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	return (sig * res);
}
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


bool parse_arguments(char **argv)
{
	char **nums;
	pthread_t hilo;
	pthread_t hilo2;
	

	
    nums = check_number(argv);
	if(!nums)
		return(false);
	//funcion de convertir el array de string de numeros a int
	size_t i = 0;
	while(i < ft_arraylen(nums))
	{
		printf("este es el nummero: %s\n",  nums[i]);
		i++;
	}
	pthread_create(&hilo, NULL, printas, "hola");
	pthread_create(&hilo2, NULL, printas, "hola");
	//aprender de los mutex
	pthread_join(hilo, NULL);
	pthread_join(hilo2, NULL);
	
	
	return(true);
}
