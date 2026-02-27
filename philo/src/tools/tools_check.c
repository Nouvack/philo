/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsantand <nsantand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 16:42:03 by nsantand          #+#    #+#             */
/*   Updated: 2026/02/27 18:19:38 by nsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>
char	**check_number(char **argv)
{
	int		i;
	int		j;
	char	*str;
	char	**numbers;

	i = 1;
	str = ft_strdup("");
	while (argv[i] != NULL)
	{
		j = -1;
		while (argv[i][++j] != '\0')
			if (!aux_exit_check_number(argv, i, j))
				return (free(str), NULL);
		str = aux_checknumber(str, argv[i]);
		if(!str)
			return(NULL);
		i++;
	}
	numbers = check_long(str);
	return (numbers);
}
bool aux_exit_check_number(char **argv, int i, int j)
{
	if (!ft_isdigit(argv[i][j]) && argv[i][j] != ' '
				&& argv[i][j] != '-' && argv[i][j] != '+' && argv[i][j] != ' ')
				return (false);
	if ((argv[i][j] == '+' && !ft_isdigit(argv[i][j + 1]))
				|| (argv[i][j] == '-' && !ft_isdigit(argv[i][j + 1])))
				return (false);

	return(true);
}
bool	check_spaces(char *argv, char *str)
{
	int	i;

	i = 0;
	while (argv[i] != '\0')
	{
		if (argv[i] != ' ')
			return (true);
		i++;
	}
	ft_putendl_fd("Error: Empty argument", 2);
	free(str);
	return(false);
}

char	*aux_checknumber(char *str, char *argv)
{
	char	*temp;

	if(!check_spaces(argv, str))
		return(NULL);
	if (argv[0] == '\0')
		return (ft_putendl_fd("Error: Empty argument", 2), free(str),
			NULL);
	if (!argv)
		return (ft_putendl_fd("Error: Argument not int", 2), free(str),
			NULL);
	temp = ft_strjoin(str, argv);
	free(str);
	str = temp;
	temp = ft_strjoin(str, " ");
	free(str);
	str = temp;
	return (str);
}



char	**check_long(char *str)
{
	int		i;
	int		j;
	long	number;
	char	**nums;

	nums = ft_split(str, ' ');
	free(str);
	i = 0;
	while (nums[i] != NULL)
	{
		number = ft_atoll(nums[i]);
		if(nums[i + 1] == NULL && (number >= -1  && number < INT_MAX))
			break;
		if (nums[0] > 200 ||number > INT_MAX || number < 0)
			return (free_array(nums), NULL);
		j = i + 1;
		i++;
	}
	if (ft_arraylen(nums) == 1)
		return (free_array(nums), NULL);
	return (nums);
}