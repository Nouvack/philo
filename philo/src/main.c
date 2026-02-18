#include "philo.h"

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
		{
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != ' '
				&& argv[i][j] != '-' && argv[i][j] != '+' && argv[i][j] != ' ')
				return (free(str), NULL);
			if ((argv[i][j] == '+' && !ft_isdigit(argv[i][j + 1]))
				|| (argv[i][j] == '-' && !ft_isdigit(argv[i][j + 1])))
				return (free(str), NULL);
		}
		str = aux_checknumber(str, argv[i]);
		i++;
	}
	numbers = check_long(str);
	check_sort(numbers);
	return (numbers);
}

void	check_spaces(char *argv, char *str)
{
	int	i;

	i = 0;
	while (argv[i] != '\0')
	{
		if (argv[i] != ' ')
			return ;
		i++;
	}
	ft_putendl_fd("Error: Empty argument", 2);
	free(str);
}

char	*aux_checknumber(char *str, char *argv)
{
	char	*temp;

	check_spaces(argv, str);
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

void	*check_sort(char **numbers)
{
	int	i;
	int	current;
	int	next;

	i = 0;
	while (numbers[i + 1])
	{
		current = ft_atoi(numbers[i]);
		next = ft_atoi(numbers[i + 1]);
		if (current > next)
			return ((void *)0);
		i++;
	}
	free_array(numbers);
	return(NULL);
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
		if (number > INT_MAX || number < INT_MIN)
			return (free_array(nums), NULL);
		j = i + 1;
		while (nums[j])
		{
			if (ft_atoll(nums[j]) == number)
				return (free_array(nums),  NULL);
			j++;
		}
		i++;
	}
	if (ft_arraylen(nums) == 1)
		return (free_array(nums), NULL);
	return (nums);
}

void parse_arguments(char **argv)
{
	char **nums;


    nums = check_number(argv);
}



int main(int argc, char **argv)
{

    if(argc < 5 || argc > 6)
    {
        printf("hola");
        return(1);
    }
    parse_arguments(argv);

    return(0);
}
