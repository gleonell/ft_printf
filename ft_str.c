/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 09:25:51 by gleonell          #+#    #+#             */
/*   Updated: 2020/09/15 08:00:01 by gleonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_str(t_flags flag, t_parameters *parms)
{
	char	*ptr;

	if (!(ptr = va_arg(parms->ap, char *)))
	{
		if (!(ptr = ft_strdup("(null)")))
			return (NULL);
	}
	else
	{
		if (!(ptr = ft_strdup(ptr)))
			return (NULL);
	}
	if (flag.dot)
		if (!(ptr = ft_get_precision(flag.precision, ptr)))
			return (NULL);
	if (flag.width)
		if (!(ptr = ft_apply_width(flag.width, ptr, ' ')))
			return (NULL);
	if (flag.negative)
		ptr = ft_l_align(ptr);
	return (ptr);
}
