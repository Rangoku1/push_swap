/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelmrabe <nelmrabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 17:17:59 by nelmrabe          #+#    #+#             */
/*   Updated: 2023/07/21 20:09:52 by nelmrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *a)
{
	if (a->size == 2)
	{
		if (a->tab[0] > a->tab[1])
			swap_stack(a, 'a');
	}
	if (a->tab[0] > a->tab[1] && a->tab[1] < a->tab[2] && a->tab[0] > a->tab[2])
		rotate_stack(a, 'a');
	else if (a->tab[0] > a->tab[1] && a->tab[1] > a->tab[2])
	{
		swap_stack(a, 'a');
		reverse_rotate_stack(a, 'a');
	}
	else if (a->tab[0] > a->tab[1] && a->tab[1] < a->tab[2] \
	&& a->tab[0] < a->tab[2])
		swap_stack(a, 'a');
	else if (a->tab[0] < a->tab[1] && a->tab[1] > a->tab[2] \
	&& a->tab[0] < a->tab[2])
	{
		reverse_rotate_stack(a, 'a');
		swap_stack(a, 'a');
	}
	else if (a->tab[0] < a->tab[1] && a->tab[1] > a->tab[2] \
	&& a->tab[0] > a->tab[2])
		reverse_rotate_stack(a, 'a');
}

int	index_of_smallest(t_stack *stack)
{
	int	i;
	int	index;
	int	smallest;

	i = 0;
	index = 0;
	smallest = stack->tab[0];
	while (i < stack->size)
	{
		if (stack->tab[i] < smallest)
		{
			smallest = stack->tab[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int	the_smallest(t_stack *stack)
{
	int	i;
	int	smallest;

	i = 0;
	smallest = stack->tab[0];
	while (i < stack->size)
	{
		if (stack->tab[i] < smallest)
			smallest = stack->tab[i];
		i++;
	}
	return (smallest);
}

void	sort_five(t_stack *a, t_stack *b)
{
	int	index;

	while (a->size > 3)
	{
		index = index_of_smallest(a);
		while (a->tab[0] != the_smallest(a))
		{
			if (index <= a->size / 2)
				rotate_stack(a, 'a');
			if (index > a->size / 2)
				reverse_rotate_stack(a, 'a');
		}
		push_stack(a, b, 'b');
	}
	sort_three(a);
	while (b->size > 0)
		push_stack(b, a, 'a');
}
