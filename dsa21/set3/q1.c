#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int val;
  struct Node *left;
  struct Node *right;
} Node;

Node *createNode(int x) {
  Node *root = (Node *)malloc(sizeof(Node));
  root->val = x;
  root->left = NULL;
  root->right = NULL;
  return root;
}

Node *insertNode(Node *root, int choice, int x) {
  if (choice == 1) {
    root->left = createNode(x);
    return root->left;
  } else if (choice == 2) {
    root->right = createNode(x);
    return root->right;
  }
  printf("Invalid choice.\n");
  return NULL;
}

void preorder(Node *root) {
  if (root == NULL)
    return;
  printf("%d ", root->val);
  preorder(root->left);
  preorder(root->right);
}

void inorder(Node *root) {
  if (root == NULL)
    return;
  inorder(root->left);
  printf("%d ", root->val);
  inorder(root->right);
}

void postorder(Node *root) {
  if (root == NULL)
    return;
  postorder(root->left);
  postorder(root->right);
  printf("%d ", root->val);
}

int main() {
  int choice, y;
  Node *root = NULL;
  Node *current = NULL;
  while (1) {
    printf(
        "Enter 1 to insert node\n 2 to print preorder traversal\n 3 to print "
        "inorder traversal\n 4 to print postorder traversal\n 5 to move "
        "through tree\n 6 to exit.\n");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      if (root == NULL) {
        printf("Enter data for root node:\n");
        int x;
        scanf("%d", &x);
        root = createNode(x);
        current = root;
        break;
      }
      int dir;
      printf("Enter 1 to enter node to left\n 2 to enter node to right.\n");
      scanf("%d", &dir);
      printf("Enter data to be stored in new node:\n");
      int x;
      scanf("%d", &x);
      current = insertNode(current, dir, x);
      break;
    case 2:
      preorder(root);
      printf("\n");
      break;
    case 3:
      inorder(root);
      printf("\n");
      break;
    case 4:
      postorder(root);
      printf("\n");
      break;
    case 5:
      if (current == NULL) {
        printf("Invalid\n");
        break;
      }
      printf(
          "\nEnter 1 to move to left child\n 2 to move to right child\n 3 to "
          "go back to root");
      scanf("%d", &y);
      if (y == 1) {
        if (current->left == NULL)
          printf("Invalid\n");
        else
          current = current->left;
      } else if (y == 2) {
        if (current->right == NULL)
          printf("Invalid\n");
        else
          current = current->right;
      } else
        current = root;
      printf("Current value: %d\n", current->val);
      break;
    default:
      return 0;
    }
  }
  return 0;
}
