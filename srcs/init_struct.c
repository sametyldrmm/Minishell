/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samet <samet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 19:24:20 by samet             #+#    #+#             */
/*   Updated: 2022/09/07 20:41:24 by samet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_prompt_cycle(t_info *info)
{
	info->error = 0;
	info->index = 0;
	info->tinfo.qstatus = NO_Q;
	info->tinfo.tokenlist = NULL;
	info->tree = NULL;
	info->cmd_count = 1;
	info->input = NULL;
	info->heredoc_offset = 0;
}
