/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelmrabe <nelmrabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 19:18:56 by nelmrabe          #+#    #+#             */
/*   Updated: 2023/07/15 19:53:11 by nelmrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	the_greatest(t_stack *stack)
{
	int	i;
	int	greatest;

	i = 0;
	greatest = stack->tab[0];
	while (i < stack->size)
	{
		if (stack->tab[i] > greatest)
			greatest = stack->tab[i];
		i++;
	}
	return (greatest);
}

void	big_sort(t_stacks *stack)
{
	int	index;
	int	min;
	int	max;

	min = 0;
	max = 15;
	if (stack->a->size > 200)
		max = 40;
	push_to_b(stack, min, max);
	while (stack->b->size)
	{
		index = index_of_bigest(stack->b);
		while (stack->b->tab[0] != the_greatest(stack->b))
		{
			if (index <= stack->b->size / 2)
				rotate_stack(stack->b, 'b');
			else
				reverse_rotate_stack(stack->b, 'b');
		}
		push_stack(stack->b, stack->a, 'a');
	}
}
