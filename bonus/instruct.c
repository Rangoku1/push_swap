/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelmrabe <nelmrabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:46:16 by nelmrabe          #+#    #+#             */
/*   Updated: 2023/07/21 20:15:51 by nelmrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rotate_stack(t_stack *stack)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = stack->tab[0];
	while (i < stack->size - 1)
	{
		stack->tab[i] = stack->tab[i + 1];
		i++;
	}
	stack->tab[i] = tmp;
}

void	swap_stack(t_stack *stack)
{
	int	tmp;

	tmp = stack->tab[0];
	stack->tab[0] = stack->tab[1];
	stack->tab[1] = tmp;
}

void	reverse_rotate_stack(t_stack *stack)
{
	int	tmp;
	int	i;

	i = stack->size - 1;
	tmp = stack->tab[i];
	while (i > 0)
	{
		stack->tab[i] = stack->tab[i - 1];
		i--;
	}
	stack->tab[i] = tmp;
}

void	push_stack(t_stack *stack1, t_stack *stack2)
{
	int	i;

	i = stack2->size;
	while (i > 0)
	{
		stack2->tab[i] = stack2->tab[i - 1];
		i--;
	}
	stack2->tab[0] = stack1->tab[0];
	i = 0;
	while (i < stack1->size - 1)
	{
		stack1->tab[i] = stack1->tab[i + 1];
		i++;
	}
	stack1->size--;
	stack2->size++;
}
