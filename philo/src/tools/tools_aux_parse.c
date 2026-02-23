/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_aux_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsantand <nsantand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:17:32 by nsantand          #+#    #+#             */
/*   Updated: 2026/02/23 14:17:42 by nsantand         ###   ########.fr       */
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