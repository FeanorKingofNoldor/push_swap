/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuthmay <mhuthmay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:19:21 by mhuthmay          #+#    #+#             */
/*   Updated: 2024/11/05 13:34:05 by mhuthmay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	process_input(t_stack *a, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!process_arg(a, argv[i]))
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	if (!init_stacks(&a, &b))
		error_exit(NULL, NULL);
	if (!process_input(a, argc, argv))
		error_exit(a, b);
	if (has_duplicates(a))
		error_exit(a, b);
	if (!is_sorted(a))
	{
		if (a->size <= 5)
			sort_small(a, b);
		else
			sort_chunks(a, b);
	}
	stack_clear(a);
	stack_clear(b);
	return (0);
}
