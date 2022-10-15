/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syildiri <syildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 21:19:19 by syildiri          #+#    #+#             */
/*   Updated: 2022/09/08 21:19:20 by syildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_tmp;

	s_tmp = (unsigned char *)s;
	while (n--)
	{
		if (*s_tmp == (unsigned char)c)
			return (s_tmp);
		s_tmp++;
	}
	return (NULL);
}
