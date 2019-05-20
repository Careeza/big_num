/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_num_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecerri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 11:51:01 by fbecerri          #+#    #+#             */
/*   Updated: 2019/05/20 14:06:18 by fbecerri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "num.h"

void	big_num_atoi(const char *str, t_num **num)
{
	size_t		i;
	const char	c = str[0];
	t_num		*op;

	op = create_num(LEN_NBR);
	(*num)->len = 0;
	i = c == '-' || c == '+' ? 1 : 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		add_a_nbr(&op, 10);
		big_num_mult(*num, op, num);
		op->len = 0;
		add_a_nbr(&op, str[i] - '0');
		big_num_add(*num, op, num);
		op->len = 0;
		i++;
	}
	(*num)->sign = c == '-' ? true : false;
	free(op);
}

t_num	*create_num_with_1_at_end(size_t len)
{
	t_num *num;

	if (!(num = create_num(len + 1)))
		return (NULL);
	num->num[len] = 1;
	num->len = len + 1;
	return (num);
}
