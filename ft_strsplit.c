/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichebota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 17:53:27 by ichebota          #+#    #+#             */
/*   Updated: 2017/08/19 17:53:30 by ichebota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_wrds(char *buf, char c)
{
	int		ret;
	int		i;

	i = 0;
	ret = 0;
	while (buf[i] == c)
		i++;
	while (buf[i] != '\0')
	{
		if (buf[i] != c && (buf[i + 1] == c || buf[i + 1] == '\0'))
			ret++;
		i++;
	}
	return (ret);
}

int		ft_len(char *tmp, int i, char c)
{
	int		ret;

	ret = 0;
	while (tmp[i] != '\0')
	{
		if (tmp[i] == c)
			return (ret);
		ret++;
		i++;
	}
	return (ret);
}

char	*ft_new_wrd(char *tmp, int i, int len)
{
	char	*ret;
	int		in;

	ret = (char*)malloc(sizeof(char) * len + 1);
	in = 0;
	while (in < len)
	{
		ret[in] = tmp[i];
		i++;
		in++;
	}
	ret[in] = '\0';
	return (ret);
}

char	**ft_strsplit(char const *s, char c)
{
	char	*tmp;
	char	**ret;
	int		len;
	int		i;
	int		j;

	tmp = (char*)s;
	i = 0;
	j = 0;
	if ((ret = (char**)malloc(sizeof(char*) * ft_count_wrds(tmp, c) + 1)) == 0)
		return (NULL);
	while (tmp[i] != '\0')
	{
		while (tmp[i] == c)
			i++;
		len = ft_len(tmp, i, c);
		if ((ret[j] = ft_new_wrd(tmp, i, len)) == NULL)
			return (NULL);
		i = i + len;
		j++;
	}
	ret[j] = NULL;
	return (ret);
}
