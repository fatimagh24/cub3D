/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fghanem <fghanem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:28:54 by fghanem           #+#    #+#             */
/*   Updated: 2025/07/24 17:48:44 by fghanem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (0);
	}
	return (1);
}
/*
int main()
{
	char c = '6';
	
	printf("%d\n", ft_isdigit(c));
	printf("%d",isdigit(c));
	return (0);	
}*/
