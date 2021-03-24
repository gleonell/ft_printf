/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 09:24:54 by gleonell          #+#    #+#             */
/*   Updated: 2020/09/10 09:24:56 by gleonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_percent(t_flags flag)
{
	char	*ptr;

	if (!(ptr = ft_strdup("%")))
		return (NULL);
	if (flag.width && !flag.negative)
		if (!(ptr = ft_apply_width(flag.width, ptr, ' ')))
			return (NULL);
	if (flag.negative)
		if (!(ptr = ft_apply_rightwidth(flag.width, ptr, ' ')))
			return (NULL);
	return (ptr);
}
