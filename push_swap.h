/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelmrabe <nelmrabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:48:17 by nelmrabe          #+#    #+#             */
/*   Updated: 2023/07/07 16:21:06 by nelmrabe         ###   ########.fr       */
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
#endif