#include <stdio.h>
#define offset &((&(struct foo))0->t)
struct foo {
	int m, k;
	int t;
	int x, y;
};
main()
{
	printf("%d",offset);
}

