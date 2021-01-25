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
// int get_env_variable(t_env *env, char *arg_var)
// {
//     struct env *tmp_n;
//     t_env *tmp_env;
//     char *var;
//     while (env->prev)
//         env = env->prev;
//     while (env)
//     {
//         tmp_n = env->next;
//         tmp_env = env;
//         var = ft_substr((char *)env->value, 0, indexof(env->value, '='));
//         if (!ft_strcmp(var, arg_var))
//         {
//             env = env->prev;
//             env->next = tmp_env->next;
//             env = tmp_env->next;
//             if (tmp_env->next)
//                 env->prev = tmp_env->prev;
//             free(tmp_env);
//             return (1);
//         }
//         env = env->next;
//     }
//     return (0);
// }
void get_first(t_env **env)
{
	while ((*env)->prev)
	{
		(*env) = (*env)->prev;
	}
	
}
void printf_arg_cmd(t_token *first)
{
	int i;

	i= 0;
	while (first->prev)
		first = first->prev;
	while (first->next)
	{
		printf("type=%d\n",first->type);
		printf("str=%s\n",first->str);
		printf("=============================\n");
		first=first->next;
	}
	printf("type=%d\n",first->type);
	printf("str=%s\n",first->str);
	printf("=============================\n");
	i = 0;
}
void test(t_token *token)
{
		while (token->prev)
		token = token->prev;
}
int main(int argc, char **argv, char **env)
{
	t_mini mini;
 	char *line;
	int s;
	// t_env *temp;
	s = 1;
	mini.env=get_env(env,argv,argc);
	//get_first(&list);
	// temp = mini.env;
	// while (temp->prev)
	// 	temp = temp->prev;
		
	// while (temp)
	// {
	// 	printf("%s\n",temp->value);
	// 	temp= temp->next;
	// }
	
	while(1)
	{
		mini.token = new_token();
		ft_putstr_fd("\n\033[1;32m$minishell$~> \033[0m", 1);
		get_next_line(0, &line);
		//printf("|%s|\n",line);
		if(line[0] != '\0')
		{
			//puts("here");
			check_fir(&mini,line);
			check_sec(&mini);
			// printf("%s\n",mini.token->str);
			// test(mini.token);
			// printf("%s\n",mini.token->str);

			printf_arg_cmd(mini.token);
			free(mini.token);
		}//if(token)
	}
	return 0;
}