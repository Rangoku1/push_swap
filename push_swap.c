/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelmrabe <nelmrabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:47:46 by nelmrabe          #+#    #+#             */
/*   Updated: 2023/07/07 18:00:25 by nelmrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void 	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
void free_array(char **av)
{
	int i;
	i = 0;
	while(av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
}
char	*oneline(char **args)
{
	char *tmp;
	char *line;
	int i = 1;
	
	line = ft_strdup("");
	while (args[i])
	{
		if (ft_strlen(args[i]) == 0)
			ft_error();
		tmp = ft_strjoin(args[i], " ");
		line = ft_strjoin(line, tmp);
		free(tmp);
		i++;
	}
	return(line);
}

char	**splitit(char **av)
{
	char *line;
	char **container;
	int i;
	int j;

	line = oneline(av);
	i = 0;
	container = ft_split(line, ' ');
	while (container[i])
	{
		j = 0;
		if (container[i][j] == '-' || container[i][j] == '+')
			j++;
		while (container[i][j])
		{
			if (ft_isdigit(container[i][j]) == 0)
				ft_error();
			j++;
		}
		i++;
	}
	free(line);
	return(container);
}

int tablen(char **str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return(i);
}

int	*tabint(char **av, t_stacks stacks)
{
	char **spl_args;
	int *tab;
	int i;

	i = 0;
	spl_args = splitit(av);
	stacks.a->size = tablen(spl_args);
	tab = malloc(sizeof(int) * stacks.a->size);
	while(spl_args[i])
	{
		tab[i] = ft_atoi(spl_args[i]);
		i++;
	}
	free_array(spl_args);
	return(tab);
}
void check_rep(t_stack *a)
{
	int i;
	int j;

	i = 0;
	while(i < a->size)
	{
		j = i + 1;
		while (j < a->size)
		{
			if(a->tab[i] == a->tab[j])
				ft_error();
			j++;
		}
		i++;
	}
}
int is_sorted(t_stack *a)
{
	int i;

	i = 0;
	while (i + 1 < a->size)
	{
		if(a->tab[i] > a->tab[i + 1])
			return(0);
		i++;
	}
	return(1);
}
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