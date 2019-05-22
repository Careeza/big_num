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

void	aff_big_num(t_num *res)
{
	t_num *a;
	t_num *b;
	t_num *mod;

	a = create_num(LEN_NBR);
	mod = create_num(LEN_NBR);
	b = copy_num(res);
	a->len = 1;
	a->num[1] = 10;
	while (!b->zero)
	{
		big_num_mod(b, a, &mod);
		printf("%d-", mod->num[0]);
		big_num_div(b, a, &b);
	}
	printf("\n");
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

