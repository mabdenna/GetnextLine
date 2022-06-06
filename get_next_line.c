/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 05:00:24 by mabdenna          #+#    #+#             */
/*   Updated: 2022/05/16 05:23:41 by mabdenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static int	ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

static char	*lgina_n(char **str)
{
	char	*containere;
	char	*stare;
	int		k;

	k = ft_strchr(*str, '\n');
	containere = *str;
	stare = ft_substr(*str, 0, k + 1);
	*str = ft_substr(*str, k + 1, ft_strlen(*str));
	free (containere);
	containere = NULL;
	return (stare);
}

static char	*malginach_n(char **str)
{
	char	*containere;

	if (*str != NULL && **str != '\0')
	{
		containere = *str;
		*str = NULL;
		return (containere);
	}
	else
	{
		free (*str);
		*str = NULL;
		return (NULL);
	}
}

char	*get_next_line(int fd)
{
	static char	*ptr;
	char		*stare;
	char		buffer[BUFFER_SIZE + 1];
	int			ret;

	if (BUFFER_SIZE < 0 || fd < 0)
		return (NULL);
	if (!ptr)
		ptr = ft_strdup("");
	while (ft_strchr(ptr, '\n') == -1)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret == 0 || ret == -1)
			break ;
		buffer[ret] = '\0';
		ptr = ft_strjoin(ptr, buffer);
	}
	if (ft_strchr(ptr, '\n') == -1)
	{
		stare = malginach_n(&ptr);
		return (stare);
	}
	stare = lgina_n(&ptr);
	return (stare);
}
// int main(void)
// {
// 	int fd = open("hola",2);
// 	char *str = get_next_line(fd);

// 	while(str)
// 	{
// 		printf("%s",str);
// 		str = get_next_line(fd);
// 	}
// }
