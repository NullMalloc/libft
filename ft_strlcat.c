/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahassou <sahassou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 10:32:00 by sahassou          #+#    #+#             */
/*   Updated: 2026/11/07 16:56:15 by sahassou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)

{
	size_t	i;
	size_t	dst_len;

	i = 0;
	dst_len = ft_strlen(dst);
	if (size <= dst_len)
	{
		return (size + ft_strlen(src));
	}
	while (i < size - dst_len -1 && src[i] != '\0')
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + ft_strlen(src));
}

/* #include <stdio.h>
#include <bsd/string.h>

int	main(void)
{
	char dst[50] = "sa";
	char src[50] = "mi";
	char dst2[50] = "sa";
	size_t	k;
	k = 0;
	
	printf("\n");
	printf("%zu %s\n", ft_strlcat(dst, src, 7), dst);
	printf("%zu %s\n", strlcat(dst2, src, 7), dst2);
	while (k < 8)
	{
		if (dst[k] == '\0')
			printf("[%zu]=\\0 ", k);
		else
			printf("[%zu]=%c ", k, dst[k]);
		k++;
	}

}
 */