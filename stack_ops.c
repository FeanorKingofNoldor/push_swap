/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuthmay <mhuthmay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:19:03 by mhuthmay          #+#    #+#             */
/*   Updated: 2024/11/05 13:34:35 by mhuthmay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(void);

int	init_stacks(t_stack **a, t_stack **b)
{
	*a = init_stack();
	if (!a)
		return (0);
	*b = init_stack();
	if (!b)
	{
		stack_clear(*a);
		return (0);
	}
	return (1);
}

t_stack	*init_stack(void)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->head = NULL;
	new->tail = NULL;
	new->size = 0;
	return (new);
}

int	stack_add_front(t_stack *stack, int value)
{
	t_node	*node;

	if (!stack)
		return (0);
	node = new_node(value);
	if (!node)
		return (0);
	if (!stack->head)
	{
		stack->head = node;
		stack->tail = node;
	}
	else
	{
		node->next = stack->head;
		stack->head->prev = node;
		stack->head = node;
	}
	stack->size++;
	return (1);
}

int	stack_add_back(t_stack *stack, int value)
{
	t_node	*node;

	if (!stack)
		return (0);
	node = new_node(value);
	if (!node)
		return (0);
	if (!stack->head)
	{
		stack->head = node;
		stack->tail = node;
	}
	else
	{
		node->prev = stack->tail;
		stack->tail->next = node;
		stack->tail = node;
	}
	stack->size++;
	return (1);
}

void	stack_clear(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	if (!stack)
		return ;
	current = stack->head;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(stack);
}
