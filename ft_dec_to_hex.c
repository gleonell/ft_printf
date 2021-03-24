/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_to_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 09:24:24 by gleonell          #+#    #+#             */
/*   Updated: 2020/09/15 07:58:59 by gleonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_hex_precision(t_flags flag, char *ptr)
{
	if (flag.precision == 0 && ptr[0] == '0')
		ptr[0] = '\0';
	else
	{
		if (!(ptr = ft_apply_width(flag.precision, ptr, '0')))
			return (NULL);
	}
	if (flag.width)
		if (!(ptr = ft_apply_width(flag.width, ptr, ' ')))
			return (NULL);
	if (flag.negative)
		if (!(ptr = ft_l_align(ptr)))
			return (NULL);
	return (ptr);
}

static char		*ft_hex_without_precision(t_flags flag, char *ptr)
{
	if (flag.negative)
		return (ft_apply_rightwidth(flag.width, ptr, ' '));
	if (!flag.flag_zero)
		if (!(ptr = ft_apply_width(flag.width, ptr, ' ')))
			return (NULL);
	if (flag.flag_zero)
		if (!(ptr = ft_apply_width(flag.width, ptr, '0')))
			return (NULL);
	return (ptr);
}

char			*ft_dec_to_hex(t_flags flag, t_parameters *parms)
{
	char			*ptr;
	unsigned int	unsigned_value;

	unsigned_value = va_arg(parms->ap, unsigned int);
	if (!(ptr = ft_hex_itoa(unsigned_value)))
		return (NULL);
	if (flag.dot)
		if (!(ptr = ft_hex_precision(flag, ptr)))
			return (NULL);
	if (!flag.dot)
		if (!(ptr = ft_hex_without_precision(flag, ptr)))
			return (NULL);
	return (ptr);
}
