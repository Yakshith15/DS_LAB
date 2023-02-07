#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *CreateNode(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}
int count = 0;
void Inorder(struct node *root)
{

    if (root == NULL && count == 0)
    {
        printf("tree is empty\n");
    }
    if (root != NULL)
    {
        count = 1;
        Inorder(root->left);
        printf("%d--", root->data);
        Inorder(root->right);
    }
   
}

struct node *Insert(struct node *root, int key)
{

    if (root == NULL)
        return CreateNode(key);
    if (key < root->data)
    {
        root->left = Insert(root->left, key);
    }
    else
    {
        root->right = Insert(root->right, key);
    }
    return root;
}

struct node *minValueNode(struct node *node)
{
    struct node *current = node;

    // Find the leftmost leaf
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

void *minnValueNode(struct node *node)
{
    struct node *current = node;
    if (node == NULL)
    {
        printf("tree is empty\n");
    }
    else
    {

        while (current && current->left != NULL)
            current = current->left;

        printf("min is %d\n", current->data);
    }
}

void *maxValueNode(struct node *node)
{
    struct node *current = node;
    if (node == NULL)
    {
        printf("tree is empty\n");
    }
    else
    {

        // Find the leftmost leaf
        while (current && current->right != NULL)
            current = current->right;

        printf("max is %d\n", current->data);
    }
}

struct node *Deletion(struct node *root, int key)
{
    if (root == NULL)
    {
        printf("element not found to be deleted \n");
        return root;
    }
    // printf("hero\n");
    if (key < root->data)
    {
        root->left = Deletion(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = Deletion(root->right, key);
    }
    else
    {
        if (root->left == NULL)
        {
            struct node *temp = (struct node *)malloc(sizeof(struct node));
            temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = (struct node *)malloc(sizeof(struct node));
            temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            struct node *temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = Deletion(root->right, temp->data);
        }
    }
    return root;
}

struct node *search(struct node *root, int key)
{
    if (root == NULL)
    {
        printf("The element is not found\n");
        return NULL;
    }
    if (root->data == key)
    {
        printf("The element is found\n");
        return root;
    }
    else if (key < root->data)
    {
        return search(root->left, key);
    }
    else
    {
        return search(root->right, key);
    }
}

int main()
{
    struct node *root = NULL;
    printf("MENU\n 1.Insert\n 2.Delete\n 3.MAximum\n 4.Minimum\n 5.Inorder Trversal\n 6.Search\n 7.Exit\n");
    while (1)
    {
        printf("Enter choice\n");
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {

        case 1:
            printf("Enter the data to be inserted\n");
            int key;
            scanf("%d", &key);
            root = Insert(root, key);
            break;

        case 2:
            printf("Enter data to be deleted\n");
            int keys;
            scanf("%d", &keys);
            //	Inorder(root);
            root = Deletion(root, keys);
            break;

        case 3:
            maxValueNode(root);
            break;

        case 4:
            minnValueNode(root);
            break;

        case 5:
            Inorder(root);
            printf("\n");
            break;

        case 6:
            printf("Enter element to be searched\n");
            int temp;
            scanf("%d", &temp);
            search(root, temp);
            break;

        case 7:
            exit(0);
        }
    }
}