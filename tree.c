#include <stdio.h>
#include <malloc.h>
#include <assert.h>

struct node {
    int dat;
    struct node *left, *right;
};


struct node* new(int dat)
{
    struct node *t;
    t = malloc(sizeof(struct node));
    t->dat = dat;
    return t;
}

struct node *insert(struct node *h, struct node *n)
{
	if(h == 0) return n;
	
	if(n->dat < h->dat)
		h->left = insert(h->left, n);
	else h->right = insert(h->right, n);

	return h;
}


void inorder(struct node *h)
{
	if(h == 0) return;

	inorder(h->left);
	printf("%d\n", h->dat);
	inorder(h->right);
}

main()
{
		struct node *h = 0;
		h = insert(h, new(10));
		h = insert(h, new(20));
		h = insert(h, new(5));
		inorder(h);
}
