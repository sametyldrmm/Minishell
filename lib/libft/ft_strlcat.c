/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syildiri <syildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 21:20:45 by syildiri          #+#    #+#             */
/*   Updated: 2022/09/08 21:20:46 by syildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	s_len;
	size_t	d_len;
	size_t	i;
	size_t	j;

	s_len = ft_strlen(src);
	d_len = ft_strlen(dst);
	i = 0;
	j = 0;
	if (dstsize < d_len)
		return (s_len + dstsize);
	else
	{
		while (dst[i])
			i++;
		while (src[j] && i + 1 < dstsize)
			dst[i++] = src[j++];
		dst[i] = '\0';
		return (s_len + d_len);
	}
}
