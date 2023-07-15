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

void a_sorted(t_stacks *stacks)
{
	int	i;
	int	j;
	int	tmp;

	stacks->a_sorted = malloc(sizeof(int) * stacks->a->size);
	for (int i = 0; i < stacks->a->size; i++)
		stacks->a_sorted[i] = stacks->a->tab[i];
	i = 0;
	while (i < stacks->a->size)
	{
		j = 0;
		while (j < stacks->a->size - 1)
		{
			if (stacks->a_sorted[j] > stacks->a_sorted[j + 1])
			{
				tmp = stacks->a_sorted[j];
				stacks->a_sorted[j] = stacks->a_sorted[j + 1];
				stacks->a_sorted[j + 1] = tmp;
			}
			j++;
		}
		i++;
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
