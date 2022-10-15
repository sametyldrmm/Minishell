/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samet <samet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 19:26:07 by samet             #+#    #+#             */
/*   Updated: 2022/09/07 20:42:40 by samet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_status;

void	execute(t_info *info)
{
	int	in;
	int	out;
	int	i;

	in = dup(STDIN_FILENO);
	out = dup(STDOUT_FILENO);
	i = -1;
	if (no_fork_cmd(info->tree[0].root) && info->cmd_count == 1)
		preorder_once(info, info->tree[0].root, in, out);
	else
	{
		while (++i < info->cmd_count)
		{
			info->heredoc_offset = info->tree[i].heredoc_offset;
			if (i + 1 < info->cmd_count)
			{
				pipe(info->tree[i].fd);
				info->tree[i + 1].prev_fd = dup(info->tree[i].fd[0]);
				close(info->tree[i].fd[0]);
			}
			fork_cmd(info, i, in, out);
		}
		g_exit_status = check_exit_status(info);
	}
}

void	executor(t_info *info)
{
	if (info->error == 1)
		return ;
	heredoc_process(info);
	execute(info);
}
