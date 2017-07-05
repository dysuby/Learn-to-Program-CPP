#include <stdio.h>
#include "queue.hpp"

void test_queue(void) {
  if (true) {
    queue qu;
    for (int i = 0; i < 5; i++) {
      qu.push(i);
    }
    qu.isEmpty() ? printf("empty\n") : printf("not empty\n");
    qu.isFull() ? printf("full\n") : printf("not full\n");
    for (int i = 0; i < 5; i++) {
      printf("(%d,%d) ", qu.front(), qu.back());
      qu.pop();
    }
    printf("\n");
    qu.isEmpty() ? printf("empty\n") : printf("not empty\n");
    qu.isFull() ? printf("full\n") : printf("not full\n");
  }
  printf("\n");
  if (true) {
    queue qu;
    for (int i = 0; i < 11; i++) {
      qu.push(i);
    }
    qu.isEmpty() ? printf("empty\n") : printf("not empty\n");
    qu.isFull() ? printf("full\n") : printf("not full\n");
    for (int i = 0; i < 11; i++) {
      printf("(%d,%d) ", qu.front(), qu.back());
      qu.pop();
    }
    printf("\n");
    qu.isEmpty() ? printf("empty\n") : printf("not empty\n");
    qu.isFull() ? printf("full\n") : printf("not full\n");
  }
  printf("\n");
  if (true) {
    queue qu;
    for (int i = 0; i < 11; i++) {
      qu.push(i);
    }
    qu.isEmpty() ? printf("empty\n") : printf("not empty\n");
    qu.isFull() ? printf("full\n") : printf("not full\n");
    qu.clear();
    qu.isEmpty() ? printf("empty\n") : printf("not empty\n");
    qu.isFull() ? printf("full\n") : printf("not full\n");
    for (int i = 0; i < 5; i++) {
      qu.push(i);
    }
    for (int i = 0; i < 5; i++) {
      printf("(%d,%d) ", qu.front(), qu.back());
      qu.pop();
    }
    printf("\n");
    qu.isEmpty() ? printf("empty\n") : printf("not empty\n");
    qu.isFull() ? printf("full\n") : printf("not full\n");
  }
  printf("\n");
}

int main() {
  test_queue();
  return 0;
}
