/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_set_flags.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 09:25:34 by gleonell          #+#    #+#             */
/*   Updated: 2020/09/15 17:25:00 by gleonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_set_flag(t_flags *flag, char symbol, t_parameters *parms)
{
	if (symbol == '0')
		flag->flag_zero = 1;
	if (symbol == '-')
		flag->negative = 1;
	if (symbol == '.')
		flag->dot = 1;
	if (symbol == '*')
	{
		if ((flag->dot) == 1)
			flag->precision = va_arg(parms->ap, int);
		else
			flag->width = va_arg(parms->ap, int);
	}
	if (symbol >= '1' && symbol <= '9')
	{
		if (flag->dot)
			flag->precision =
				ft_atoi(&(parms->format_copy[parms->count]), parms);
		else
			flag->width =
				ft_atoi(&(parms->format_copy[parms->count]), parms);
	}
	if (symbol == ' ')
		flag->space = 1;
	return (0);
}

void	ft_start(t_flags *flag, t_parameters *parms)
{
	parms->head_zero = 0;
	parms->back_zero = 0;
	flag->dot = 0;
	flag->negative = 0;
	flag->width = 0;
	flag->flag_zero = 0;
	flag->precision = 0;
	flag->space = 0;
}
