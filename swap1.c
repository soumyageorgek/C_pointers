void swap(int *a1, int *b1)
{
	int *temp;

	*temp=*a1;
	*a1=*b1;
	*b1=*temp;
}

main()
{
        int a = 10, b = 20;

        swap(&a, &b);

        printf("%d %d\n", a, b);
}

