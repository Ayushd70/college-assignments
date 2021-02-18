#include <stdio.h>
#include <stdlib.h>
typedef struct bTree
{
    int data;
    struct bTree *left;
    struct bTree *right;
} bTree;
bTree *insert(bTree **rt, int data)
{
    if (*rt == NULL)
    {
        (*rt) = (bTree *)malloc(sizeof(bTree));
        (*rt)->data = data;
        (*rt)->left = NULL;
        (*rt)->right = NULL;
    }
    else if (data <= (*rt)->data)
    {
        insert(&(*rt)->left, data);
    }
    else
    {
        insert(&(*rt)->right, data);
    }
    return *rt;
}
bTree **getMax(bTree **rt)
{
    bTree *i = *rt;
    if (i->right == NULL)
        return rt;

    for (; i->right->right != NULL; i = i->right)
        ;

    return &(i->right);
}
void Tdelete(bTree **rt, int data)
{
    bTree *temp, **t2;
    if (*rt == NULL)
        printf("\n not found ");
    else if ((*rt)->data > data)
    {
        // printf("\n dr ",(*rt)->data);
        Tdelete(&(*rt)->left, data);
    }
    else if ((*rt)->data < data)
    {
        //printf("\n dl %d",(*rt)->data);

        Tdelete(&(*rt)->right, data);
    }
    else if ((*rt)->left && (*rt)->right) //delete it 2 child
    {
        //printf("\n lr %d",(*rt)->data);
        t2 = getMax(&(*rt)->left);

        (*rt)->data = (*t2)->data;

        Tdelete(t2, (*t2)->data);
    }
    else
    {

        //printf("\n del %d",(*rt)->data);
        temp = *rt;
        if ((*rt)->left != NULL)
            //printf("\n del l"),
            *rt = (bTree *)(temp->left);
        else if ((*rt)->right != NULL)
            //printf("\n del r"),
            *rt = (bTree *)(temp->right);
        else
            //printf("\n del me"),
            *rt = NULL;
        //free(temp);
    }
}
void printInorder(bTree *rt)
{
    if (rt == NULL)
        return;
    printInorder(rt->left);
    printf(" %d", rt->data);
    printInorder(rt->right);
}
void printPreorder(bTree *rt)
{
    if (rt == NULL)
        return;
    printf(" %d", rt->data);
    printPreorder(rt->left);
    printPreorder(rt->right);
}
void printPostorder(bTree *rt)
{
    if (rt == NULL)
        return;
    printPostorder(rt->left);
    printPostorder(rt->right);
    printf(" %d", rt->data);
}
int main()
{
    bTree *root = NULL;
    int c = 0, data;
    do
    {
        printf("\n1. Insert\n2. Delete\n3. Display(preorder)\n4. Display(inorder)\n5. Display(postorder)\n6. Exit\n\n Enter: ");
        scanf("%d", &c);

        switch (c)
        {
        case 1:
            printf("Enter a no. ");
            scanf("%d", &data);
            insert(&root, data);
            break;
        case 2:
            printf("Enter a no. ");
            scanf("%d", &data);
            Tdelete(&root, data);
            break;
        case 3:
            printf("Preorder: ");
            printPreorder(root);
            break;
        case 4:
            printf("Inorder: ");
            printInorder(root);
            break;
        case 5:
            printf("Postorder: ");
            printPostorder(root);
            break;
        case 6:
            exit(0);
        default:
            printf("Wrong input ");
            break;
        }

    } while (1);
    return 0;
}