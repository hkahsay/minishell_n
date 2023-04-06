#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/uio.h>
# include "../libft/libft.h"

# define WHITE      "\033[38;2;255;255;255m"
# define BLACK      "\033[38;2;0;0;0m"
# define R        "\033[38;2;255;0;0m"
# define LIME       "\033[38;2;0;255;0m"
# define BLUE       "\033[38;2;0;80;255m"
# define YELLOW     "\033[38;2;255;255;0m"
# define GCYAN      "\033[38;2;0;164;114m"
# define MAGENTA    "\033[38;2;255;0;255m"
# define SILVER     "\033[38;2;192;192;192m"
# define GRAY       "\033[38;2;128;128;128m"
# define MAR     "\033[38;2;128;0;0m"
# define OL      "\033[38;2;128;128;0m"
# define GREEN      "\033[38;2;0;128;0m"
# define PURPLE     "\033[38;2;128;0;128m"
# define TEAL       "\033[38;2;0;128;128m"
# define NAVY       "\033[38;2;0;0;128m"
# define DB         "\033[38;2;0;0;139m"
# define LC         "\033[38;2;224;255;255m"
# define MBLUE      "\033[38;2;58;62;92m"
# define LBLUE      "\033[38;2;114;121;179m"
# define GGREEN     "\033[38;2;14;195;6m"
# define OR	"\033[38;5;208m"

# define RS      "\033[0m"
# define clear() printf("\033[H\033[J");

#define MAXLINE 1024
#define MAXARGS 100
//---------------built-in----------------
// # define PWD 1
// # define CD 2
// # define CMD_ECHO 3
// # define UNSET 4
// # define EXPORT 5
// # define ENV 6
// # define EXIT 7

//-------------------MY_ENV-----------------------

typedef struct s_envnode
{
	char *key;
	char *value;
	struct s_envnode *prev;
	struct s_envnode *next;
} t_envnode;

typedef struct s_prompt
{
	int			nbr_elm;
	char		*str;
}	t_prompt;


//-------------------LEXER------------------------

# define CLOSED 0
# define OPEN 1

// //assigning integer value to tokens = enumeration

typedef enum	e_toktype
{
	TOK_ERROR,
	TOK_WORD,
	TOK_D_QUOTE,
	TOK_S_QUOTE,
	TOK_REDIR_OUT,
	TOK_REDIR_IN,
	TOK_REDIR_OUT_APPEND,
	TOK_HEREDOC,
	TOK_PIPE,
	TOK_SPACE,
	TOK_ERRQUOTE
	// TOK_UNKNOWN = 9
}	t_toktype;

typedef	struct s_delim
{
	char		*delim_str;
	int			delim_len;
	t_toktype	delim_type;
} t_delim;

typedef	struct s_quote
{
	char		*quote_str;
	int			quote_len;
	t_toktype	quote_type;
} t_quote;


// //define the delimiters as an array of t_toktype values
// t_delim delimiters[] = {
//     {">>", 2, TOK_REDIR_OUT_APPEND},
//     {"<<", 2, TOK_HEREDOC},
// 	{">", 1, TOK_REDIR_OUT},
//     {"<", 1, TOK_REDIR_IN},
//     {"|", 1, TOK_PIPE}
// };

    // {TOK_DQUOTE, "\"", 1},
	// {TOK_SQUOTE, "\'", 1},

typedef struct s_token
{
	char			*content;
	t_toktype		id;
	struct s_token	*next;
}	t_token;

//-------------------PARSER------------------------------

// typedef struct s_redir_args
// {
// 	int						type;
// 	char					*args;
// 	struct s_redir_args		*next;
// }  t_redir_args;

typedef struct s_wr_node
{
	int					type;
	char				*file;
	int					close_fd;
	struct s_wr_node	*next;
}  t_wr_node;

typedef struct s_cmd
{
	t_wr_node	*cmd_wnode;
	t_wr_node	*cmd_rnode;
	struct s_cmd	*next;
} t_cmd;

typedef struct	s_pline
{
	int			pline_index;
	t_cmd		*pline_cmd_node;
	struct s_pline	*next;
} t_pline;

// typedef enum e_builtin_type
// {
// 	PWD,
// 	CD,
// 	ECHO,
// 	UNSET,
// 	EXPORT,
// 	ENV,
// 	EXIT
// } t_builtin_type;

// typedef	struct s_builtin_ptr
// {
	
// 	t_builtin_cmd	builtins_type;
// } t_builtin_ptr;

typedef int (*builtin_func)(char **, t_envnode **);

typedef struct s_builtin
{
    const char *name;
    builtin_func func;
} t_builtin;

