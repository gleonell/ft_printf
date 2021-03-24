/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_it_valid_string.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 09:22:52 by gleonell          #+#    #+#             */
/*   Updated: 2020/09/16 00:04:51 by gleonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_string(t_parameters parms)
{
	size_t	counter;

	counter = parms.count;
	while (parms.format_copy[++counter] != '\0'
	&& (!(ft_type(parms.format_copy[counter]))))
	{
		if (!(ft_flag_and_digit(parms.format_copy[counter])))
			return (1);
	}
	if (parms.format_copy[counter] == '\0')
		return (1);
	return (0);
}
