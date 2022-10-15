/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syildiri <syildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 19:24:17 by samet             #+#    #+#             */
/*   Updated: 2022/09/08 20:26:00 by syildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	terminate_arg(int argc, char **argv)
{
	if (!argv)
		argc += 1;
	argc = (int)argc;
}

int	main(int argc, char **argv, char **envp)
{
	t_info	info;

	terminate_arg(argc, argv);
	set_signal();
	init_info(&info, envp);
	prompt(&info);
	return (0);
}
