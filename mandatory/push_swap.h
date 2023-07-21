/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelmrabe <nelmrabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:48:17 by nelmrabe          #+#    #+#             */
/*   Updated: 2023/07/20 16:38:05 by nelmrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>

typedef struct s_stack
{
	int	*tab;
	int	size;
}	t_stack;

typedef struct s_stacks
{
	t_stack	*a;
	t_stack	*b;
	int		*a_sorted;
}	t_stacks;

/* Check args*/
void	ft_error(void);
void	free_array(char **av);
int		all_space(char *str);
char	*oneline(char **args);
char	**splitit(char **av);
int		tablen(char **str);
int		*tabint(char **av, t_stacks stacks);
void	check_rep(t_stack *a);
int		is_sorted(t_stack *a);

/* INstruction*/
void	rotate_stack(t_stack *stack, char x);
void	swap_stack(t_stack *stack, char x);
void	reverse_rotate_stack(t_stack *stack, char x);
void	push_stack(t_stack *stack1, t_stack *stack2, char to);

/* INstruction*/
void	sort_three(t_stack *a);
void	sort_five(t_stack *a, t_stack *b);

/* INstruction*/
void	a_sorted(t_stacks *stacks);
void	a_sorted(t_stacks *stacks);
int		index_of_bigest(t_stack *stack);
int		content_index(int content, int *a_sorted);
void	push_to_b(t_stacks *stack, int min, int max);
int		the_greatest(t_stack *stack);
void	big_sort(t_stacks *stack);
#endif