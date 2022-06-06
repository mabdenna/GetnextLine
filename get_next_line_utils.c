/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdenna <mabdenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 02:13:25 by mabdenna          #+#    #+#             */
/*   Updated: 2022/05/16 05:12:29 by mabdenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	is1;
	size_t	is2;
	size_t	ist;
	char	*ptr;

	if (!s1 || !s2)
		return (NULL);
	is1 = ft_strlen((char *)s1);
	is2 = ft_strlen(s2);
	ist = is1 + is2 + 1 ;
	ptr = malloc(sizeof(char) * ist);
	if (!ptr)
		return (NULL);
	ft_memmove(ptr, s1, is1);
	ft_memmove(ptr + is1, s2, is2);
	ptr[ist - 1] = '\0';
	free ((char *) s1);
	return (ptr);
}

char	*ft_substr(char	const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	i = 0;
	j = (size_t)start;
	if (!s)
		return (NULL);
	while (s[j])
		j++;
	if (start > ft_strlen(s))
		ptr = malloc(sizeof(unsigned char));
	else if (j < len)
		ptr = malloc(sizeof(unsigned char) * j + 1);
	else
		ptr = malloc(sizeof(unsigned char) * len + 1);
	if (!ptr)
		return (NULL);
	while (s[start] != '\0' && i < len && start <= ft_strlen(s))
		ptr[i++] = s[start++];
	ptr[i] = '\0';
	return (ptr);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*p;
	int		i;

	i = 0;
	p = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (p == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;
	unsigned char	*lasts;
	unsigned char	*lastd;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (!d && !s)
		return (dest);
	if (d < s)
		while (len--)
		*d++ = *s++;
	else
	{
		lasts = s + (len - 1);
		lastd = d + (len - 1);
		while (len--)
		*lastd-- = *lasts--;
	}
	return (dest);
}
