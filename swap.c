void swap(int a, int b)
{
	int c[4];
	c[0]=1;
	c[12]=a;
	c[13]=b;
}

main()
{
        int a = 10, b = 20;

        swap(a, b);

        printf("%d %d\n", a, b);
}

