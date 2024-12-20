#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int val;
  struct node *next;
  struct node *prev;
} node;

node *createNode(int x) {
  node *newNode = (node *)malloc(sizeof(node));
  newNode->val = x;
  newNode->prev = newNode->next = NULL;
  return newNode;
}

node *insertNode(node *head, int pos, int key) {
  node *newNode = createNode(key);

  if (!head) {
    head = newNode;
    return head;
  }

  if (pos == 0) {
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
    return head;
  }

  node *temp = head;
  while (--pos) {
    if (!temp) {
      printf("Invalid position.\n");
      return head;
    }
    temp = temp->next;
  }

  newNode->next = temp->next;
  newNode->prev = temp;
  if (temp->next)
    temp->next->prev = newNode;
  temp->next = newNode;
  return head;
}

void deleteNode(node *head, int pos) {
  if (!head)
    return;

  if (pos == 0) {
    if (!head->next) {
      free(head);
      return;
    }
    head->next->prev = NULL;
    node *temp = head;
    head = head->next;
    temp->next = temp->prev = NULL;
    free(temp);
    return;
  }

  node *temp = head;
  while (--pos) {
    if (!temp || !temp->next) {
      printf("Invalid position\n");
      return;
    }
    temp = temp->next;
  }
  if (!temp->next) {
    printf("Invalid position.\n");
    return;
  }

  node *target = temp->next;
  if (target->next)
    target->next->prev = temp;
  temp->next = target->next;
  target->next = target->prev = NULL;
  free(target);
}

int countNodes(node *head) {
  int ctr = 0;
  while (head) {
    ++ctr;
    head = head->next;
  }
  return ctr;
}

void reversePrint(node *head) {
  while (head->next) {
    head = head->next;
  }
  printf("Linked list in reverse order: ");
  while (head) {
    printf("%d ", head->val);
    head = head->prev;
  }
  printf("\n");
}

void reverse(node *head) {
  node *left = head, *right = head;
  while (right->next) {
    right = right->next;
  }
  while (right != left && right->next != left) {
    int temp = left->val;
    left->val = right->val;
    right->val = temp;
    left = left->next;
    right = right->prev;
  }
}

int main() {
  node *head = createNode(0);
  printf("Enter value of first node: ");
  scanf("%d", &head->val);
  int choice;
  while (1) {
    printf("\nEnter 1 to insert node\n2 to delete node\n3 to count nodes\n4 to "
           "reverse print the linked list\n5 to reverse the list\n6 to exit\n");
    scanf("%d", &choice);
    int key, pos;
    switch (choice) {
    case 1:
      printf("Enter the value of the node to be inserted: ");
      scanf("%d", &key);
      printf("Enter the position where node is to be inserted: ");
      scanf("%d", &pos);
      head = insertNode(head, pos, key);
      break;
    case 2:
      printf("Enter the position of the node to be deleted: ");
      scanf("%d", &pos);
      deleteNode(head, pos);
      if (countNodes(head) == 0)
        head = createNode(0);
      break;
    case 3:
      printf("Number of nodes: %d\n\n", countNodes(head));
      break;
    case 4:
      reversePrint(head);
      break;
    case 5:
      reverse(head);
      break;
    default:
      return 0;
    }
  }
  return 0;
}
