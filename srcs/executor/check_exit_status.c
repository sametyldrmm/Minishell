/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exit_status.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samet <samet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 19:25:57 by samet             #+#    #+#             */
/*   Updated: 2022/09/07 19:25:58 by samet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_wifexited(int status)
{
	return ((status & 0177) == 0);
}

int	ft_wifsignaled(int status)
{
	return ((status & 0177) != 0);
}

int	ft_wexitstatus(int status)
{
	return (((status >> 8) & 0x000000ff) % 256);
}

int	ft_wtermsig(int status)
{
	return ((status & 0177) + 128);
}

int	check_exit_status(t_info *info)
{
	int	status;
	int	i;

	i = -1;
	while (++i < info->cmd_count)
	{
		if (waitpid(info->tree[i].pid, &status, 0) == -1)
		{
			ft_putendl_fd("Fail to get exit status", STDERR_FILENO);
			exit(1);
		}
	}
	if (ft_wifexited(status))
		return (ft_wexitstatus(status));
	else if (ft_wifsignaled(status))
		return (ft_wtermsig(status));
	else
		return (status % 128);
}
