/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizing_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samet <samet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 19:25:42 by samet             #+#    #+#             */
/*   Updated: 2022/09/07 20:42:40 by samet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_status;

int	get_qstatus(char c, int qstatus)
{
	if (qstatus == NO_Q)
	{
		if (c == SINGLE_Q)
			qstatus = SINGLE_Q;
		else if (c == DOUBLE_Q)
			qstatus = DOUBLE_Q;
	}
	else if (qstatus == SINGLE_Q)
	{
		if (c == SINGLE_Q)
			qstatus = NO_Q;
	}
	else if (qstatus == DOUBLE_Q)
	{
		if (c == DOUBLE_Q)
			qstatus = NO_Q;
	}
	return (qstatus);
}

int	check_quote(t_info *info)
{
	int	i;

	i = 0;
	while (info->input && info->input[i])
	{
		info->tinfo.qstatus = get_qstatus(info->input[i], info->tinfo.qstatus);
		i++;
	}
	if (info->tinfo.qstatus != NO_Q)
	{
		info->error = 1;
		ft_putendl_fd(UNCLOSED_QUOTE, STDERR_FILENO);
		g_exit_status = 1;
	}
	return (info->error);
}

int	is_only_space(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (!ft_strchr(SPACELIST, str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_redirection(int tokentype)
{
	if (tokentype == INPUT_R
		|| tokentype == OUTPUT_R
		|| tokentype == APPEND_R
		|| tokentype == HEREDOC)
		return (1);
	return (0);
}
