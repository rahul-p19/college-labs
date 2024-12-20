#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
  int top, size;
  int arr[100];
} stack;

stack *createStack(int s) {
  stack *newStack = (stack *)malloc(sizeof(stack));
  newStack->top = -1;
  newStack->size = s;
  return newStack;
}

void push(stack *s, int key) {
  if (s->top == s->size - 1) {
    printf("Stack full. Can't enter more elements.\n");
    return;
  }

  s->arr[++s->top] = key;
}

int pop(stack *s) {
  if (s->top == -1) {
    printf("Stack is empty. Nothing to pop.\n");
    return -1;
  }
  return s->arr[s->top--];
}

typedef struct queue {
  struct stack *s1, *s2;
} queue;

queue *createQueue(int s) {
  queue *newQueue = (queue *)malloc(sizeof(queue));
  newQueue->s1 = createStack(s);
  newQueue->s2 = createStack(s);
  return newQueue;
}

void enqueue(queue *q, int key) {
  while (q->s1->top > -1) {
    push(q->s2, pop(q->s1));
  }
  push(q->s1, key);
  while (q->s2->top > -1) {
    push(q->s1, pop(q->s2));
  }
}

int dequeue(queue *q) { return pop(q->s1); }

void printQueue(queue *q) {
  int i;
  printf("Queue: ");
  for (i = 0; i <= q->s1->top; i++) {
    printf("%d ", q->s1->arr[i]);
  }
  printf("\n");
}

int main() {
  int s, choice, key;
  printf("Enter maximum size of queue: ");
  scanf("%d", &s);
  queue *q = createQueue(s);

  while (1) {
    printf(
        "\nQueue Operations:\n1.Enqueue\n2.Dequeue\n3.Display queue\n4.Exit\n");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      printf("Enter value to be enqueued: ");
      scanf("%d", &key);
      enqueue(q, key);
      break;
    case 2:
      printf("Dequeued element: %d\n", dequeue(q));
      break;
    case 3:
      printQueue(q);
      break;
    default:
      return 0;
    }
  }
  return 0;
}
