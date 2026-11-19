/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahassou <sahassou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 16:28:30 by sahassou          #+#    #+#             */
/*   Updated: 2026/11/12 15:39:30 by sahassou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char	*l1;
	unsigned const char	*l2;
	size_t				i;

	l1 = s1;
	l2 = s2;
	i = 0;
	while (i < n && l1[i] == l2[i])
	{
		i++;
	}
	if (i < n)
	{
		return (l1[i] - l2[i]);
	}
	return (0);
}
