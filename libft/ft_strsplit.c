/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 13:43:45 by csinglet          #+#    #+#             */
/*   Updated: 2018/04/21 13:43:46 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_wrdcount(char const *str, char c)
{
	int				count;

	if (str == NULL)
		return (0);
	count = 0;
	while (*str)
	{
		while (*str == c && *str)
			str++;
		if (*str)
			count++;
		while (*str != c && *str)
			str++;
	}
	return (count);
}

static int		ft_wrdlen(char const *str, char c)
{
	int				len;

	len = 0;
	while (str[len] != c && str[len] != '\0')
		len++;
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char			**splits;
	int				word_count;
	int				index;

	if (s == NULL)
		return (0);
	word_count = ft_wrdcount(s, c);
	index = 0;
	if (!(splits = (char **)malloc((sizeof(char *) * (word_count + 1)))))
		return (0);
	while (index < word_count)
	{
		while (*s == c && *s != '\0')
			s++;
		splits[index] = ft_strsub(s, 0, ft_wrdlen(s, c));
		if (splits[index] == NULL)
			return (0);
		s += ft_wrdlen(s, c);
		index++;
	}
	splits[index] = NULL;
	return (splits);
}
