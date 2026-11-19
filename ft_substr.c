/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahassou <sahassou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 15:22:38 by sahassou          #+#    #+#             */
/*   Updated: 2026/11/14 11:22:34 by sahassou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	len_s;

	len_s = ft_strlen(s);
	if (start >= len_s)
	{
		return (ft_strdup(""));
	}
	if (len > len_s - start)
	{
		len = len_s - start;
	}
	p = malloc(len + 1);
	if (p == NULL)
	{
		return (NULL);
	}
	ft_memcpy(p, &s[start], len);
	p[len] = '\0';
	return (p);
}

/* #include <stdio.h>

int	main(void)
{
	char *mine;
	char *result;

	mine = "easybaby";
	result = ft_substr(mine, 0, 100);
	printf("%s\n", result);
	free (result);
	return (0);
}
 */