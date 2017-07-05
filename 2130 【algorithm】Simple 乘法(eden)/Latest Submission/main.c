#include <stdio.h>
#include <string.h>
#include <ctype.h>

void output(int* res, int len) {
  int i = 0;
  while (res[i] == 0)
    ++i;
  for ( ; i < len; ++i) {
    printf("%d", res[i]);
  }
  putchar('\n');
}

void SimpleMulti(char* A, char* B) {
  int lenOfA = strlen(A);
  int lenOfB = strlen(B);
  int Aindex = 0, Bindex = 0, pos = 0, begin;
  int res[50000] = {0};
  for (Aindex = lenOfA - 1; Aindex >= 0; --Aindex) {
    begin = 50000 - (lenOfA - Aindex);
    for (Bindex = lenOfB - 1; Bindex >= 0; --Bindex) {
      int temp = res[begin];
      res[begin] = (temp + (A[Aindex] - '0') * (B[Bindex] - '0') + pos)
                    % 10;
      pos = (temp + (A[Aindex] - '0') * (B[Bindex] - '0') + pos) / 10;
      --begin;
    }
    while (pos) {
      int temp = res[begin];
      res[begin] = (temp + pos) % 10;
      pos = (temp + pos) / 10;
      --begin;
    }
  }
  output(res, 50000);
}

int main() {
  char A[1000] = {0}, B[1000] = {0};
  char temp = 0;
  while (!isdigit(temp = getchar())) {
    continue;
  }
  A[0] = temp;
  for (int i = 1; isdigit(temp = getchar()); ++i) {
    A[i] = temp;
  }
  while (!isdigit(temp = getchar())) {
    continue;
  }
  B[0] = temp;
  for (int i = 1; isdigit(temp = getchar()); ++i) {
    B[i] = temp;
  }
  SimpleMulti(A, B);
  return 0;
}