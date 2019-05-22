/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecerri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 10:00:36 by fbecerri          #+#    #+#             */
/*   Updated: 2019/05/20 15:24:14 by fbecerri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "num.h"

bool		bin_add(t_num *a, t_num *b, t_num **res, size_t len)
{
	size_t		i;
	uint16_t	num;
	bool		overflow;

	i = 0;
	overflow = false;
	if (a->zero && b->zero)
	{
		(*res)->zero = true;
		(*res)->len = 1;
		return (true);
	}
	while (i < len)
	{
		num = ((a->len > i ? a->num[i] : 0) + (b->len > i ? b->num[i] : 0)
				+ overflow);
		if (!(add_a_nbr(res, num % 256)))
			return (false);
		overflow = num >= 256;
		i++;
	}
	overflow ? add_a_nbr(res, 1) : 0;
	return (true);
}

static bool	gest_sign_add(t_num *a, t_num *b, t_num **res)
{
	size_t len;

	len = a->len > b->len ? a->len : b->len;
	if (a->sign || b->sign)
	{
		if (a->sign && b->sign)
		{
			(*res)->sign = true;
			return (bin_add(a, b, res, len));
		}
		else if (a->sign)
			return (bin_sub(b, a, res, len));
		else
			return (bin_sub(b, a, res, len));
	}
	else
		return (bin_add(a, b, res, len));
}

bool		big_num_add(t_num *op1, t_num *op2, t_num **res)
{
	t_num		*a;
	t_num		*b;
	bool		sucess;

	if (!(a = copy_num(op1)))
		return (false);
	if (!(b = copy_num(op2)))
	{
		free(a);
		return (false);
	}
	(*res)->len = 0;
	sucess = gest_sign_add(a, b, res);
	free(a);
	free(b);
	return (sucess);
}
