/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_out.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 09:24:46 by gleonell          #+#    #+#             */
/*   Updated: 2020/09/16 00:42:38 by gleonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_str_out(char *str, t_parameters *parms)
{
	char zero;

	zero = '\0';
	if (parms->head_zero)
	{
		write(1, &zero, 1);
		parms->length++;
	}
	if (str)
	{
		while (*str)
		{
			write(1, str, 1);
			str++;
		}
	}
	if (parms->back_zero)
	{
		write(1, &zero, 1);
		parms->length++;
	}
}
