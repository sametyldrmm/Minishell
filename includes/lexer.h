/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syildiri <syildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 23:13:46 by syildiri          #+#    #+#             */
/*   Updated: 2022/09/07 23:16:59 by syildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
# include "struct.h"

void	validate_syntax(t_info *info);

t_token	*create_token(int type, char *str);
t_token	*token_add_back(t_token *token, int type, char *str);
void	string_add_back(t_info *info);
void	redirection_add_back(t_info *info);

int		get_qstatus(char c, int qstatus);
int		check_quote(t_info *info);
int		is_in_charset(char c, const char *charset);
int		is_only_space(char *str);
int		is_redirection(int tokentype);

void	tokenizer(t_info *info);

void	lexer(t_info *info);

#endif