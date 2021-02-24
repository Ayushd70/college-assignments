
#include <stdio.h>
#include <stdlib.h>
#define max(a, b) ((a > b) ? a : b)
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

//-------------------------------------------------------------------
bTree *findTMax(bTree *rt)
{
    if (rt == NULL || rt->right == NULL)
        return rt;
    else
        return findTMax(rt->right);
}
bTree *findTMin(bTree *rt)
{
    if (rt == NULL || rt->left == NULL)
        return rt;
    else
        return findTMin(rt->left);
}
int count(bTree *rt)
{
    if (rt == NULL)
        return 0;
    else
        return count(rt->left) + count(rt->right) + 1;
}
int countEx(bTree *rt)
{
    if (rt == NULL)
        return 0;
    else if (rt->left == NULL && rt->right == NULL)
        return 1;
    else
        return countEx(rt->left) + countEx(rt->right);
}
int countIn(bTree *rt)
{
    if (rt == NULL)
        return 0;
    else if (rt->left != NULL || rt->right != NULL)
        return 1 + countIn(rt->left) + countIn(rt->right);
    else
        return 0;
}
int height(bTree *rt)
{
    if (rt == NULL)
        return 0;
    else
        return max(height(rt->left), height(rt->right)) + 1;
}
void delTree(bTree *rt)
{
    if (rt != NULL)
    {
        delTree(rt->left);
        delTree(rt->right);
        free(rt);
    }
}
void mirror(bTree *rt)
{
    bTree *tmp;
    if (rt != NULL)
    {
        mirror(rt->left);
        mirror(rt->right);
        tmp = rt->left;
        rt->left = rt->right;
        rt->right = tmp;
    }
}
//-------------------------------------------------------------------
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
void display(bTree *rt)
{
    printf("\nPreorder: ");
    printPreorder(rt);
    printf("\nInorder: ");
    printInorder(rt);
    printf("\nPostorder: ");
    printPostorder(rt);
}
void printMirror(bTree *rt)
{
    mirror(rt);
    display(rt);
    mirror(rt);
}
int main()
{
    bTree *root = NULL;
    int c = 0, data;
    do
    {
        printf("\n1. Insert\n2. Delete Tree\n3. Max Element\n4. Min Element\n5. Display Mirror\n6. Count Total Nodes\n7. Count External Nodes\
        \n8.Count External Nodes\n9. Height\n10. Display\n\n Enter: ");
        scanf("%d", &c);

        switch (c)
        {
        case 1:
            printf("Enter a no. ");
            scanf("%d", &data);
            insert(&root, data);
            break;
        case 2:
            delTree(root);
            root = NULL;
            break;
        case 3:
            printf("Max Element: %d", findTMax(root)->data);
            break;
        case 4:
            printf("Min Element: %d", findTMin(root)->data);
            break;
        case 5:
            printMirror(root);
            break;
        case 6:
            printf("Total no. of Element: %d", count(root));
            break;
        case 7:
            printf("Total no. of External Element: %d", countEx(root));
            break;
        case 8:
            printf("Total no. of Internal Element: %d", countIn(root));
            break;
        case 9:
            printf("Tree Height: %d", height(root));
            break;
        case 10:
            display(root);
            break;
        case 0:
            exit(0);
        default:
            printf("Wrong input ");
        }

    } while (1);
    return 0;
}