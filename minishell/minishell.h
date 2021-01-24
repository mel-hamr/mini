# ifndef MINISHELL_H
# define MINISHELL_H
#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <stdlib.h>
#define BUFFER_SIZE 50
#include "libft/libft.h"

typedef struct node
{
    char **arg;
    struct node *next;
    struct node *prev;
}               t_node;

typedef struct env
{
    char *value;
    struct env *next;
    struct env *prev;
}               t_env;

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
size_t	        ft_strlen(const char *s);
char	        *ft_strdup(const char *s1);
char			*ft_strtrim(char const *s1, char const *set);
t_env *get_env(char **env,char **argv,int argc);
# endif