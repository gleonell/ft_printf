/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 09:25:18 by gleonell          #+#    #+#             */
/*   Updated: 2020/09/18 18:35:34 by gleonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_flags
{
	int			negative;
	int			flag_zero;
	int			width;
	int			dot;
	int			precision;
	int			star;
	int			space;
}				t_flags;

typedef struct	s_parameters
{
	va_list		ap;
	const char	*format_copy;
	size_t		count;
	size_t		length;
	char		line;
	int			head_zero;
	int			back_zero;
}				t_parameters;

int				ft_printf(const char *format, ...);
int				ft_check_parameters(t_parameters *parms);
int				ft_check_string(t_parameters parms);
int				ft_flag_and_digit(int c);
void			ft_start(t_flags *flag, t_parameters *parms);
int				ft_set_flag(t_flags *flag, char symbol, t_parameters *parms);
int				ft_atoi_length(int n);
int				ft_atoi(const char *str, t_parameters *param);
int				ft_type(int type);
void			ft_putchar(char c);
void			ft_str_out(char *str, t_parameters *parms);
void			ft_except_flags(t_flags *flag);
char			*ft_get_type(t_flags flag, t_parameters *parms);
char			*ft_char(t_flags flag, t_parameters *parms);
char			*ft_mem_char(int c);
char			*ft_apply_width(size_t counter, char *string, char ch);
char			*ft_l_align(char *ptr);
char			*ft_str(t_flags flag, t_parameters *parms);
char			*ft_get_precision(int counter, char *string);
char			*ft_strdup(const char *s1);
char			*ft_percent(t_flags flag);
char			*ft_apply_rightwidth(size_t counter, char *string, char ch);
char			*ft_int_decimal(t_flags flag, t_parameters *parms);
char			*ft_itoa(long n);
char			*ft_precision_integer(int znak, t_flags flag, char *ptr);
char			*ft_without_precision(int znak, t_flags flag, char *ptr);
char			*ft_pointer(t_flags flag, t_parameters *parms);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_dec_to_hex(t_flags flag, t_parameters *parms);
char			*ft_hex_itoa(unsigned long long number);
char			*ft_hex_up(char *string);
char			*ft_unsigned(t_flags flag, t_parameters *parms);
size_t			ft_strlen(const char *str);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
#endif
