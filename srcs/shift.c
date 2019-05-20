/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecerri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 14:26:38 by fbecerri          #+#    #+#             */
/*   Updated: 2019/05/20 14:54:05 by fbecerri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "num.h"

bool	shift_to_right(t_num **num, ssize_t shift)
{
	t_num	*new;
	size_t	i;
	size_t	capacity;

	if (shift < 0)
		return (true);
	capacity = LEN_NBR;
	while (capacity < (*num)->len + shift)
		capacity *= 2;
	if (!(new = create_num(capacity)))
		return (false);
	new->len = shift;
	i = 0;
	while (i < (*num)->len)
	{
		if (!(add_a_nbr(&new, (*num)->num[i])))
			return (false);
		i++;
	}
	*num = copy_num(new);
	free(new);
	return (true);
}

bool	shift_to_left(t_num **num, ssize_t shift)
{
	t_num	*new;
	size_t	i;

	if (!(new = create_num(LEN_NBR)))
		return (false);
	i = shift;
	while (i < (*num)->len)
	{
		if (!(add_a_nbr(&new, (*num)->num[i])))
			return (false);
		i++;
	}
	*num = copy_num(new);
	free(new);
	return (true);
}
