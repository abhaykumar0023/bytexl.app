#include <stdio.h>
#include <stdlib.h>
// Define the structure for a binary tree node
struct Node {
 int data;
 struct Node* left;
 struct Node* right;
};
// Function to create a new node
struct Node* createNode(int data) {
 struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
 newNode->data = data;
 newNode->left = NULL;
 newNode->right = NULL;
 return newNode;
}
// Function to check if two binary trees are mirrored
int areMirrored(struct Node* root1, struct Node* root2) {
 // Base cases
 if (root1 == NULL && root2 == NULL) {
 return 1; // Both trees are empty
 }
 if (root1 == NULL || root2 == NULL) {
 return 0; // One tree is empty while the other is not
 }
 
 // Compare values and check the mirrored structure
 return (root1->data == root2->data) &&
 areMirrored(root1->left, root2->right) &&
 areMirrored(root1->right, root2->left);
}
int main() {
 // Construct two binary trees
 struct Node* root1 = createNode(1);
 root1->left = createNode(2);
 root1->right = createNode(2);
 root1->left->left = createNode(3);
 root1->left->right = createNode(4);
 root1->right->left = createNode(4);
 root1->right->right = createNode(3);
 struct Node* root2 = createNode(1);
 root2->left = createNode(2);
 root2->right = createNode(2);
 root2->left->left = createNode(3);
 root2->left->right = createNode(4);
 root2->right->left = createNode(4);
 root2->right->right = createNode(3);
 if (areMirrored(root1, root2)) {
 printf("The two binary trees are mirrored.\n");
 } else {
 printf("The two binary trees are not mirrored.\n");
 }
 return 0;
}
