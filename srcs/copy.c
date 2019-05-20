/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecerri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 14:54:41 by fbecerri          #+#    #+#             */
/*   Updated: 2019/05/20 14:56:38 by fbecerri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "num.h"

t_num	*copy_num(t_num *num)
{
	t_num	*copy;
	size_t	i;

	if (!(copy = create_num(num->capacity)))
		return (NULL);
	i = 0;
	while (i < num->len)
	{
		copy->num[i] = num->num[i];
		i++;
	}
	copy->len = num->len;
	copy->sign = num->sign;
	return (copy);
}

t_num	*copy_reverse_num(t_num *num)
{
	t_num	*copy;
	size_t	i;

	if (!(copy = create_num(num->capacity)))
		return (NULL);
	i = 0;
	while (i < num->len)
	{
		copy->num[i] = num->num[num->len - i - 1];
		i++;
	}
	copy->len = num->len;
	copy->sign = num->sign;
	return (copy);
}