#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int val;
  struct node *next;
} node;

node *createNode(int x) {
  node *temp = (node *)malloc(sizeof(node));
  temp->val = x;
  temp->next = NULL;
  return temp;
}

node *insertNode(node *head, int pos, int key) {
  node *newNode = createNode(key);

  if (!head)
    return NULL;

  if (pos == 0) {
    newNode->next = head;
    head = newNode;
    return head;
  }

  node *temp = head;

  while (--pos) {
    if (!temp) {
      printf("Invalid position\n");
      return head;
    }
    temp = temp->next;
  }

  newNode->next = temp->next;
  temp->next = newNode;
  return head;
}

void deleteNode(node *head, int pos) {
  if (!head)
    return;

  if (pos == 0) {
    node *temp = head;
    head = head->next;
    temp->next = NULL;
    free(temp);
    return;
  }

  while (--pos) {
    if (!head || !head->next) {
      printf("Invalid position\n");
      return;
    }
    head = head->next;
  }
  if (!head->next) {
    printf("Invalid position.\n");
    return;
  }
  node *temp = head->next;
  head->next = temp->next;
  temp->next = NULL;
  free(temp);
}

int countNodes(node *head) {
  int ctr = 0;
  while (head != NULL) {
    ++ctr;
    head = head->next;
  }
  return ctr;
}

void reversePrint(node *head) {
  node *end = NULL, *temp = head;
  while (end != head) {
    temp = head;
    while (temp->next != end)
      temp = temp->next;
    printf("%d ", temp->val);
    end = temp;
  }
  printf("\n");
}

node *reverse(node *head) {
  node *prev = NULL, *curr = head, *future = head->next;

  while (curr) {
    curr->next = prev;
    prev = curr;
    curr = future;
    if (future)
      future = future->next;
  }
  head = prev;
  return head;
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
      head = reverse(head);
      break;
    default:
      return 0;
    }
  }
  return 0;
}
