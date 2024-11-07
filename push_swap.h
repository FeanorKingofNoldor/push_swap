/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuthmay <mhuthmay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:19:12 by mhuthmay          #+#    #+#             */
/*   Updated: 2024/11/05 13:47:18 by mhuthmay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "ft_printf/libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_bounds
{
	int				min;
	int				max;
}					t_bounds;

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_stack
{
	t_node			*head;
	t_node			*tail;
	int				size;
}					t_stack;

// Stack operations
t_stack				*init_stack(void);
int					init_stacks(t_stack **a, t_stack **b);
void				stack_clear(t_stack *stack);
int					stack_add_front(t_stack *stack, int value);
int					stack_add_back(t_stack *stack, int value);
t_node				*new_node(int value);

// Input processing
int					process_arg(t_stack *a, char *arg);
int					add_number(t_stack *a, char *str);

// Stack operations (push, swap, rotate)
void				sa(t_stack *a);
void				sb(t_stack *b);
void				ss(t_stack *a, t_stack *b);
void				pa(t_stack *a, t_stack *b);
void				pb(t_stack *a, t_stack *b);
void				ra(t_stack *a);
void				rb(t_stack *b);
void				rr(t_stack *a, t_stack *b);
void				rra(t_stack *a);
void				rrb(t_stack *b);
void				rrr(t_stack *a, t_stack *b);

// Stack checking functions
int					is_sorted(t_stack *stack);
int					get_min(t_stack *stack);
int					get_max(t_stack *stack);
int					get_min_pos(t_stack *stack);
int					get_max_pos(t_stack *stack);

// Input validation
int					is_valid_int(char *str);
int					is_number(char *str);
int					has_duplicates(t_stack *stack);

// Error handling
void				error_exit(t_stack *a, t_stack *b);

// Chunk sorting
void				get_chunk_bounds(t_stack *a, int chunk, t_bounds *bounds);
int					find_closest_in_chunk(t_stack *a, t_bounds *bounds);
void				sort_chunks(t_stack *a, t_stack *b);
int					find_value_pos(t_stack *stack, int value);
void				quick_sort(int *arr, int low, int high);
int					get_chunk_count(int size);
void				smart_rotate_b(t_stack *b, int target);
void				optimize_push(t_stack *a, t_stack *b, int pos);

// sorting
void				sort_small(t_stack *a, t_stack *b);
void				sort_three(t_stack *a);
void				sort_four(t_stack *a, t_stack *b);
void				sort_five(t_stack *a, t_stack *b);

#endif