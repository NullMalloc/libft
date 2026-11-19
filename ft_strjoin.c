/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahassou <sahassou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 11:32:44 by sahassou          #+#    #+#             */
/*   Updated: 2026/11/15 10:57:30 by sahassou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*p;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	p = malloc(len_s1 + len_s2 + 1);
	if (p == NULL)
	{
		return (NULL);
	}
	ft_memcpy(p, s1, len_s1);
	ft_memcpy(&p[len_s1], s2, len_s2);
	p[len_s1 + len_s2] = '\0';
	return (p);
}

/* #include <stdio.h>
int	main(void)
{
	char *result;

	result = ft_strjoin("str", "join");
	printf("expected: [strjoin][%s]\n", result);
	free (result);
	result = ft_strjoin("", "join");
	printf("expected: [join][%s]\n", result);
	free (result);
	
}

 */