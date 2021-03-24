/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 09:23:23 by gleonell          #+#    #+#             */
/*   Updated: 2020/09/15 18:06:18 by gleonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_sign(int sign, char *string)
{
	char *str;

	if (sign == -1)
	{
		if (!(str = ft_strjoin("-", string)))
			return (NULL);
		free(string);
		return (str);
	}
	return (string);
}

char		*ft_get_precision(int counter, char *string)
{
	char *str;

	if (!(str = malloc((counter + 1) * sizeof(char))))
		return (NULL);
	ft_strlcpy(str, string, counter + 1);
	free(string);
	return (str);
}

char		*ft_precision_integer(int sign, t_flags flag, char *ptr)
{
	if (flag.precision == 0 && ptr[0] == '0')
		ptr[0] = '\0';
	else
	{
		if (!(ptr = ft_apply_width(flag.precision, ptr, '0')))
			return (NULL);
	}
	if (!(ptr = ft_sign(sign, ptr)))
		return (NULL);
	if (flag.width)
		if (!(ptr = ft_apply_width(flag.width, ptr, ' ')))
			return (NULL);
	if (flag.negative)
		if (!(ptr = ft_l_align(ptr)))
			return (NULL);
	if (flag.space)
		if (!(ptr = ft_strjoin(" ", ptr)))
			return (NULL);
	return (ptr);
}

char		*ft_without_precision(int sign, t_flags flag, char *ptr)
{
	char	ch;
	int		i;

	i = 0;
	if (flag.negative)
	{
		if (!(ptr = ft_sign(sign, ptr)))
			return (NULL);
		return (ft_apply_rightwidth(flag.width, ptr, ' '));
	}
	ch = (flag.flag_zero) ? '0' : ' ';
	if (!(ptr = ft_sign(sign, ptr)))
		return (NULL);
	if (!(ptr = ft_apply_width(flag.width, ptr, ch)))
		return (NULL);
	while (ptr[i] != '\0' && ptr[i] != '-' && ptr[i] != '+')
		i++;
	if (i && ptr[0] == '0' && ptr[i] != '\0')
	{
		ptr[0] = ptr[i];
		ptr[i] = '0';
	}
	return (ptr);
}
