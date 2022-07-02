/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyseo <jiyseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 20:22:36 by jiyseo            #+#    #+#             */
/*   Updated: 2022/05/19 17:11:50 by jiyseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	put_char(t_info *inf, char c)
{
	inf->count++;
	return (write(1, &c, 1));
}

void	fill_char(t_info *inf, char ch, int count)
{
	while (count > 0)
	{
		put_char(inf, ch);
		count--;
	}
}

void	fill_left(t_info *inf)
{
	char	ch;

	if (inf->flag & FLAG_MINUS)
		return ;
	if (inf->flag & FLAG_ZERO)
		ch = '0';
	else
		ch = ' ';
	while (inf->width > 0)
	{
		put_char(inf, ch);
		inf->width--;
	}
}

void	fill_right(t_info *inf)
{
	while (inf->width > 0)
	{
		put_char(inf, ' ');
		inf->width--;
	}
}
