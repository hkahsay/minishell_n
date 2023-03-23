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
# define MAROON     "\033[38;2;128;0;0m"
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

//MACROS

# define CLOSED 0
# define OPEN 1

// //assigning integer value to tokens = enumeration

//-------------------LEXER------------------------

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

typedef struct s_token
{
	char			*content;
	t_toktype		id;
	struct s_token	*next;
}	t_token;

//-------------------END OF LEXER------------------------

//-------------------PARSER------------------------------

typedef struct s_cmd
{
	t_token		*args;
	t_toktype	*redir;

} t_cmd;

typedef struct s_redir_type
{
	int					type;
	char				*str;
	struct s_redir_type	*next;
}  t_redir_type;



//-------------------END OF PARSER------------------------


typedef struct s_stringln
{
	char	*str;
	size_t	len;
}	t_stringln;

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

typedef struct s_info
{
	// t_builtin_ptr	builtin[7];
	char			reserved_words[7]; //builtins
	char			**mini_envp;
	struct s_token	*envp_list;
	char			envp_flag;
	char			exit_flag;
	int				status;
	
}t_info;

// typedef struct s_token
// {
// 	void			*key;
// 	void			*value;
// 	struct s_token	*prev;
// 	struct s_token	*next;
// }t_token;

/*copy into my environment*/
t_envnode	*dublicate_env(char **envp);
t_envnode	*create_my_envvar_node(char *key, char *value, int i);
void		free_myenvp(t_envnode *head);

void print_my_envp(t_envnode *temp);

void	prompt(char	*line); //t_envnode *my_envp, 
// t_stringln	*ft_strdup_stringln(const char *str);

// t_token    **ft_split_line(char *str);

//LEXER
t_token    *interp(char *input_str);
char    *skip_spaces(char *str);
char *check_delim(char **p, t_token **head);
int	is_delim_char(char c);
// t_token	*create_list_token(char  *epline); //, int id
// t_token *init_token_redirect(char *epline, int *i);
char *check_quotes(char **p, t_token **head);
int	is_quote(char c);
int eval_quote_type(char *q);
int	get_wordlen(char *p);

//TOKEN
t_token	*init_token(t_token	*token);
t_token *new_token(char *content, t_toktype type);
void add_token(t_token **head, char *content, t_toktype type);
void print_token(t_token *temp);
void add_token(t_token **head, char *content, t_toktype type);
char    *skip_spaces(char *str);
// t_token *ft_split_line(t_token *head, char *input_str, t_toktype *delimiters);
// void	print_tokens(t_token *token_list);

// t_token	*init_token(char *line);
// int	classification(t_token *token, char *line);
// int		ft_strlen(char *str);
// void	ft_putstr_fd(char *str, int fd);
// char	*classification(t_token *token, char *content, int id);
// char	*word_token(char *word);
// int		is_word(const char *str);
// int	is_space(char c);
// char	**ft_split(const char *s, char c);
// int	ft_strlen(const char *str);
// char	*ft_substr(char const *s, unsigned int start, size_t len);

// typedef int(*t_builtin_ptr)(t_llist *, t_info *);

//init minishell
//void	init_minishell();

#endif