/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 09:22:22 by gleonell          #+#    #+#             */
/*   Updated: 2020/09/15 07:57:08 by gleonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_char(t_flags flag, t_parameters *parms)
{
	int		symbol;
	char	*ptr;

	symbol = va_arg(parms->ap, int);
	if (!(ptr = ft_mem_char(symbol)))
		return (NULL);
	if (flag.width)
		if (!(ptr = ft_apply_width(flag.width - 1 + ft_strlen(ptr), ptr, ' ')))
			return (NULL);
	if (flag.negative)
		if (!(ptr = ft_l_align(ptr)))
			return (NULL);
	if (symbol == 0)
	{
		if (flag.negative)
			parms->head_zero = 1;
		else
			parms->back_zero = 1;
	}
	return (ptr);
}

char	*ft_mem_char(int symbol)
{
	char	*s;

	s = (char *)malloc(sizeof(char) * 2);
	if (!s)
		return (NULL);
	s[0] = (char)symbol;
	s[1] = '\0';
	return (s);
}
