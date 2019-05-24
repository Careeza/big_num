/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_num_mult.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecerri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 10:43:45 by fbecerri          #+#    #+#             */
/*   Updated: 2019/05/22 16:31:17 by fbecerri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "num.h"

bool	bin_pow(t_num *a, size_t num, t_num **res)
{
	size_t	i;

	i = 0;
	while (i < num)
	{
		big_num_mult(a, *res, res);
		i++;
	}
	return (true);
}

bool	gest_pow(t_num *a, t_num *b, t_num **res)
{
	bool		sucess;
	ssize_t		num;

	(*res)->len = 1;
	(*res)->num[0] = 1;
	if ((num = conv_in_int(b)) == -1)
	{
		printf("to big\n");
		return (false);
	}
	if (b->sign)
	{
		printf("no gest of neg\n");
		return (false);
	}
	(*res)->sign = a->sign * (num % 2);
	a->sign = false;
	b->sign = false;
	sucess = bin_pow(a, num, res);
	return (sucess);
}

bool	big_num_pow(t_num *op1, t_num *op2, t_num **res)
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
	sucess = gest_pow(a, b, res);
	free(a);
	free(b);
	return (sucess);
}
