/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_parameters.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 09:22:42 by gleonell          #+#    #+#             */
/*   Updated: 2020/09/16 00:00:39 by gleonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_parameters(t_parameters *parms)
{
	t_flags	flag;
	char	*string;

	ft_start(&flag, parms);
	if (ft_check_string(*parms))
		return (1);
	while (parms->format_copy[++(parms->count)] != '\0' &&
		ft_flag_and_digit(parms->format_copy[parms->count]))
		ft_set_flag(&flag, parms->format_copy[parms->count], parms);
	ft_except_flags(&flag);
	if (!(string = ft_get_type(flag, parms)))
		return (1);
	else
	{
		ft_str_out(string, parms);
		parms->length += ft_strlen(string);
		free(string);
	}
	return (0);
}
