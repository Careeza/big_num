/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_num_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecerri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 11:51:01 by fbecerri          #+#    #+#             */
/*   Updated: 2019/05/22 13:54:20 by fbecerri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "num.h"

void	big_num_atoi(const char *str, t_num **num)
{
	ssize_t		i;
	ssize_t		j;
	const char	c = str[0];

	(*num)->len = 0;
	i = c == '-' || c == '+' ? 1 : 0;
	while (str[i] == '0')
		i++;
	j = i;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		i++;
	i--;
	while (i >= j && str[i] >= '0' && str[i] <= '9')
	{
		add_a_nbr(num, str[i] - '0');
		i--;
	}
	if ((*num)->len == 0)
	{
		(*num)->len = 1;
		(*num)->zero = true;
	}
	else
		(*num)->sign = c == '-' ? true : false;
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
