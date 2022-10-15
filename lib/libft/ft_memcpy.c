/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syildiri <syildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 21:19:28 by syildiri          #+#    #+#             */
/*   Updated: 2022/09/08 21:19:30 by syildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dst_tmp;
	unsigned char	*src_tmp;
	size_t			i;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = -1;
	dst_tmp = (unsigned char *)dst;
	src_tmp = (unsigned char *)src;
	while (++i < n)
		*(dst_tmp + i) = *(src_tmp + i);
	return (dst);
}
