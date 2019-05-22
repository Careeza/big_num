/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_num_mult.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecerri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 10:43:45 by fbecerri          #+#    #+#             */
/*   Updated: 2019/05/20 11:10:43 by fbecerri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "num.h"

bool	bin_mult(t_num *a, t_num *b, t_num *c, t_num **res)
{
	size_t		i;
	size_t		j;
	uint16_t	num;
	uint16_t	overflow;

	i = -1;
	if (a->zero || b->zero)
	{
		(*res)->len = 1;
		(*res)->zero = true;
		return (true);
	}
	while (++i < a->len)
	{
		j = -1;
		overflow = 0;
		while (++j < b->len)
		{
			num = a->num[i] * b->num[j] + overflow;
			if (!(add_a_nbr(&c, num % 256)))
				return (false);
			overflow = num / 256;
		}
		if (overflow != 0)
			if (!(add_a_nbr(&c, overflow)))
				return (false);
		if (!(bin_add(*res, c, res, c->len)))
			return (false);
		c->len = i + 1;
	}
	return (true);
}

bool	gest_mult(t_num *a, t_num *b, t_num **res)
{
	t_num		*c;
	bool		sucess;

	if (!(c = create_num(LEN_NBR)))
		return (false);
	(*res)->sign = a->sign ^ b->sign;
	(*res)->len = 0;
	a->sign = false;
	b->sign = false;
	if (a->len > b->len)
		sucess = bin_mult(b, a, c, res);
	else
		sucess = bin_mult(a, b, c, res);
	free(c);
	return (sucess);
}

bool	big_num_mult(t_num *op1, t_num *op2, t_num **res)
{
	t_num	*a;
	t_num	*b;
	bool	sucess;

	if (!(a = copy_num(op1)))
		return (false);
	if (!(b = copy_num(op2)))
	{
		free(a);
		return (false);
	}
	sucess = gest_mult(a, b, res);
	free(a);
	free(b);
	return (sucess);
}
