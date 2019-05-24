#include "num.h"

void	aff_param(t_num *op, char *name)
{
	printf("---------HERE---------\n");
	printf("name = %s\n", name);
	printf("capacity = %ld\n", op->capacity);
	printf("len = %ld\n", op->len);
	printf("sign = %s\n", !op->sign ? "positif" : "negatif");
	printf("num = ");
	aff_big_num(op, "\n");
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
