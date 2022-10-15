/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_optarg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samet <samet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 19:27:47 by samet             #+#    #+#             */
/*   Updated: 2022/09/07 19:27:49 by samet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_optarg(char *str)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (str && str[i])
	{
		if (str[i] == '\n')
			cnt++;
		i++;
	}
	return (cnt);
}

char	*strdup_optarg(char *str, int len)
{
	if (len == 0)
		return (ft_strdup(""));
	else
		return (ft_strndup(str, len));
}

char	**split_optarg(char *str)
{
	char	**ret;
	int		i;
	int		j;
	int		cur;

	i = 0;
	j = 0;
	cur = 0;
	ret = (char **)ft_calloc(count_optarg(str) + 1, sizeof(char *));
	while (str && str[j])
	{
		if (str[j] == '\n')
		{
			ret[cur] = strdup_optarg(&str[i], j - i);
			cur++;
			i = j + 1;
		}
		j++;
	}
	return (ret);
}
