/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safety_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samet <samet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 19:24:26 by samet             #+#    #+#             */
/*   Updated: 2022/09/07 19:24:28 by samet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	safety_free(void **data)
{
	if (data && *data)
	{
		free(*data);
		*data = NULL;
	}
}

void	safety_free_doublearray(void ***data)
{
	int	i;

	i = 0;
	if (data)
	{
		while (*data && (*data)[i])
		{
			safety_free((void **)&(*data)[i]);
			i++;
		}
		if (*data)
		{
			free(*data);
			data = NULL;
		}
	}
}
