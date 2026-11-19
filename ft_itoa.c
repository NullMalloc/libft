/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahassou <sahassou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 13:19:59 by sahassou          #+#    #+#             */
/*   Updated: 2026/11/15 10:59:54 by sahassou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int n)
{
	int	count;

	count = 0;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*p;
	int		count;
	int		i;

	if (n == 0)
		return (ft_strdup("0"));
	count = count_digits(n);
	if (n < 0)
		count++;
	p = malloc(count + 1);
	if (p == NULL)
		return (NULL);
	if (n < 0)
		p[0] = '-';
	else
		n = -n;
	p[count] = '\0';
	i = count - 1;
	while (n != 0)
	{
		p[i] = -(n % 10) + '0';
		n = n / 10;
		i--;
	}
	return (p);
}

/* #include <stdio.h>
int	main(void)
{
	char *s = ft_itoa (-42);
	printf("%s\n", s);
	free (s);
	return (0);
}
 */