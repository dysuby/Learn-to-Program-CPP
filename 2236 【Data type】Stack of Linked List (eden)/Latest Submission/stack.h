#ifndef STACK_H
#define STACK_H
#include "Node.h"
#include <stdlib.h>
#include <memory.h>
void push(Node** top, int n) {
  if (*top) {
    Node* newtop = (Node*)malloc(sizeof(Node));
    memset(newtop, sizeof(Node), 0);
    newtop -> num = n;
    newtop -> next = *top;
    *top = newtop;
  } else {
    Node* newtop = (Node*)malloc(sizeof(Node));
    memset(newtop, sizeof(Node), 0);
    newtop -> num = n;
    newtop -> next = NULL;
    *top = newtop;
  }
}
int pop(Node** top) {
  int res = -1;
  if (*top) {
    Node* temp = *top;
    *top = temp -> next;
    res = temp -> num;
    free(temp);
  }
  return res;
}

void del(Node** top) {
  while (*top) {
    Node* temp = *top;
    *top = temp -> next;
    free(temp);
  }
}
#endif