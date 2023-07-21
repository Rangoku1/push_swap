/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelmrabe <nelmrabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 16:26:51 by nelmrabe          #+#    #+#             */
/*   Updated: 2023/07/21 20:21:03 by nelmrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	check_instruction(char *line, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strncmp(line, "sa\n", 3) == 0)
		swap_stack(stack_a);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		swap_stack(stack_b);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		swap_both(stack_a, stack_b);
	else if (ft_strncmp(line, "pa\n", 3) == 0)
		push_stack(stack_a, stack_b);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		push_stack(stack_b, stack_a);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		rotate_stack(stack_a);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		rotate_stack(stack_b);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		rotate_both(stack_a, stack_b);
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		reverse_rotate_stack(stack_a);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		reverse_rotate_stack(stack_b);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		reverse_rotate_both(stack_a, stack_b);
	else
		ft_error();
}

void	ft_check(t_stack *stack_a, t_stack *stack_b)
{
	if (is_sorted(stack_a) && stack_b->size == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int ac, char **av)
{
	t_stacks	stacks;
	char		*line;

	if (ac == 1)
		return (1);
	stacks.a = malloc(sizeof(t_stack));
	stacks.b = malloc(sizeof(t_stack));
	stacks.a->tab = tabint(av, stacks);
	stacks.b->size = 0;
	stacks.b->tab = malloc(sizeof(int) * stacks.a->size);
	check_rep(stacks.a);
	line = get_next_line(0);
	while (line)
	{
		check_instruction(line, stacks.a, stacks.b);
		free(line);
		line = get_next_line(0);
	}
	ft_check(stacks.a, stacks.b);
	free(stacks.a->tab);
	free(stacks.b->tab);
	free(stacks.a);
	free(stacks.b);
	return (0);
}
