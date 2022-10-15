/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syildiri <syildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 23:13:55 by syildiri          #+#    #+#             */
/*   Updated: 2022/09/07 23:16:52 by syildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "minishell.h"

void	init_tree_with_pipecount(t_info *info);
void	init_parse_util(t_parse_util *par_v, t_tree *root);

t_tree	*create_node(int type, char *token, t_info *info);
void	add_cmd_arg(t_tree **parent, char *s, t_info *info);
void	add_cmd_node(t_tree **parent, char *s, int t, t_info *info);
void	add_arg_node(t_tree **parent, char *s, int t, t_info *info);
void	add_red_node(t_tree **parent, char *s, int t, t_info *info);

void	build_tree(t_info *info);

#endif