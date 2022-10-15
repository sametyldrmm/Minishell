/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samet <samet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 19:25:12 by samet             #+#    #+#             */
/*   Updated: 2022/09/07 20:42:40 by samet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_tree_with_pipecount(t_info *info)
{
	int	pipecount;
	int	pipesize;
	int	i;

	i = -1;
	if (info->error)
		return ;
	pipecount = info->cmd_count;
	pipesize = sizeof(t_tree_list);
	info->tree = (t_tree_list *)ft_calloc(pipecount, pipesize);
	if (!info->tree)
	{
		info->error = 1;
		safety_free((void **)&info->tree);
	}
	while (++i < pipecount)
		info->tree[i].prev_fd = -1;
}

void	init_parse_util(t_parse_util *par_v, t_tree *root)
{
	par_v->red_cur = root;
	par_v->cmd_cur = root;
	par_v->temp = NULL;
	par_v->cmd_status = 0;
	par_v->red_status = 0;
	par_v->heredoc_status = 0;
	par_v->heredoc_count = 0;
}
