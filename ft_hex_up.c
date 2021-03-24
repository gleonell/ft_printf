/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_up.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 09:24:06 by gleonell          #+#    #+#             */
/*   Updated: 2020/09/10 09:24:09 by gleonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c + 65 - 97);
	return (c);
}

char		*ft_hex_up(char *string)
{
	int i;

	i = -1;
	while (string[++i] != '\0')
		string[i] = (char)ft_toupper(string[i]);
	return (string);
}
