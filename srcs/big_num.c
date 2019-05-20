/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigNum.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecerri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 09:33:43 by fbecerri          #+#    #+#             */
/*   Updated: 2019/05/20 14:58:51 by fbecerri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "num.h"

t_num	*create_num(size_t capacity)
{
	t_num	*num;

	if (!(num = malloc(sizeof(t_num) + capacity * sizeof(uint8_t))))
		return (NULL);
	*num = (t_num){
		.capacity = capacity,
		.len = 0,
		.sign = false
	};
	ft_memset(num->num, 0, capacity * sizeof(uint8_t));
	return (num);
}

bool	add_a_nbr(t_num **num, uint8_t c)
{
	size_t	new_capacity;

	if ((*num)->len >= (*num)->capacity)
	{
		new_capacity = (*num)->capacity * 2;
		if (!(*num = realloc(*num, sizeof(t_num)
						+ new_capacity * sizeof(uint8_t))))
			return (false);
		ft_memset((*num)->num + (*num)->capacity, 0, (new_capacity / 2)
				* sizeof(uint8_t));
		(*num)->capacity = new_capacity;
	}
	(*num)->num[(*num)->len] = c;
	(*num)->len++;
	return (true);
}

void	conv_in_int(t_num *op)
{
	ssize_t		i;
	size_t		num;

	num = 0;
	i = op->len - 1;
	if (op->sign)
		printf("-");
	while (i >= 0)
	{
		num = num * 256 + op->num[i];
		i--;
	}
	printf("%ld\n", num);
}

int		main(int argc, const char *argv[])
{
	t_num *op1;
	t_num *op2;
	t_num *op3;

	op1 = create_num(LEN_NBR);
	op2 = create_num(LEN_NBR);
	op3 = create_num(LEN_NBR);
	if (argc == 4)
	{
		big_num_atoi(argv[1], &op1);
		big_num_atoi(argv[3], &op2);
		conv_in_int(op1);
		conv_in_int(op2);
		if (argv[2][0] == '-')
			big_num_sub(op1, op2, &op3);
		if (argv[2][0] == '+')
			big_num_add(op1, op2, &op3);
		if (argv[2][0] == '*')
			big_num_mult(op1, op2, &op3);
		if (argv[2][0] == '/')
			big_num_div(op1, op2, &op3);
		conv_in_int(op3);
	}
	else
	{
		big_num_atoi(argv[1], &op1);
		shift_to_left(&op1, 1);
		conv_in_int(op1);
	}
	return (0);
}