// typedef struct s_info
// {
// 	// t_builtin_ptr	builtin[7];
// 	// char			*builtins_cmds[]; //builtins
// 	t_builtin_ptr	*builtins;
// 	char			**mini_envp;
// 	struct s_token	*envp_list;
// 	char			envp_flag;
// 	char			exit_flag;
// 	int				status;
	
// }t_info;

// typedef struct s_stringln
// {
// 	char	*str;
// 	size_t	len;
// }	t_stringln;


/*MY_ENV*/
void ft_putchar(char c);
int    ft_putstr(char *str);
t_envnode	*dublicate_env(char **envp);
t_envnode	*create_mini_envvar_node(char *key, char *value);
void		free_mini_envp(t_envnode *head);
t_envnode	*find_env_var(char *key, t_envnode *current_dir);
void 		print_mini_envp(t_envnode *temp);
void 		update_env_var(char *key, char *value);
void 		ft_add_envlist(t_envnode *new_node, t_envnode **env);
int 		ft_setenv(char *name, char *value, t_envnode **env);
/*PROMPT*/
void	prompt(char	*line, t_envnode *my_envp); //, t_envnode *my_envp
/*LEXER*/
void interp(char *line, t_envnode *mini_env);
char    *skip_spaces(char *str);
int	is_space(char c);

char *check_delim(char **p, t_token **head);
int	is_delim_char(char c);
// t_token	*create_list_token(char  *epline); //, int id
// t_token *init_token_redirect(char *epline, int *i);
char *check_quotes(char **p, t_token **head);
int	is_quote(char c);
int eval_quote_type(char *q);
int	get_wordlen(char *p);
t_token    *expand_token_list(t_token *token_head, t_envnode *mini_env); //
size_t	ft_strcspn(const char *str, const char *charset);
char	*ft_strncpy(char *dest, const char *src, size_t n);
/*TOKEN*/
t_token	*init_token(t_token	*token);
t_token *new_token(char *content, t_toktype type);
t_token *last_token(t_token *token_list);
void add_token(t_token **head, char *content, t_toktype type);
void print_token(t_token *temp);
void	free_token_list(t_token *tokens);
char	*get_next_token(t_token *token, char *temp);

// void	print_tokens(t_token *token_list);

/*PARSER*/
void	*parse(t_token **token_head, t_envnode *mini_env);
/*INIT_PARSE*/
t_cmd		*init_cmd(void);
t_wr_node	*init_wr_node(t_wr_node *new_wr_node);
char *strndup(const char *str, size_t n);

/*ADD WNODE*/
t_wr_node	*add_w_to_cmd_wnode(t_token **head, t_cmd **cmd, t_wr_node **head_wnode, int id, char *word);
t_wr_node	*check_$_add_w_to_cmd_wnode(t_token **head, t_cmd **cmd, t_wr_node **head_wnode, int id, char *word);
t_wr_node	*fill_wr_node(t_wr_node **wr_node, int id, char *word);
char    **create_array(t_cmd **node);
int ft_list_size(t_cmd *node);

/*EXECUTER*/
void execute(t_cmd *cmd, t_envnode *mini_env);
// t_cmd_node	*parse(char *line, t_cmd_node *first_cmd);
// int	empty_str(char *str);
// t_redir_args	*eval_token(t_token *head);
//-----------built_in-----------------
// int	mini_pwd2(t_envnode *env_list);
// int is_builtins(t_builtin_cmds commands);
// int	ft_cd(char **args, t_envnode *env_list);
// int ft_echo(t_cmd *cmds);//, t_envnode *env
// int count_char(char *str, char c);
// int	export(t_cmd *cmd, t_envnode *env_var);
// int	ft_unset(t_cmd *cmd, t_envnode *env_var);
int is_builtin(char **cmd, t_envnode *env_var);
int ft_pwd(char **args, t_envnode **env_var);
int ft_cd(char **args, t_envnode **env_var);
int ft_echo(char **args, t_envnode **env_var);
int ft_unset(char **args, t_envnode **env_var);
int ft_export(char **cmd_args, t_envnode **mini_env);
int ft_env(char **args, t_envnode **env_var);
int ft_exit(char **args, t_envnode **env_var);


void	print_cmd(t_cmd *cmd);
void	print_array(char **array);
// 
// int	b_cd(t_envnode *list, char *input)

int ft_strcmp(const char *s1, const char *s2);


// int	mini_pwd(void);


// t_cmd	*tok_parser(char *input);
// t_parser	*init_parser(t_parser *parse);
// char	*new_parser(t_parser *parse, char *line);
// typedef int(*t_builtin_ptr)(t_llist *, t_info *);

//init minishell
//void	init_minishell();

#endif