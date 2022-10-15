/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syildiri <syildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 21:18:25 by syildiri          #+#    #+#             */
/*   Updated: 2022/09/08 21:18:28 by syildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	get_size(int n)
{
	int	cnt;

	cnt = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		cnt++;
	while (n)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

char	*ft_itoa(int n)
{
	int		size;
	char	*ret;

	size = get_size(n);
	ret = (char *)malloc(size + 1);
	if (!ret)
		return (NULL);
	ret[size] = '\0';
	if (n == 0)
	{
		ret[0] = '0';
		return (ret);
	}
	if (n < 0)
		ret[0] = '-';
	while (size-- && n)
	{
		if (n > 0)
			ret[size] = '0' + n % 10;
		else
			ret[size] = '0' - n % 10;
		n /= 10;
	}
	return (ret);
}
