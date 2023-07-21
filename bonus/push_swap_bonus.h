/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelmrabe <nelmrabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:48:17 by nelmrabe          #+#    #+#             */
/*   Updated: 2023/07/21 20:14:56 by nelmrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

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
void	rotate_stack(t_stack *stack);
void	swap_stack(t_stack *stack);
void	reverse_rotate_stack(t_stack *stack);
void	push_stack(t_stack *stack1, t_stack *stack2);

/*gnl*/
int		ftstrlen(char *str);
char	*ftstrjoin(char *s1, char *s2);
int		ftstrchr(char *str, char c);
char	*before_n(char *str);
char	*after_n(char *ptr);
int		read_fun(int read, char **line);
char	*get_next_line(int fd);

/* INstruction*/
void	swap_both(t_stack *a, t_stack *b);
void	rotate_both(t_stack *a, t_stack *b);
void	reverse_rotate_both(t_stack *a, t_stack *b);
#endif