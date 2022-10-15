/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samet <samet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 19:25:28 by samet             #+#    #+#             */
/*   Updated: 2022/09/07 20:42:40 by samet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	lexer(t_info *info)
{
	if (check_quote(info))
		return ;
	while (info->input[info->index])
	{
		tokenizer(info);
		info->index++;
	}
	if (!info->tinfo.tokenlist)
	{
		info->error = 1;
		return ;
	}
	validate_syntax(info);
}
