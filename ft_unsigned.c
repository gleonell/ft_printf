/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 09:26:34 by gleonell          #+#    #+#             */
/*   Updated: 2020/09/15 23:32:29 by gleonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_itoa_for_unsigned(unsigned int number)
{
	int		length;
	char	str[11];
	int		i;
	int		j;
	char	*string;

	i = 0;
	j = -1;
	if (number == 0)
		return (ft_strdup("0"));
	while (number != 0)
	{
		str[i++] = (char)(number % 10 + 48);
		number /= 10;
	}
	str[i] = '\0';
	length = ft_strlen(str);
	if (!(string = (char *)malloc((length + 1) * sizeof(char))))
		return (NULL);
	while (++j < length)
		string[j] = str[length - j - 1];
	string[j] = '\0';
	return (string);
}

static char		*ft_precision_unsigned(t_flags flag, char *ptr)
{
	if (flag.precision == 0 && ptr[0] == '0')
		ptr[0] = '\0';
	else
	{
		if (!(ptr = ft_apply_width(flag.precision, ptr, '0')))
			return (NULL);
	}
	if (!(ptr = ft_apply_width(flag.precision, ptr, '0')))
		return (NULL);
	if (flag.width)
		if (!(ptr = ft_apply_width(flag.width, ptr, ' ')))
			return (NULL);
	if (flag.negative)
		if (!(ptr = ft_l_align(ptr)))
			return (NULL);
	return (ptr);
}

char			*ft_unsigned(t_flags flag, t_parameters *parms)
{
	char			*ptr;
	unsigned int	p;

	p = va_arg(parms->ap, unsigned int);
	ptr = ft_itoa_for_unsigned(p);
	if (flag.dot)
	{
		if (!(ptr = ft_precision_unsigned(flag, ptr)))
			return (NULL);
		if (flag.negative)
			return (ft_apply_rightwidth(flag.width, ptr, ' '));
	}
	else
	{
		if (flag.flag_zero)
			if (!(ptr = ft_apply_width(flag.width, ptr, '0')))
				return (NULL);
		if (flag.negative)
			return (ft_apply_rightwidth(flag.width, ptr, ' '));
		if (flag.width)
			if (!(ptr = ft_apply_width(flag.width, ptr, ' ')))
				return (NULL);
	}
	return (ptr);
}
