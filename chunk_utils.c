/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuthmay <mhuthmay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:20:23 by mhuthmay          #+#    #+#             */
/*   Updated: 2024/11/05 13:35:44 by mhuthmay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_endpoints(t_stack *a, t_bounds *bounds)
{
	if (!a || !a->head)
		return (-1);
	if (a->size == 1)
	{
		if (a->head->value >= bounds->min && a->head->value <= bounds->max)
			return (0);
		return (-1);
	}
	return (0);
}

static void	advance_pointers(t_node **top, t_node **bottom, int *top_pos,
		int *bottom_pos)
{
	if ((*top)->next)
	{
		*top = (*top)->next;
		(*top_pos)++;
	}
	if ((*bottom)->prev)
	{
		*bottom = (*bottom)->prev;
		(*bottom_pos)--;
	}
}

int	find_closest_in_chunk(t_stack *a, t_bounds *bounds)
{
	t_node	*top;
	t_node	*bottom;
	int		top_pos;
	int		bottom_pos;
	int		check;

	check = check_endpoints(a, bounds);
	if (check != 0)
		return (check);
	top = a->head;
	bottom = a->tail;
	top_pos = 0;
	bottom_pos = a->size - 1;
	while (top && bottom && top_pos <= bottom_pos)
	{
		if (top->value >= bounds->min && top->value <= bounds->max)
			return (top_pos);
		if (bottom->value >= bounds->min && bottom->value <= bounds->max)
			return (bottom_pos);
		if (top_pos == bottom_pos)
			return (-1);
		advance_pointers(&top, &bottom, &top_pos, &bottom_pos);
	}
	return (-1);
}

void	get_chunk_bounds(t_stack *a, int chunk, t_bounds *bounds)
{
	int		size;
	int		chunk_count;
	int		*sorted;
	int		i;
	t_node	*current;

	size = a->size;
	chunk_count = get_chunk_count(size);
	sorted = (int *)malloc(sizeof(int) * size);
	if (!sorted)
		return ;
	i = 0;
	current = a->head;
	while (current)
	{
		sorted[i++] = current->value;
		current = current->next;
	}
	quick_sort(sorted, 0, size - 1);
	bounds->min = sorted[size * chunk / chunk_count];
	bounds->max = sorted[size * (chunk + 1) / chunk_count - 1];
	free(sorted);
}
