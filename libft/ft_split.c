/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fghanem <fghanem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:40:44 by fghanem           #+#    #+#             */
/*   Updated: 2025/08/25 13:13:44 by fghanem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wcount(const char *s, char c)
{
	int	ct;

	ct = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s != '\0')
			ct++;
		while (*s && *s != c)
			s++;
	}
	return (ct);
}

static char	*ft_wdup(const char *s, size_t len)
{
	char	*wd;

	wd = (char *)malloc(len + 1);
	if (!wd)
		return (NULL);
	ft_memcpy(wd, s, len);
	wd[len] = '\0';
	return (wd);
}

static int	ft_check(char **s, size_t i)
{
	if (!s[i])
	{
		while (i-- > 0)
			free(s[i]);
		free(s);
		return (0);
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char		**res;
	size_t		i;
	const char	*start;

	i = 0;
	res = (char **)malloc((ft_wcount(s, c) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s)
		{
			start = s;
			while (*start != '\0' && *start != c)
				start++;
			res[i++] = ft_wdup(s, (start - s));
			if (!ft_check(res, i - 1))
				return (NULL);
			s = start;
		}
	}
	res[i] = NULL;
	return (res);
}
/*
int main(void) {
    char **result;
    char *str = "Hello world fatima";
    char delimiter = ' ';
    int i;

    // Split the string
    result = ft_split(str, delimiter);

    // Check if result is not NULL
    if (result) {
        i = 0;
        while (result[i]) {
            printf("\"%s\"\n", result[i]);
            free(result[i]);  // Free each allocated word
            i++;
        }
        free(result);  // Free the array of pointers
    } else {
        printf("Error: Memory allocation failed\n");
    }

    return 0;
}*/
