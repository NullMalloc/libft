/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahassou <sahassou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 11:00:59 by sahassou          #+#    #+#             */
/*   Updated: 2026/11/10 16:27:38 by sahassou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*s1;
	size_t				i;

	s1 = s;
	i = 0;
	while (i < n)
	{
		if (s1[i] == (unsigned char) c)
		{
			return ((unsigned char *) &s1[i]);
		}
		i++;
	}
	return (NULL);
}

/* #include <stdio.h>
int	main(void)
{
	char	buf[10] = "ab\0cdab";

	printf("%p %p\n", memchr(buf, 'a', 7), ft_memchr(buf, 'a', 7));
	printf("%p %p\n", memchr(buf, 'c', 7), ft_memchr(buf, 'c', 7));
	printf("%p %p\n", memchr(buf, 'z', 7), ft_memchr(buf, 'z', 7));
	printf("%p %p\n", memchr(buf, 0, 7), ft_memchr(buf, 0, 7));
	printf("%p %p\n", memchr(buf, 'a', 0), ft_memchr(buf, 'a', 0));
	printf("%p %p\n", memchr(buf, 'b' + 256, 7), ft_memchr(buf, 'b' + 256, 7));
	return (0);
} */