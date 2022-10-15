/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syildiri <syildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 21:21:55 by syildiri          #+#    #+#             */
/*   Updated: 2022/09/08 21:21:57 by syildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	len;
	int	flag;
	int	location;

	i = 0;
	flag = 0;
	location = 0;
	len = ft_strlen(s);
	while (i <= len)
	{
		if (s[i] == (unsigned char)c)
		{
			flag = 1;
			location = i;
		}
		i++;
	}
	if (flag)
		return ((char *)s + location);
	return (NULL);
}
