#include <stdio.h>
#include <malloc.h>
#include <assert.h>

struct node {
    int dat;
    struct node *next;
};


struct node* new(int dat)
{
    struct node *t;
    t = malloc(sizeof(struct node));
    t->dat = dat;
    return t;
}

struct node *append(struct node *h, struct node *n)
{
	struct node *t;
	if(h == 0) return n;
	t=h;
	while(t->next != 0)
		t=t->next;
	t->next = n;
	return h;
}

struct node* find(struct node *h, int n)
{
	for(; h != 0; h = h->next)
		if(h->dat == n)
			return h;
	return 0;
}

void print(struct node *h)
{
    for(; h != 0; h = h->next)
        printf("%d\n", h->dat);
}

// create list of integers 0, 1, ... n-1
struct node* create_list(int n)
{
	struct node *h = 0;
	int i;

	for(i = 0; i < n; i++)
		h = append(h, new(i));
	return h;
}


int looping_list(struct node *h)
{
	int n = 0,i = 0;
	struct node *a[25];
	struct node *temp;
	
	while(h!=0){
		i = 0;
		temp = h;
		while(i < n){
			if(a[i] == temp)
				return 1; 
			i++;
		}
		a[n++] = h;
		h = h->next;
	}
	return 0;
}

main()
{
		int r;
		struct node *h = 0;
		struct node *a, *b;
	
		h = create_list(20);
		
		print(h);

		//now make a loop

		a = find(h, 6);
		b = find(h, 19);
		b->next = a;

		// return true if list has a loop

		r = looping_list(h);
		if(r == 1)
			printf("There is a loop\n");

		else
			printf("no loop\n");
		
}
