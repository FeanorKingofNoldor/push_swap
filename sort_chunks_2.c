/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunks_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuthmay <mhuthmay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:40:12 by mhuthmay          #+#    #+#             */
/*   Updated: 2024/11/05 13:42:40 by mhuthmay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_chunk_to_b(t_stack *a, t_stack *b, t_bounds *bounds)
{
	int	pos;

	pos = find_closest_in_chunk(a, bounds);
	while (pos != -1)
	{
		optimize_push(a, b, pos);
		pos = find_closest_in_chunk(a, bounds);
	}
}

static void	push_back_to_a(t_stack *a, t_stack *b)
{
	int	max;

	while (b->size > 0)
	{
		max = get_max(b);
		smart_rotate_b(b, max);
		pa(a, b);
	}
}

void	sort_chunks(t_stack *a, t_stack *b)
{
	t_bounds	bounds;
	int			chunks;
	int			i;
	int			initial_size;

	initial_size = a->size;
	chunks = get_chunk_count(initial_size);
	i = 0;
	while (a->size > 0)
	{
		get_chunk_bounds(a, i, &bounds);
		push_chunk_to_b(a, b, &bounds);
		i++;
		if (i >= chunks)
			i = 0;
	}
	push_back_to_a(a, b);
}
