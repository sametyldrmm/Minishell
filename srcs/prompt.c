/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syildiri <syildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 19:24:15 by samet             #+#    #+#             */
/*   Updated: 2022/09/07 23:38:42 by syildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <readline/readline.h>
#include <readline/history.h>

char	*preadline(char *shellname)
{
	char	*cmdline;

	signal(SIGQUIT, SIG_IGN);
	cmdline = readline(shellname);
	set_signal();
	return (cmdline);
}

void	prompt(t_info *info)
{
	while (1)
	{
		init_prompt_cycle(info);
		info->input = preadline("minishell$ ");
		if (!info->input)
		{
			rl_replace_line("", 0);
			printf("exit\n");
			exit(0);
		}
		add_history(info->input);
		lexer(info);
		scanner(info);
		parser(info);
		executor(info);
		terminate_free(info);
	}
}
