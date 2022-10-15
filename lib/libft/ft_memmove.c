/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syildiri <syildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 21:19:32 by syildiri          #+#    #+#             */
/*   Updated: 2022/09/08 21:19:34 by syildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_tmp;
	unsigned char	*src_tmp;

	if (dst == 0 && src == 0)
		return (NULL);
	dst_tmp = (unsigned char *)dst;
	src_tmp = (unsigned char *)src;
	if (dst < src)
	{
		while (len--)
			*dst_tmp++ = *src_tmp++;
	}
	else
	{
		while (len--)
			*(dst_tmp + len) = *(src_tmp + len);
	}
	return (dst);
}
