/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samet <samet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 19:27:58 by samet             #+#    #+#             */
/*   Updated: 2022/09/07 20:42:40 by samet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_echo(char **argv)
{
	int	newline_flag;
	int	i;

	newline_flag = 0;
	i = 1;
	if (argv[1] == NULL)
	{
		ft_putendl_fd("", STDOUT_FILENO);
		return (0);
	}
	if (argv[i] && !ft_strncmp(argv[i], "-n", 3))
	{
		newline_flag = 1;
		++i;
	}
	while (argv[i])
	{
		ft_putstr_fd(argv[i], STDOUT_FILENO);
		if (argv[i + 1])
			ft_putstr_fd(" ", STDOUT_FILENO);
		i++;
	}
	if (!newline_flag)
		write(STDOUT_FILENO, "\n", 1);
	return (0);
}
