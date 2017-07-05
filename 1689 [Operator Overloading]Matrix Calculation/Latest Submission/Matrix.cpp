#include "Matrix.h"
#include <cstring>
Matrix::Matrix(string name_, int height_, int width_, int** matrix) {
  name = name_;
  height = height_;
  width = width_;
  param = new int*[height];
  for (int hindex = 0; hindex < height; ++hindex) {
    param[hindex] = new int[width];
    memset(param[hindex], 0, width * sizeof(int));
    for (int windex = 0; windex < width; ++windex) {
      param[hindex][windex] = matrix[hindex][windex];
    }
  }
}
Matrix::Matrix(const Matrix& source) {
  name = source.name;
  height = source.height;
  width = source.width;
  param = new int*[height];
  for (int hindex = 0; hindex < height; ++hindex) {
    param[hindex] = new int[width];
    memset(param[hindex], 0, width * sizeof(int));
    for (int windex = 0; windex < width; ++windex) {
      param[hindex][windex] = source.param[hindex][windex];
    }
  }
}
Matrix::~Matrix() {
  for (int hindex = 0; hindex < height; ++hindex) {
    delete[] param[hindex];
  }
  delete[] param;
  name = "";
  height = 0;
  width = 0;
}
bool Matrix::operator ==(const Matrix& matrix) {
  for (int hindex = 0; hindex < height; ++hindex) {
    for (int windex = 0; windex < width; ++windex) {
      if (param[hindex][windex] != matrix.param[hindex][windex])
        return false;
    }
  }
  return true;
}
bool Matrix::operator !=(const Matrix& matrix) {
  for (int hindex = 0; hindex < height; ++hindex) {
    for (int windex = 0; windex < width; ++windex) {
      if (param[hindex][windex] != matrix.param[hindex][windex])
        return true;
    }
  }
  return false;
}
void Matrix::operator +=(const Matrix& matrix) {
  if (height != matrix.height || width != matrix.width) {
    cout << "invalid addition." << endl;
    return;
  }
  for (int hindex = 0; hindex < height; ++hindex) {
    for (int windex = 0; windex < width; ++windex) {
      param[hindex][windex] += matrix.param[hindex][windex];
    }
  }
}
void Matrix::operator -=(const Matrix& matrix) {
  if (height != matrix.height || width != matrix.width) {
    cout << "invalid substraction." << endl;
    return;
  }
  for (int hindex = 0; hindex < height; ++hindex) {
    for (int windex = 0; windex < width; ++windex) {
      param[hindex][windex] -= matrix.param[hindex][windex];
    }
  }
}
Matrix Matrix::operator *(const Matrix& matrix) {
  if (width != matrix.height) {
    cout << "invalid multiplication."  << endl;
    Matrix empty;
    return empty;
  }
  int hei = height, wid = matrix.width;
  int **res = new int*[hei];
  for (int hindex = 0; hindex < hei; ++hindex) {
    res[hindex] = new int[wid];
    memset(res[hindex], 0, wid * sizeof(int));
  }
  for (int hindex = 0; hindex < hei; ++hindex) {
    for (int windex = 0; windex < wid; ++windex) {
      int key = 0;
      for (int pos = 0; pos < width; ++pos) {
        key += param[hindex][pos] * matrix.param[pos][windex];
      }
      res[hindex][windex] = key;
    }
  }
  Matrix result("newMat", hei, wid, res);
  for (int hindex = 0; hindex < hei; ++hindex) {
    delete[] res[hindex];
  }
  delete[] res;
  return result; 
}