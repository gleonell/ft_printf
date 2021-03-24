/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_except_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 09:23:05 by gleonell          #+#    #+#             */
/*   Updated: 2020/09/15 18:05:43 by gleonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_except_flags(t_flags *flag)
{
	if (flag->negative)
		flag->flag_zero = 0;
	if (flag->width < 0)
	{
		flag->negative = 1;
		flag->width *= -1;
	}
	if (flag->precision < 0)
		flag->dot = 0;
}
