/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 09:22:11 by gleonell          #+#    #+#             */
/*   Updated: 2020/09/15 07:42:45 by gleonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_atoi_length(int n)
{
	size_t	i;

	if (n > 0)
		i = 0;
	else
		i = 1;
	while (1)
	{
		i++;
		n /= 10;
		if (!n)
			break ;
	}
	return (i);
}

int	ft_atoi(const char *str, t_parameters *param)
{
	int				i;
	int				negative;
	unsigned long	ret;

	i = 0;
	negative = 1;
	ret = 0;
	if (!str)
		return (0);
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negative = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		ret = ret * 10 + str[i++] - '0';
	param->count = param->count +
		ft_atoi_length((int)ret * negative) - 1;
	return ((int)ret * negative);
}
