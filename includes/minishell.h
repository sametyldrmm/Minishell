/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syildiri <syildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 23:13:52 by syildiri          #+#    #+#             */
/*   Updated: 2022/09/07 23:21:53 by syildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <dirent.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/wait.h>

# include "libft.h"
# include "struct.h"
# include "constant.h"
# include "lexer.h"
# include "parser.h"
# include "scanner.h"
# include "builtin.h"
# include "executor.h"

void	signal_handler(int signum);
void	set_signal(void);

char	*preadline(char *shellname);
void	prompt(t_info *info);

void	init_info(t_info *info, char **envp);

int		is_redirection(int tokentype);
void	terminate_error(char *str);

void	init_prompt_cycle(t_info *info);
void	terminate_free(t_info *info);

void	lexer(t_info *info);
void	safety_free(void **data);
void	safety_free_doublearray(void ***data);

void	scanner(t_info *info);
void	execute(t_info *info);

char	**split_optarg(char *str);

void	parser(t_info *info);

/* LEXER */

#endif