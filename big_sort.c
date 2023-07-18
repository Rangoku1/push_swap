/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelmrabe <nelmrabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 19:18:56 by nelmrabe          #+#    #+#             */
/*   Updated: 2023/07/15 19:53:11 by nelmrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_sorted(t_stacks *stacks)
{
	int	i;
	int	j;
	int	tmp;

	stacks->a_sorted = malloc(sizeof(int) * stacks->a->size);
	i = 0;
	while (i < stacks->a->size)
	{
		stacks->a_sorted[i] = stacks->a->tab[i];
		i++;
	}
	i = -1;
	while (++i < stacks->a->size)
	{
		j = -1;
		while (++j < stacks->a->size - 1)
		{
			if (stacks->a_sorted[j] > stacks->a_sorted[j + 1])
			{
				tmp = stacks->a_sorted[j];
				stacks->a_sorted[j] = stacks->a_sorted[j + 1];
				stacks->a_sorted[j + 1] = tmp;
			}
		}
	}
}

int	index_of_bigest(t_stack *stack)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	while (i < stack->size)
	{
		if (stack->tab[i] > stack->tab[index])
			index = i;
		i++;
	}
	return (index);
}

int	content_index(int content, int *a_sorted)
{
	int	i;

	i = 0;
	while (a_sorted[i] != content)
		i++;
	return (i);
}

void	push_to_b(t_stacks *stack, int min, int max)
{
	int	index;

	while (stack->a->size)
	{
		index = content_index(stack->a->tab[0], stack->a_sorted);
		if (min > index)
		{
			push_stack(stack->a, stack->b, 'b');
			rotate_stack(stack->b, 'b');
			min++;
			max++;
		}
		if (min <= index && index <= max)
		{
			push_stack(stack->a, stack->b, 'b');
			min++;
			max++;
		}
		if (index > max)
			rotate_stack(stack->a, 'a');
	}
}
