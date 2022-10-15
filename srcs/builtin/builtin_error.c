/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samet <samet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 19:28:04 by samet             #+#    #+#             */
/*   Updated: 2022/09/07 19:28:06 by samet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_error(char *cmd, char *cmd_arg, char *errmsg)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": ", 2);
	if (cmd_arg)
	{
		ft_putstr_fd(cmd_arg, 2);
		ft_putstr_fd(": ", 2);
	}
	ft_putstr_fd(errmsg, 2);
	ft_putstr_fd("\n", 2);
}

void	ft_s_quote_error(char *cmd, char *cmd_arg, char *errmsg)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd("`", 2);
	if (cmd_arg)
		ft_putstr_fd(cmd_arg, 2);
	ft_putstr_fd("'", 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(errmsg, 2);
	ft_putstr_fd("\n", 2);
}
