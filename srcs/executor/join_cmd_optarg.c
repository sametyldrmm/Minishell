/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_cmd_optarg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samet <samet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 19:26:25 by samet             #+#    #+#             */
/*   Updated: 2022/09/07 19:26:26 by samet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*join_cmd_optarg(t_tree *node)
{
	char	*cmdopt;
	char	*temp;

	cmdopt = ft_strdup(node->l_child->token);
	temp = cmdopt;
	cmdopt = ft_strjoin(cmdopt, "\n");
	safety_free((void **)&temp);
	if (node->r_child)
	{
		temp = cmdopt;
		cmdopt = ft_strjoin(cmdopt, node->r_child->token);
		safety_free((void **)&temp);
		temp = cmdopt;
		cmdopt = ft_strjoin(cmdopt, "\n");
		safety_free((void **)&temp);
	}
	return (cmdopt);
}
