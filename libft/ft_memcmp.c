/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fghanem <fghanem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 11:21:31 by fghanem           #+#    #+#             */
/*   Updated: 2025/08/25 13:11:58 by fghanem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ss1;
	unsigned char	*ss2;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	while (n)
	{
		if (*ss1 != *ss2)
		{
			return (*ss1 - *ss2);
		}
		--n;
		++ss1;
		++ss2;
	}
	if (n)
	{
		return (*ss1 - *ss2);
	}
	else
		return (0);
}
