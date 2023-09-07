/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantos2 <fsantos2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:24:03 by fsantos2          #+#    #+#             */
/*   Updated: 2023/04/18 17:02:45 by fsantos2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	word_counter(char const *s, char c)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			i++;
			continue ;
		}
		count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

void	strings(char **split, char *s, char c)
{
	size_t	i;
	size_t	beginning;
	size_t	index;

	i = 0;
	index = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			i++;
			continue ;
		}
		beginning = i;
		while (s[i] != c && s[i])
			i++;
		split[index] = malloc(i - beginning + 1);
		ft_strlcpy(split[index], s + beginning, i - beginning + 1);
		index++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	char	*str;
	size_t	count;

	str = (char *)s;
	count = word_counter(str, c);
	split = malloc((count + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	split[count] = 0;
	strings(split, str, c);
	return (split);
}

/* int main()
{
    char str[] = "Hello,   how    are  you  ?";
    char **temp;

    temp = ft_split(str, ' ');
    printf("%s", temp[1]);
} */