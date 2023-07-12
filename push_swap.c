/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelmrabe <nelmrabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:47:46 by nelmrabe          #+#    #+#             */
/*   Updated: 2023/07/09 14:40:11 by nelmrabe         ###   ########.fr       */
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

	check_rep(stacks.a);
	if (is_sorted(stacks.a))
		return (0);
	for (int i = 0; i < stacks.a->size; i++)
		printf("==>%d\n", stacks.a->tab[i]);
}