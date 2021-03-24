/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 09:26:23 by gleonell          #+#    #+#             */
/*   Updated: 2020/09/15 23:51:43 by gleonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type(int type)
{
	if ((type == 'c') || (type == 's') || (type == 'p') || (type == 'd') ||
	(type == 'i') || (type == 'u') || (type == 'x') || (type == 'X') ||
	(type == '%'))
		return (1);
	return (0);
}

int	ft_flag_and_digit(int c)
{
	if (c == '.' || c == '-' || c == '*' || c == ' ')
		return (1);
	else if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
