/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fghanem <fghanem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 11:33:43 by fghanem           #+#    #+#             */
/*   Updated: 2025/08/25 12:57:26 by fghanem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s)
{
	int	i;
	int	res;
	int	sig;

	i = 0;
	res = 0;
	sig = 1;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sig = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = res * 10 + (s[i] - '0');
		i++;
	}
	return (res * sig);
}
/*
#include <stdio.h>
#include <stdlib.h>
int main()
{
	char c[] = "-2345jkdf";
	printf("%d\n",ft_atoi(c));
	printf("%d", atoi(c));
	return (0);
}*/
