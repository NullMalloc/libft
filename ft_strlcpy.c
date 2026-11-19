/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahassou <sahassou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 18:25:16 by sahassou          #+#    #+#             */
/*   Updated: 2026/11/07 10:31:08 by sahassou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)

{
	size_t	i;

	i = 0;
	if (size == 0)
	{
		return (ft_strlen(src));
	}
	while (i < size -1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

/* #include <stdio.h>
#include <bsd/string.h>

int	main(void)
{
	char d [50] = "Sami";
	char s [50] = "majorant";
	char c [50] = "Sami";
	printf("%zu %s\n", ft_strlcpy(d, s, 4), d);
	printf("%zu %s\n", strlcpy(c, s, 4), c);
} */