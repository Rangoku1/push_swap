/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelmrabe <nelmrabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 14:40:34 by nelmrabe          #+#    #+#             */
/*   Updated: 2023/07/18 14:47:48 by nelmrabe         ###   ########.fr       */
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
	int	i;
	i = 0;
	while(av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
}
int	all_space(char *str)
{
	size_t i;

	i = 0;
	while((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			i++;
	if(ft_strlen(str) == i)
		return (1);
	else
		return (0);
}
char	*oneline(char **args)
{
	char *tmp;
	char *line;
	int i = 2;
	
	line = ft_strjoin(args[1], " ");
	while (args[i])
	{
		if (all_space(args[i]))
			ft_error();
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
