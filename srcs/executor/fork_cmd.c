/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samet <samet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 19:26:11 by samet             #+#    #+#             */
/*   Updated: 2022/09/07 19:26:12 by samet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_exit_status;

void	set_pipe(t_info *info, int i)
{
	if (info->tree[i].prev_fd > -1)
	{
		dup2(info->tree[i].prev_fd, 0);
		close(info->tree[i].prev_fd);
	}
	if (i + 1 < info->cmd_count)
	{
		dup2(info->tree[i].fd[1], 1);
		close(info->tree[i].fd[0]);
		close(info->tree[i].fd[1]);
	}
}

void	fork_cmd(t_info *info, int i, int in, int out)
{
	info->tree[i].pid = fork();
	if (info->tree[i].pid < 0)
		exit(1);
	else if (info->tree[i].pid == 0)
	{
		set_pipe(info, i);
		preorder(info, info->tree[i].root);
		exit(g_exit_status);
	}
	else
	{
		if (i + 1 < info->cmd_count)
		{
			close(info->tree[i].fd[0]);
			close(info->tree[i].fd[1]);
		}
		dup2(in, STDIN_FILENO);
		dup2(out, STDOUT_FILENO);
		close(in);
		close(out);
	}
}
