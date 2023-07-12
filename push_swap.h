/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelmrabe <nelmrabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:48:17 by nelmrabe          #+#    #+#             */
/*   Updated: 2023/07/09 14:40:51 by nelmrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
typedef struct s_stack
{
	int *tab;
	int size;
}t_stack;

typedef struct s_stacks
{
	t_stack *a;
	t_stack *b;
}t_stacks;


void	ft_error(void);
void	free_array(char **av);
int		all_space(char *str);
char	*oneline(char **args);
char	**splitit(char **av);
int		tablen(char **str);
int		*tabint(char **av, t_stacks stacks);
void	check_rep(t_stack *a);
int		is_sorted(t_stack *a);
#endif