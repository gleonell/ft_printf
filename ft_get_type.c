/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 09:23:48 by gleonell          #+#    #+#             */
/*   Updated: 2020/09/18 18:35:34 by gleonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_type(t_flags flag, t_parameters *parms)
{
	char *ptr;

	parms->line = parms->format_copy[parms->count];
	if (parms->format_copy[parms->count] == '%')
		return (ft_percent(flag));
	if (parms->format_copy[parms->count] == 'c')
		return (ft_char(flag, parms));
	if (parms->format_copy[parms->count] == 's')
		return (ft_str(flag, parms));
	if (parms->format_copy[parms->count] == 'x')
		return (ft_dec_to_hex(flag, parms));
	if (parms->format_copy[parms->count] == 'X')
	{
		if (!(ptr = ft_dec_to_hex(flag, parms)))
			return (NULL);
		return (ft_hex_up(ptr));
	}
	if (parms->format_copy[parms->count] == 'd' ||
		parms->format_copy[parms->count] == 'i')
		return (ft_int_decimal(flag, parms));
	if (parms->format_copy[parms->count] == 'u')
		return (ft_unsigned(flag, parms));
	if (parms->format_copy[parms->count] == 'p')
		return (ft_pointer(flag, parms));
	return (NULL);
}
