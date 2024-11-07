/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuthmay <mhuthmay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:23:27 by mhuthmay          #+#    #+#             */
/*   Updated: 2024/11/05 13:04:10 by mhuthmay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_split(char **split, int i)
{
	while (i >= 0)
		free(split[i--]);
	free(split);
}

int	add_number(t_stack *a, char *str)
{
	if (!is_number(str) || !is_valid_int(str))
		return (0);
	if (!stack_add_back(a, ft_atoi(str)))
		return (0);
	return (1);
}

int	process_arg(t_stack *a, char *arg)
{
	char	**numbers;
	int		i;

	numbers = ft_split(arg, ' ');
	if (!numbers)
		return (0);
	i = 0;
	while (numbers[i])
	{
		if (!add_number(a, numbers[i]))
		{
			free_split(numbers, i);
			return (0);
		}
		i++;
	}
	free_split(numbers, i - 1);
	return (1);
}

void	error_exit(t_stack *a, t_stack *b)
{
	if (a)
		stack_clear(a);
	if (b)
		stack_clear(b);
	ft_putendl_fd("Error", 2);
	exit(1);
}
