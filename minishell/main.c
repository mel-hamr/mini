#include "minishell.h"


// char	**exp(t_env *ls)
// {
//     char	**tab;
//     int		i;
//     tab = (char **)malloc(ft_lstsize(ls) * sizeof(char *) +1);
//     i = -1;
//     while (ls)
//     {
//         tab[++i] = ft_strdup(ls->value);
//         ls = ls->next;
//     }
//     tab[++i] = NULL;
//     return (tab);
// }

t_node *new_node()
{
    t_node *tmp;
     tmp = malloc(sizeof(t_node));
    tmp->arg = NULL;
    tmp->next = NULL;
    tmp->prev = NULL;
    return(tmp);
}
t_node *link_node(t_node *first,t_node *next)
{
    t_node *tmp;
     tmp = first;
    while (tmp->next)
    {
        tmp = tmp->next;
    }
    tmp->next = next;
    return(first);
}
t_node *add_arg_cmd(t_node *first,char *str)
{
	t_node *new;
	char **tab;
	int i;
	int j;

	j = 0;
	i = 0;
	new = new_node();
	tab = ft_split(str,' ');
	while (tab[i])
		i++;
	while (first->prev)
		first = first->prev;
	while (first->next)
		first = first->next;
	
	new->arg = (char**)malloc(sizeof(char*) * (i + 1));
	while (j  < i)
	{
		new->arg[j] = ft_strdup(tab[j]);
		j++;
	}
	new->arg[j]= NULL;
	new->prev= first;
	new->next =NULL;
	first->next = new;

	return(first);
}
t_node *check(t_node *first,char *line)
{
	int i;
	int j;
	char **tab;
	char **tab1;


	j=0;
	i= 0;
	while (line[i] )
	{
		if((line[i] == ';' && line[i + 1] == ';') || (line[i] == '|' && line[i + 1] == '|' )
		||(line[i] == ';' && line[i + 1] == '|') || (line[i] == '|' && line[i + 1] == ';') )
		{
				 ft_putstr_fd("error double char:", 2)	;
			//printf("error double char :'%c'\n",line[i]);
			return(NULL);
		}
		i++;
	}
	i=0;
	tab = ft_split_1(line,';','|');
	tab1 = ft_split(tab[0],' ');
	i=0;
	while (tab1[i])
		i++;
	first->arg = (char**)malloc(sizeof(char*) * i + 1 );
	while (j  < i)
	{
		first->arg[j] = ft_strdup(tab1[j]);
		j++;
	}
	first->arg[j]= NULL;
	
	i=1;
	while (tab[i])
	{
		first = add_arg_cmd(first,tab[i]);
		i++;
	}
	
	return (first);
	
}
void printf_arg_cmd(t_node *first)
{
	int i;

	i= 0;
	while (first->prev)
		first = first->prev;
	while (first->next)
	{
		i = 0;
		while (first->arg[i])
		{
			printf("arg [%d]:%s\n",i,first->arg[i]);
			i++;
		}
		printf("\\\\\\\\\\\n");
		first=first->next;
	}
	i = 0;
		while (first->arg[i])
		{
			printf("arg [%d]:%s\n",i,first->arg[i]);
			i++;
		}
}
int main(int argc, char **argv, char **env)
{
	t_env *list;
 	char *line;
	t_node *first;
	
	list=get_env(env,argv,argc);
	while(1)
	{
		first = new_node();
		ft_putstr_fd("\n\033[1;32m$minishell$~> \033[0m", 1);
		get_next_line(0, &line);
		 first = check(first,line);
		 //if(first)
		printf_arg_cmd(first);
		//printf("%s\n",first->cmd);
		//  if(first->arg)
		//  printf("%s\n",first->arg[0]);
		free(first);
	}

	return 0;
}

/* cd pwd echo*/
