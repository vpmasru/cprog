/*
 *
 * binary tree depth first traversal
 * Pre-order : Root, Left, Right
 * In-order  : Left, Root, Right
 * Post-order: Left, Right, Root
 */

#include <stdio.h>
#include <stdlib.h>
                /* 0  1  2  3  4  5  6  7   8   9   10 */
int node_arr [] = {2, 6, 7, 4, 5, 9, 8, 12, 16, 19, 21};

/*
              2
           /    \
          /      \
          6       7
        /   \    /  \
       4     5  9    8
      / \   / \
     12 16 19 21


     root  = 2*i
     left  = 2*i + 1
     right = 2*i + 2
 */

struct bt_node {
    int val;
    struct bt_node *left;
    struct bt_node *right;
};

struct bt_node *root = NULL;

static struct bt_node *
create_node(int val)
{
    struct bt_node *tmp = NULL;

    tmp = (struct bt_node *)calloc(sizeof(struct bt_node), 1);
    tmp->val = val;

    return tmp;
}

static struct bt_node *
create_tree(int *arr, int idx, size_t arr_sz)
{
    struct bt_node *root = NULL; 

    if (idx < arr_sz) {
        root = create_node(arr[idx]);

        root->left = create_tree(arr, 2*idx+1, arr_sz);

        root->right = create_tree(arr, 2*idx+2, arr_sz);
    }

    return root;
}

static void
traverse_preorder(struct bt_node *root)
{
    if (root != NULL) {
        printf("%d, ", root->val);
        traverse_preorder(root->left);
        traverse_preorder(root->right);
    }
}

static void
traverse_inorder(struct bt_node *root)
{
    if (root != NULL) {
        traverse_inorder(root->left);
        printf("%d, ", root->val);
        traverse_inorder(root->right);
    }
}

static void
traverse_postorder(struct bt_node *root)
{
    if (root != NULL) {
        traverse_postorder(root->left);
        traverse_postorder(root->right);
        printf("%d, ", root->val);
    }
}

int main(void)
{
    int i;
    size_t arr_sz = sizeof(node_arr)/sizeof(node_arr[0]);
    printf ("Array is: ");
    for (;i<arr_sz;i++) {
        printf("%d, ", node_arr[i]);
    }
    printf("\n");

    root = create_tree(node_arr, 0, arr_sz);

    printf ("Preorder: ");
    traverse_preorder(root);
    printf("\n");

    printf ("Inorder: ");
    traverse_inorder(root);
    printf("\n");

    printf ("Postorder: ");
    traverse_postorder(root);
    printf("\n");

    return 0;
}

