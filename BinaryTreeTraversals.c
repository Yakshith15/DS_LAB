#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* left;
	struct node* right;
};

struct node* newNode(int data)
{
	struct node* node= (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

void Inorder(struct node* node)
{
	if (node == NULL)
		return;
	Inorder(node->left);
	printf("%d ", node->data);
	Inorder(node->right);
}

void Preorder(struct node* node)
{
	if (node == NULL)
		return;
	printf("%d ", node->data);
    Preorder(node->left);
	Preorder(node->right);
}

void Postorder(struct node* node)
{
	if (node == NULL)
		return;
	Postorder(node->left);
	Postorder(node->right);
    printf("%d ", node->data);
}

int main()
{
	struct node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

    printf("\nPreorder traversal of binary tree is \n");
	Preorder(root);

	printf("\nInorder traversal of binary tree is \n");
	Inorder(root);
    
    printf("\nPostorder traversal of binary tree is \n");
	Postorder(root);

	return 0;
}
