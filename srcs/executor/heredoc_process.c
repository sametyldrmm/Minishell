/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samet <samet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 19:26:18 by samet             #+#    #+#             */
/*   Updated: 2022/09/07 19:26:19 by samet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	heredoc_process(t_info *info)
{
	int	h_cnt;

	h_cnt = info->heredoc_count;
	if (h_cnt == 0)
		return ;
	info->heredoc = (t_heredoc *)ft_calloc(sizeof(t_heredoc), h_cnt + 1);
	run_heredoc(info);
}
