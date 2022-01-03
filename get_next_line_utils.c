/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaamaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 16:20:59 by rnaamaou          #+#    #+#             */
/*   Updated: 2021/12/28 16:21:03 by rnaamaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strdup(const char *src)
{
	int		i;
	int		j;
	char	*dest;

	i = 1;
	j = 0;
	while (src[j])
	{
		i++;
		j++;
	}
	dest = (char *)malloc (i * sizeof(char));
	if (dest == 0)
		return (0);
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	int	index;

	index = 0;
	while (s[index] != '\0')
	{
		if (s[index] == (char)c)
			return ((char *)(s + index));
		index++;
	}
	if (s[index] == (char)c)
		return ((char *)(s + index));
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	len_f;
	char	*str;

	if (!s1)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	len_f = len_s2 + len_s1 + 1;
	str = (char *)malloc(sizeof(char) * len_f);
	if (str == NULL)
		return (NULL);
	len_s1 = 0;
	len_s2 = 0;
	len_f = 0;
	while (s1[len_s1])
		str[len_f++] = s1[len_s1++];
	while (s2[len_s2])
		str[len_f++] = s2[len_s2++];
	str[len_f] = 0;
	free ((char *)s1);
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	index_s;
	size_t			index_l;

	index_l = 0;
	index_s = 0;
	if (!s)
		return (NULL);
	if (len <= ft_strlen(s + start))
		str = (char *)malloc(sizeof(char) * (len + 1));
	else
		str = (char *)malloc(sizeof(char) * (ft_strlen(s + start) + 1));
	if (str == NULL)
		return (NULL);
	while (s[index_s])
	{
		if (index_s >= start && index_l < len)
		{
			str[index_l] = s[index_s];
			index_l++;
		}
		index_s++;
	}
	str[index_l] = 0;
	return (str);
}
