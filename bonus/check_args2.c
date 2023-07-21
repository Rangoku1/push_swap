/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelmrabe <nelmrabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 14:40:34 by nelmrabe          #+#    #+#             */
/*   Updated: 2023/07/20 16:37:04 by nelmrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	all_space(char *str)
{
	size_t	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			i++;
	if (ft_strlen(str) == i)
		return (1);
	else
		return (0);
}

char	*ft_join(char *s1, char *s2)
{
	char	*str;
	int		len;
	int		i;
	int		j;

	if (s1 == NULL)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		str[i++] = s1[j++];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

char	*oneline(char **args)
{
	char	*tmp;
	char	*line;
	int		i;

	i = 2;
	line = ft_strjoin(args[1], " ");
	while (args[i])
	{
		if (all_space(args[i]))
			ft_error();
		if (ft_strlen(args[i]) == 0)
			ft_error();
		tmp = ft_strjoin(args[i], " ");
		line = ft_join(line, tmp);
		free(tmp);
		i++;
	}
	return (line);
}

char	**splitit(char **av)
{
	char	*line;
	char	**container;
	int		i;
	int		j;

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
	return (container);
}
