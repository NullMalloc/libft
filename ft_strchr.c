/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahassou <sahassou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 22:00:29 by sahassou          #+#    #+#             */
/*   Updated: 2026/11/12 15:37:32 by sahassou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
		{
			return ((char *) &s[i]);
		}
		i++;
	}
	if (s[i] != (char) c)
	{
		return (NULL);
	}
	return ((char *) &s[i]);
}
/* #include <stdio.h>

int main(void)
{
	printf("%s", ft_strchr("sami", 'a' + 256));
	printf("%s", strchr("sami", 'a' + 256));
} */