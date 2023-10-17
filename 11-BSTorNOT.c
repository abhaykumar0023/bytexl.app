#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

static struct node *prev = NULL;

int is_bst(struct node* root) {
    if (root) {
        if (!is_bst(root->left))
            return 0;
        if (prev != NULL && root->data <= prev->data)
            return 0;
        prev = root;
        return is_bst(root->right);
    }
    return 1;
}

struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

int main() {
    struct node *root = newNode(40);
    root->left = newNode(20);
    root->right = newNode(60);
    root->left->left = newNode(10);
    root->left->right = newNode(30);
    root->right->right = newNode(80);
    root->right->right->right = newNode(90);

    if (is_bst(root))
        printf("TREE 1 Is BST\n");
    else
        printf("TREE 1 Not a BST\n");

    prev = NULL;
    struct node *root1 = newNode(50);
    root1->left = newNode(20);
    root1->right = newNode(30);
    root1->left->left = newNode(70);
    root1->left->right = newNode(80);
    root1->left->left->right = newNode(40);
    root1->left->left->left = newNode(90);

    if (is_bst(root1))
        printf("TREE 2 Is BST\n");
    else
        printf("TREE 2 Not a BST\n");

    return 0;
}
