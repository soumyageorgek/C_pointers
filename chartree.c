#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <string.h>

struct node {
    char *str;
    struct node *left, *right;
};


struct node* new(char *s)
{
    struct node *t;
    t = malloc(sizeof(struct node));
    t->str = malloc(sizeof(strlen(s) + 1));
    strcpy(t->str,s);
    return t;
}

struct node *insert(struct node *h, struct node *n)
{
	if(h == 0) return n;
	
	if(strcmp(h->str, n->str) > 0)
		h->left = insert(h->left, n);
	else h->right = insert(h->right, n);

	return h;
}


void inorder(struct node *h)
{
	if(h == 0) return;

	inorder(h->left);
	printf("%s\t", h->str);
	inorder(h->right);
}

main()
{
	struct node *h = 0;
	char s[100];

	while(scanf("%s", s) != EOF)
		h = insert(h, new(s));
	inorder(h);
}

