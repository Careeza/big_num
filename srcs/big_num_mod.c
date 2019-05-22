/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_num_div.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecerri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 11:14:10 by fbecerri          #+#    #+#             */
/*   Updated: 2019/05/20 15:19:12 by fbecerri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "num.h"

bool	bin_mod(t_num *a, t_num *b, t_num **res, size_t save_len)
{
	ssize_t		q;

	while (b->len >= save_len)
	{
		q = 0;
		while (a->sign == false)
		{
			big_num_sub(a, b, &a);
			q++;
		}
		add_a_nbr(res, q - 1);
		big_num_add(a, b, &a);
		if (!(shift_to_left(&b, 1)))
			return (false);
	}
	*res = copy_num(a);
	return (true);
}

bool	gest_mod(t_num *a, t_num *b, t_num **res)
{
	ssize_t			shift;
	const size_t	save_len = b->len;

	(*res)->sign = a->sign ^ b->sign;
	(*res)->len = 0;
	a->sign = false;
	b->sign = false;
	shift = (a->len -  b->len);
	if (!shift_to_right(&b, shift))
		return (false);
	if (!(bin_mod(a, b, res, save_len)))
		return (false);
	return (true);
}

bool	big_num_mod(t_num *op1, t_num *op2, t_num **res)
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
	sucess = gest_mod(a, b, res);
	free(a);
	free(b);
	return (sucess);
}
