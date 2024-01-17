/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:24:13 by rpepi             #+#    #+#             */
/*   Updated: 2023/11/20 13:37:30 by rpepi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int		ft_printchar(int c);
int		ft_printf(const char *format, ...);
int		ft_after_percent(const char format, va_list args);
int		ft_print_hexa(unsigned int num, const char format);
void	ft_put_hexa(unsigned int num, const char format);
int		ft_lenght_hexa(unsigned int num);
int		ft_found_length(unsigned int num);
char	*ft_convert(unsigned int n);
int		ft_print_unsigned(unsigned int n);
int		ft_printpercent(void);
int		ft_printnbr(int n);
int		ft_printstr(char *str);
void	ft_putstr(char *str);
int		ft_print_ptr(unsigned long int ptr);
void	ft_put_ptr(unsigned long int num);
int		ft_lenght_ptr(unsigned long int num);
void	ft_putchar_fd(char c, int fd);
char	*ft_itoa(int n);

#endif