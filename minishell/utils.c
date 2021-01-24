#include "minishell.h"

void	ft_putstr_fd(char *s, int fd)
{
	int i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}


static	int		checkset(char c, char *set)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	char	*cpyset;
	int		len;

	str = ft_strdup(s1);
	if (str == NULL)
		return (NULL);
	cpyset = (char *)set;
	while (checkset(str[0], cpyset) == 1)
		str++;
	len = ft_strlen(str) - 1;
	while (len > 0)
	{
		if (checkset(str[len], cpyset) == 0)
			break ;
		str[len] = '\0';
		len--;
	}
	return (ft_strdup(str));
}


