/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuthmay <mhuthmay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:55:08 by mhuthmay          #+#    #+#             */
/*   Updated: 2024/11/05 13:36:50 by mhuthmay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_pos(t_stack *stack)
{
	t_node	*current;
	int		min;
	int		pos;
	int		min_pos;

	if (!stack || !stack->head)
		return (0);
	current = stack->head;
	min = current->value;
	pos = 0;
	min_pos = 0;
	while (current)
	{
		if (current->value < min)
		{
			min = current->value;
			min_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (min_pos);
}

int	get_max_pos(t_stack *stack)
{
	t_node	*current;
	int		max;
	int		pos;
	int		max_pos;

	if (!stack || !stack->head)
		return (0);
	current = stack->head;
	max = current->value;
	pos = 0;
	max_pos = 0;
	while (current)
	{
		if (current->value > max)
		{
			max = current->value;
			max_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (max_pos);
}

int	find_value_pos(t_stack *stack, int value)
{
	t_node	*current;
	int		pos;

	if (!stack || !stack->head)
		return (-1);
	current = stack->head;
	pos = 0;
	while (current)
	{
		if (current->value == value)
			return (pos);
		current = current->next;
		pos++;
	}
	return (-1);
}
