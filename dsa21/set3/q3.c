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

void insertNode(Node *root, int x) {
  if (root->val > x) {
    if (root->left == NULL) {
      root->left = createNode(x);
      return;
    } else
      insertNode(root->left, x);
  } else {
    if (root->right == NULL) {
      root->right = createNode(x);
      return;
    } else
      insertNode(root->right, x);
  }
}

Node *searchNode(Node *root, int key) {
  if (root == NULL)
    return NULL;
  if (root->val > key) {
    return searchNode(root->left, key);
  } else if (root->val < key) {
    return searchNode(root->right, key);
  }
  return root;
}

Node *inorderSuccessor(Node *root, int key) {
  Node *succ;
  Node *temp = root;
  while (temp != NULL) {
    if (temp->val > key) {
      succ = temp;
      temp = temp->left;
    } else
      temp = temp->right;
  }
  return succ;
}

Node *inorderPredecessor(Node *root, int key) {
  Node *pred;
  Node *temp = root;
  while (temp != NULL) {
    if (temp->val < key) {
      pred = temp;
      temp = temp->right;
    } else
      temp = temp->left;
  }
  return pred;
}

Node *minValueNode(Node *temp) {
  while (temp != NULL && temp->left != NULL)
    temp = temp->left;
  return temp;
}

Node *deleteNode(Node *root, int val) {
  if (root == NULL)
    return root;

  if (val < root->val)
    root->left = deleteNode(root->left, val);
  else if (val > root->val)
    root->right = deleteNode(root->right, val);
  else {
    if (root->left == NULL) {
      Node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      Node *temp = root->left;
      free(root);
      return temp;
    }
    Node *temp = minValueNode(root->right);
    root->val = temp->val;
    root->right = deleteNode(root->right, temp->val);
  }
  return root;
}

void inorder(Node *root) {
  if (root == NULL)
    return;
  inorder(root->left);
  printf("%d ", root->val);
  inorder(root->right);
}

int main() {
  printf("Enter data to be stored in root node: ");
  int data;
  scanf("%d", &data);
  Node *root = createNode(data);
  int choice, key;
  while (1) {
    printf(
        "Enter 1 to insert node\n 2 to search for a node\n 3 to get inorder "
        "predecessor of a node\n 4 to get inorder successor of a node\n 5 to "
        "delete a node\n 6 to print inorder traversal\n 7 to exit\n");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      printf("Enter key to insert: ");
      scanf("%d", &key);
      insertNode(root, key);
      break;
    case 2:
      printf("Enter key to search: ");
      scanf("%d", &key);
      Node *temp1 = searchNode(root, key);
      if (temp1->left != NULL)
        printf("Left child: %d\n", temp1->left->val);
      else
        printf("Left child null\n");
      if (temp1->right != NULL)
        printf("Right child: %d\n", temp1->right->val);
      else
        printf("Right child null\n");
      break;
    case 3:
      printf("Enter key whose inorder predecessor you want to find: ");
      scanf("%d", &key);
      Node *temp2 = inorderPredecessor(root, key);
      if (temp2)
        printf("Inorder predecessor: %d\n", temp2->val);
      else
        printf("Inorder predecessor not found.\n");
      break;
    case 4:
      printf("Enter key whose inorder successor you want to find: ");
      scanf("%d", &key);
      Node *temp3 = inorderSuccessor(root, key);
      if (temp3)
        printf("Inorder successor: %d\n", temp3->val);
      else
        printf("Inorder successor not found.\n");
      break;
    case 5:
      printf("Enter the key to be deleted: ");
      scanf("%d", &key);
      deleteNode(root, key);
      break;
    case 6:
      inorder(root);
      printf("\n");
      break;
    case 7:
      return 0;
    }
  }
  return 0;
}
