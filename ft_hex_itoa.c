/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_itoa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 09:24:16 by gleonell          #+#    #+#             */
/*   Updated: 2020/09/15 23:35:40 by gleonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_hex_itoa(unsigned long long number)
{
	char	str[15];
	size_t	i;
	char	*x;
	size_t	j;
	char	*string;

	i = 0;
	j = -1;
	x = "0123456789abcdef";
	if (number == 0)
		return (ft_strdup("0"));
	while (number != 0)
	{
		str[i++] = x[number % 16];
		number = number / 16;
	}
	str[i] = '\0';
	if (!(string = (char *)malloc((ft_strlen(str) + 1) * sizeof(char))))
		return (NULL);
	while (++j < ft_strlen(str))
		string[j] = str[ft_strlen(str) - j - 1];
	string[j] = '\0';
	return (string);
}
