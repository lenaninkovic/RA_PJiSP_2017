#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *left;
    struct node *right;
    char value;
} node_t, *tree_t;

void preorder(tree_t tree)
{
    if (tree)
    {
        putchar(tree->value);
        preorder(tree->left);
        preorder(tree->right);
    }
}

void inorder(tree_t tree)
{
    if (tree)
    {
        inorder(tree->left);
        putchar(tree->value);
        inorder(tree->right);
    }
}

void reverse_order(tree_t tree)
{
    if (tree)
    {
        reverse_order(tree->right);
        putchar(tree->value);
        reverse_order(tree->left);
    }
}

void insert(tree_t *tree, char value)
{
    if (*tree == NULL)
    {
        *tree = malloc(sizeof(node_t));
        (*tree)->value = value;
        (*tree)->left = NULL;
        (*tree)->right = NULL;
    }
    else if (value < (*tree)->value)
    {
        insert(&(*tree)->left, value);
    }
    else
    {
        insert(&(*tree)->right, value);
    }
}

node_t *make(char value, node_t *left, node_t *right)
{
    node_t *new = malloc(sizeof(node_t));
    new->value = value;
    new->left = left;
    new->right = right;
}

void deltree(tree_t *tree)
{
    if (*tree != NULL)
    {
        deltree(&(*tree)->left);
        deltree(&(*tree)->right);
        free(*tree);
        *tree = NULL;
    }
}

int main()
{
    tree_t tree1 = make(
        'B',
        make('A', NULL, NULL),
        make('C', NULL, make('D', NULL, NULL))
    );

    tree_t tree2 = NULL;
    insert(&tree2, 'B');
    insert(&tree2, 'A');
    insert(&tree2, 'C');
    insert(&tree2, 'D');

    preorder(tree1);
    putchar('\n');

    inorder(tree1);
    putchar('\n');

    reverse_order(tree1);
    putchar('\n');

    deltree(&tree1);

    preorder(tree2);
    putchar('\n');

    inorder(tree2);
    putchar('\n');

    reverse_order(tree2);
    putchar('\n');

    deltree(&tree2);
    return 0;
}

