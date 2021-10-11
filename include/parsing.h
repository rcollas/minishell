/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 14:31:43 by rcollas           #+#    #+#             */
/*   Updated: 2021/10/11 16:22:28 by rcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H

# define PARSING_H
# define FAIL 0
# define SUCCESS 1
# define FALSE 0
# define TRUE 1

# include <unistd.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "struct.h"

char	*get_valid_envar(t_var *var, char *str, int i);
char	*ft_trim(t_var *var, char *str, int len);
char	*get_var_name(char **env, int i);
char	*get_var_content(char **env, int i);
void	check_s_quote(int *s_quote);
void	check_d_quote(int *d_quote);
void	get_envar_len(int *j, int *i, t_var *var, char *str);
void	skip_alnum(char *str, int *j);
void	free_split(char **split_str);
void	get_env_var(t_var *var, t_envar **envar);
int	get_string_len(char *str, t_var *var);
int	is_valid_dollar(char *str, int i);
int	check_quotes(char *str, int *j, t_var *var);
int	get_arguments(t_var *var);
int	check_unmatched_quotes(t_var *var);

#endif