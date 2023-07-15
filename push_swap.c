/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelmrabe <nelmrabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:47:46 by nelmrabe          #+#    #+#             */
/*   Updated: 2023/07/15 19:54:56 by nelmrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stacks stacks;
	stacks.a = malloc(sizeof(t_stack));
	stacks.b = malloc(sizeof(t_stack));
	if (ac == 1)
		return (1);
	stacks.a->tab = tabint(av, stacks);
	stacks.b->tab = malloc(sizeof(int) * stacks.a->size);

	check_rep(stacks.a);
	if (is_sorted(stacks.a))
		return (0);
	a_sorted(&stacks);
	if (stacks.a->size <= 3)
		sort_three(stacks.a);
	else if (stacks.a->size <= 5)
		sort_five(stacks.a, stacks.b);
	else
		big_sort(&stacks);
	// printf("==============\n");
	// for (int i = 0; i < stacks.a->size; i++)
	// 	printf("==>%d\n", stacks.a_sorted[i]);
	// for (int i = 0; i < stacks.b->size; i++)
	// 	printf("==>%d\n", stacks.b->tab[i]);
}