/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samet <samet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 19:28:01 by samet             #+#    #+#             */
/*   Updated: 2022/09/07 19:28:02 by samet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_env(char **argv, t_env_list *env_head)
{
	if (!argv)
		return (0);
	if (argv[1])
	{
		ft_error("env", argv[1], strerror(2));
		return (127);
	}
	while (env_head)
	{
		ft_putstr_fd(env_head->key, STDOUT_FILENO);
		ft_putstr_fd("=", STDOUT_FILENO);
		if (env_head->value && env_head->value[0])
			ft_putstr_fd(env_head->value, STDOUT_FILENO);
		ft_putstr_fd("\n", STDOUT_FILENO);
		env_head = env_head->next;
	}
	return (0);
}
