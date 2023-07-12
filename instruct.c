/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelmrabe <nelmrabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:46:16 by nelmrabe          #+#    #+#             */
/*   Updated: 2023/07/11 15:56:22 by nelmrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate_stack(t_stack *stack)
{
	int tmp;
	int i;

	i = 0;
	tmp = stack->stack[0];
	while (i < stack->size - 1)
	{
		stack->stack[i] = stack->stack[i + 1];
		i++;
	}
	stack->stack[i] = tmp;
}


void	swap_stack(t_stack *stack)
{
	int tmp;

	tmp = stack->stack[0];
	stack->stack[0] = stack->stack[1];
	stack->stack[1] = tmp;
}

void	reverse_rotate_stack(t_stack *stack)
{
	int tmp;
	int i;

	i = stack->size - 1;
	tmp = stack->stack[i];
	while (i > 0)
	{
		stack->stack[i] = stack->stack[i - 1];
		i--;
	}
	stack->stack[i] = tmp;
}

void	reverse_rotate_both(t_stack *a, t_stack *b)
{
	reverse_rotate_stack(a);
	reverse_rotate_stack(b);
}

void	push_stack(t_stack *stack, int num)
{
	int i;

	i = stack->size;
	while (i > 0)
	{
		stack->stack[i] = stack->stack[i - 1];
		i--;
	}
	stack->stack[i] = num;
}
void swap_both(t_stack *a, t_stack *b)
{
	swap_stack(a);
	swap_stack(b);
}
void	rotate_both(t_stack *a, t_stack *b)
{
	rotate_stack(a);
	rotate_stack(b);
}