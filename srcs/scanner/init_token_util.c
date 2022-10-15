/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_token_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samet <samet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 19:24:50 by samet             #+#    #+#             */
/*   Updated: 2022/09/07 19:24:52 by samet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_expand_token_value(t_expand_token *exp_v)
{
	exp_v->str1 = NULL;
	exp_v->str2 = NULL;
	exp_v->i = 0;
	exp_v->j = 0;
	exp_v->qstatus = NO_Q;
}
