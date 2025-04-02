/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:02:42 by joao-alm          #+#    #+#             */
/*   Updated: 2025/04/01 11:57:18 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "jal_list.h"
# include "util.h"

# define NAME "favela_shell"
# define PROMPT "\033[38;5;228mfavela_shell\033[0m\033[38;5;121m ❯ \033[0m"

typedef enum e_token_type
{
	TOKEN_WORD,
	TOKEN_SQUOTE,
	TOKEN_DQUOTE,
	TOKEN_PIPE,
	TOKEN_REDIRECT_IN,
	TOKEN_REDIRECT_OUT,
	TOKEN_APPEND,
	TOKEN_HEREDOC
}					t_token_type;

typedef struct s_token
{
	t_token_type	type;
	char			*value;
}					t_token;

typedef struct s_command
{
	char			*cmd;
	char			**args;
	int				input_fd;
	int				output_fd;
}					t_command;

typedef struct s_program
{
	t_list			*token_list;
	t_list			*command_list;
	int				exit_code;
}					t_prog;

// command #####################################################################

// command ---------------------------------------------------------------------
t_list				*ft_commands_from_tokens(t_list **token_list);
// command_util ----------------------------------------------------------------
t_command			*ft_init_command();
void				ft_free_command(void *command);

// main ########################################################################

// init ------------------------------------------------------------------------
void				ft_init_prog(t_prog *prog);

// parser ######################################################################

// parser ----------------------------------------------------------------------
t_list				*ft_parser(const char *input);
// lexer -----------------------------------------------------------------------
int					ft_lexer(t_list **token_list, const char *input);
// token_utils -----------------------------------------------------------------
t_token_type		ft_get_token_type(char *s);
t_token				*ft_new_token(const t_token_type type, char *value);
void				ft_free_token(void *token);
// quote_handler ---------------------------------------------------------------
int					ft_process_quotes(t_token *token);
// quote_util ------------------------------------------------------------------
int					ft_is_quote(char c);
char				*ft_remove_quotes(char *str, char quote_type);
int					ft_count_quotes(const char *str, char quote_type);
// expander --------------------------------------------------------------------
char				*ft_expand_str(const char *str);
// expander utils --------------------------------------------------------------
char				*ft_get_env_value(const char *var_name);
int					ft_get_var_name_len(const char *str);
char				*ft_charjoin(char *s, char c);

#endif // MINISHELL_H
