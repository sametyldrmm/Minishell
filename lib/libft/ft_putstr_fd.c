/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syildiri <syildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 21:19:54 by syildiri          #+#    #+#             */
/*   Updated: 2022/09/08 21:19:56 by syildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
	unsigned char	c;
	size_t			i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		c = (unsigned char)s[i];
		write(fd, &c, 1);
		i++;
	}
}
