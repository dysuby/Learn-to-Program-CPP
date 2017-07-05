#include "mergeSortedList.h"

void push_front(node** head, int val) {
  node *temp = (node*)malloc(sizeof(node));
  temp -> val = val;
  temp -> next = *head;
  *head = temp;
}

node* mergeSortedList(node* head1, node* head2) {
  node *a = head1, *b = head2;
  node *head = NULL;
  node *temp = head;
  while (a && b) {
    if (!head) {
      head = (head1 -> val < head2 -> val) ? head1 : head2;
      (head1 -> val < head2 -> val) ? (a = a -> next) : (b = b -> next);
      temp = head;
      continue;
    }
    if (a -> val > b -> val) {
      temp -> next = b;
      b = b -> next;
    } else {
      temp -> next = a;
      a = a -> next;
    }
    temp = temp -> next;
  }
  if (a) 
    temp ? (temp -> next = a) : (head = a);
  else if (b)
    temp ? (temp -> next = b) : (head = b);
  return head;
}