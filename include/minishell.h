#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>

/* Macros para indicar sucesso e erro */
# define SUCCESS 0
# define ERROR 1

/* Tipos de tokens */
typedef enum e_token_type 
{
	TOKEN_WORD,
	TOKEN_PIPE,
	TOKEN_REDIRECT_IN,
	TOKEN_REDIRECT_OUT,
	TOKEN_APPEND,
	TOKEN_HEREDOC,
	TOKEN_PAREN_OPEN,
	TOKEN_PAREN_CLOSE,
	TOKEN_LOGIC
}	t_token_type;

/* Estrutura para tokenização */
typedef struct s_token
{
	char			*value;
	t_token_type	type;
	struct s_token	*next;
}	t_token;

/* Forward declaration para evitar dependências circulares */
typedef struct s_shell t_shell;

/* Estrutura para comandos */
typedef struct s_command
{
	char				*cmd;
	char				**args;
	char				*path;
	int					type;  /* Indica se é built-in, externo ou operador lógico */
	char				*logic; /* "&&" ou "||" para nós lógicos */
	struct s_command	*left;  /* Para árvore de operadores lógicos */
	struct s_command	*right; /* Para árvore de operadores lógicos */
	struct s_command	*next;  /* Para comandos sequenciais */
	t_shell				*shell; /* Referência para a estrutura principal */
}	t_command;

/* Estrutura principal do shell */
typedef struct s_shell
{
	t_command	*commands;
	char		**env;
	int			last_status;
}	t_shell;

/* Protótipos das funções de inicialização e finalização */
int		init_shell(t_shell *shell, char **envp);
void	free_shell(t_shell *shell);
void	cleanup_shell(t_shell *shell);
void	setup_signals(void);

/* Protótipos do Parser */
int		parse_input(t_shell *shell, char *line);
t_token	*tokenize_line(char *line);
int		build_commands(t_shell *shell, t_token *tokens);
void	free_tokens(t_token *tokens);

/* Protótipos do Parser (Bônus) */
int		parse_bonus_logic(t_token **tokens, t_command **cmd_tree);

/* Protótipos do Executor */
int		execute_commands(t_shell *shell);
int		execute_external(t_command *cmd, t_shell *shell);

/* Protótipos do Executor (Bônus) */
int		executor_bonus(t_command *cmd_tree, t_shell *shell);

/* Protótipos dos Builtins */
int		is_builtin(const char *cmd);
int		execute_builtin(t_command *cmd, t_shell *shell);
int		builtin_echo(char **args);
int		builtin_cd(char **args, t_shell *shell);
int		builtin_pwd(void);
int		builtin_export(char **args, t_shell *shell);
int		builtin_unset(char **args, t_shell *shell);
int		builtin_env(t_shell *shell);
int		builtin_exit(char **args, t_shell *shell);

/* Protótipos das Utils */
char	**expand_wildcards(const char *pattern);
int		has_wildcard(const char *cmd);

#endif
