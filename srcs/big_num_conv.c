/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_num_conv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecerri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 16:16:09 by fbecerri          #+#    #+#             */
/*   Updated: 2019/05/22 16:20:42 by fbecerri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "num.h"

ssize_t	conv_in_int(t_num *op)
{
	ssize_t		i;
	ssize_t		num;

	num = 0;
	i = op->len - 1;
	while (i >= 0)
	{
		num = num * 10 + op->num[i];
		i--;
		if (num < 0)
			return (-1);
	}
	return (num);
}
