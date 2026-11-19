/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahassou <sahassou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 18:23:23 by sahassou          #+#    #+#             */
/*   Updated: 2026/11/13 09:27:56 by sahassou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*p;

	i = ft_strlen(s);
	p = malloc(i + 1);
	if (p == NULL)
	{
		return (NULL);
	}
	ft_memcpy(p, s, i + 1);
	return (p);
}

/* #include <stdio.h>

int	main(void)
{
	char *real;
	char *mine;
	
	real = strdup("lets11");
	mine = ft_strdup("lets11");
	printf("real:%s\n", real);
	printf("mine:%s\n", mine);
	free(real);
	free(mine);
	return (0);
}
 */