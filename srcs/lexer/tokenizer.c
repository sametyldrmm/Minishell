/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samet <samet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 19:25:32 by samet             #+#    #+#             */
/*   Updated: 2022/09/07 19:25:33 by samet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	tokenizer(t_info *info)
{
	t_token_info	*tinfo;

	tinfo = &info->tinfo;
	tinfo->qstatus = get_qstatus(info->input[info->index], tinfo->qstatus);
	if (tinfo->qstatus == NO_Q
		&& ft_strchr(SEPLIST, info->input[info->index]))
	{
		if (info->input[info->index] == PIPE)
		{
			tinfo->tokenlist = token_add_back(tinfo->tokenlist, PIPE, "|");
			info->cmd_count++;
		}
		else
			redirection_add_back(info);
	}
	string_add_back(info);
}
