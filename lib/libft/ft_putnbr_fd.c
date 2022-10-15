/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syildiri <syildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 21:19:50 by syildiri          #+#    #+#             */
/*   Updated: 2022/09/08 21:19:52 by syildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char		zero;
	long long	nb;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -(long long)n;
	}
	else
		nb = (long long)n;
	zero = '0';
	if (nb < 10)
	{
		zero += nb;
		ft_putchar_fd(zero, fd);
	}
	else
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
}
