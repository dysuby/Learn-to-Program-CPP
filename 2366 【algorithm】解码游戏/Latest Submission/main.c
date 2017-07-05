#include <stdio.h>
#include <string.h>
#define oper  str[index] = matrix[h][w]; \
              ++index; \
              ++i;

void getRes(char* str, char toDel[][100], int t) {
  for (int index = 0; index < strlen(str); ++index) {
    if (str[index] == '*')
      continue;
    for (int i = 0; i < t; ++i) {
      int com = index;
      int k = 0;
      while (toDel[i][k] == str[index + k]) {
       ++k;
      }
      if (toDel[i][k] == '\0') {
        for (int j = 1; j < k; ++j)
          str[j + index] = '*';
      }
    }
  }
}

int main() {
  int height = 0, width = 0;
  scanf("%d%d", &height, &width);
  getchar();
  char matrix[50][50] = {0};
  for (int i = 0; i < height; ++i) {
    for (int j = 0; j < width; ++j) {
      scanf("%c", &matrix[i][j]);
    }
    getchar();
  }
  char str[2501] = {0};
  int index = 0;
  int h = 0, w = 0, j = 0;
  for (int i = 0; i < height * width; ) {
    for ( ; i < height * width && h < height - j; ++h) {
      oper
    }
    --h;
    ++w;
    for ( ; i < height * width && w < width - j; ++w) {
      oper
    }
    --w;
    --h;
    for ( ; i < height * width && h >= j; --h) {
      oper
    }
    ++j;
    ++h;
    --w;
    for ( ; i < height * width && w >= j; --w) {
      oper
    }
    ++h;
    ++w;
  }
  str[height * width] = 0;
  printf("%s\n", str);
  int t = 0;
  scanf("%d", &t);
  char toDel[10][100] = {0};
  for (int index = 0; index < t; ++index)
    scanf("%s", toDel[index]);
  getRes(str, toDel, t);
  printf("%s\n", str);
  return 0;
}