/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahassou <sahassou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 19:18:21 by sahassou          #+#    #+#             */
/*   Updated: 2026/11/03 21:34:55 by sahassou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	{
		if (c >= 'a' && c <= 'z')
		{
			return (c - 32);
		}
	}
	return (c);
}
/*#include <stdio.h>
int	main(void)
{
	printf("%c", ft_toupper('m'));
}*/