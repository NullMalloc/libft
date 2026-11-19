/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahassou <sahassou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 15:37:16 by sahassou          #+#    #+#             */
/*   Updated: 2026/11/05 18:20:49 by sahassou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char) c)
		{
			return ((char *) &s[i]);
		}
		i--;
	}
	return (NULL);
}
/* #include <stdio.h>

int	main(void)
{
	char	s[10] = "sammi";
	printf("%s\n", ft_strrchr(s, 'a'));
	printf("%s\n", strrchr("sammi", 'a'));	
} */