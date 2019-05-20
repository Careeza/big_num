/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_num_sub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecerri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 13:57:10 by fbecerri          #+#    #+#             */
/*   Updated: 2019/05/20 16:47:43 by fbecerri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "num.h"

bool		trunc_zero_at_the_end(t_num **res)
{
	while (--(*res)->len > 0 && (*res)->num[(*res)->len] == 0)
		;
	(*res)->len++;
	return (true);
}

bool		bin_sub(t_num *a, t_num *b, t_num **res, size_t len)
{
	size_t		i;
	uint16_t	num;
	bool		overflow;
	t_num		*sign;

	i = 0;
	overflow = false;
	while (i < len)
	{
		num = ((a->len > i ? a->num[i] : 0) - (b->len > i ? b->num[i] : 0)
				- overflow);
		if (!(add_a_nbr(res, num % 256)))
			return (false);
		overflow = num >= 256;
		i++;
	}
	if (overflow)
	{
		if (!((sign = create_num_with_1_at_end((*res)->len))
						&& big_num_sub(sign, *res, res)))
			return (false);
		free(sign);
		(*res)->sign = true;
	}
	return (trunc_zero_at_the_end(res));
}

static bool	gest_sign_sub(t_num *a, t_num *b, t_num **res)
{
	size_t len;

	len = a->len > b->len ? a->len : b->len;
	if (a->sign || b->sign)
	{
		if (a->sign && b->sign)
			return (bin_sub(b, a, res, len));
		else if (a->sign)
		{
			(*res)->sign = true;
			return (bin_add(b, a, res, len));
		}
		else
			return (bin_add(b, a, res, len));
	}
	else
		return (bin_sub(a, b, res, len));
}

bool		big_num_sub(t_num *op1, t_num *op2, t_num **res)
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
	sucess = gest_sign_sub(a, b, res);
	free(a);
	free(b);
	return (sucess);
}
