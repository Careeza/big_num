#include "num.h"

void	aff_param(t_num *op, char *name)
{
	printf("---------HERE---------\n");
	printf("name = %s\n", name);
	printf("capacity = %ld\n", op->capacity);
	printf("len = %ld\n", op->len);
	printf("sign = %s\n", !op->sign ? "positif" : "negatif");
	printf("num = ");
	conv_in_int(op);
	printf("---------END----------\n");
}

void	aff_big_num(t_num *res, const char *str)
{
	ssize_t	i;

	i = res->len;
	i--;
	if (res->sign)
		printf("-");
	while (i >= 0)
	{
		printf("%d", res->num[i]);
		i--;
	}
	printf("%s", str);
}


void	conv_in_int(t_num *op)
{
	ssize_t		i;
	size_t		num;

	if (op->zero)
		printf("zero\n");
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

