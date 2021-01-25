# ifndef MINISHELL_H
# define MINISHELL_H
#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <stdlib.h>
#define BUFFER_SIZE 50
#include "libft/libft.h"
#define LESS 4
#define GREAT 7
#define PIPE 1
#define DOUBLE_GREAT 77
#define CMD 2
#define SEP 5
#define ARG 3
typedef struct token
{
    int type;
    char *str;
    struct token *next;
    struct token *prev;
}               t_token;

typedef struct env
{
    char *value;
    struct env *next;
    struct env *prev;
}               t_env;

typedef struct minishell
{
    t_env   *env;
    t_token *token;
}   t_mini;

void            check_fir(t_mini *mini,char *line);
void            check_sec(t_mini  *mini);
t_token         *add_arg_cmd(t_token *first,char *str);
t_token         *new_token();
size_t	        ft_strlen(const char *s);
t_env           *get_env(char **env,char **argv,int argc);
char             *fix_line(char *line);
int             indexof(char *str, char c);
int             ft_strcmp(const char *s1, const char *s2);
void			ft_putstr_fd(char *s, int fd);
char			*ft_chr(const char *s, int c);
char			*str_get(char *rest, int i, char **line);
int				get_next_line(int fd, char **line);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			**ft_split(char const *s, char c);
char			**ft_split_1(char  *s, char c, char c1);
char	        *ft_strdup(const char *s1);
char			*ft_strtrim(char const *s1, char const *set);
int			    skip_quots(char *str, char c, int i);
int             ft_isalpha(int c);
# endif