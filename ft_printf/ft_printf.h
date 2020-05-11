/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaudry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 09:59:48 by bbaudry           #+#    #+#             */
/*   Updated: 2020/05/11 10:29:58 by bbaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include "libft/libft.h"

typedef	struct	s_struct
{
	int	precision;
	int	width;
	int	neg;
	int	zero;
	int	cutter;
	int	decalage;
	int	printed;
	int	constantep;
	int	constantew;
	int	suivi;
	int	opt;
}				t_flags;

int				ft_printf(const char *line, ...);
int				ft_nblenx(unsigned int nb, int opt);
int				ft_nblend(int nb);
int				ft_nbzero(t_flags *flags);
int				ft_flagsaffin(t_flags *flags, int rest, int len, int nb);
void			ft_s(va_list *list_args, t_flags *flags);
void			ft_c(va_list *list_args, t_flags *flags);
void			ft_di(va_list *list_args, t_flags *flags);
void			ft_u(va_list *list_args, t_flags *flags);
void			ft_x(va_list *list_args, t_flags *flags);
void			ft_xg(va_list *list_args, t_flags *flags);
void			ft_p(va_list *list_args, t_flags *flags);
void			ft_flags(va_list *list_args, t_flags *flags);
void			ft_putunbr_fd(long int n, int fd);
void			ft_diputnbr(t_flags *flags, int nb, int len, int rest);
void			ft_width(t_flags *flags, int rest);
void			ft_ugestion(t_flags *flags, int rest, int len,
		unsigned long int nb);
void			ft_candwrite(t_flags *flags, unsigned long int nb, int opt);
void			ft_write(char c, t_flags *flags);

#endif
