/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 09:25:10 by gleonell          #+#    #+#             */
/*   Updated: 2020/09/15 23:34:57 by gleonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	t_parameters	parms;

	parms.length = 0;
	parms.count = 0;
	parms.format_copy = format;
	va_start(parms.ap, format);
	while (parms.format_copy[parms.count] != '\0')
	{
		if (parms.format_copy[parms.count] == '%')
		{
			if (ft_check_parameters(&parms))
			{
				ft_putchar(parms.format_copy[parms.count]);
				parms.length++;
			}
		}
		else
		{
			ft_putchar(parms.format_copy[parms.count]);
			parms.length++;
		}
		(parms.count)++;
	}
	va_end(parms.ap);
	return (parms.length);
}
