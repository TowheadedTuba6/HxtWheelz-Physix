#ifndef MATRIX4_H
#define MATRIX4_H

class Matrix4 {
private:
  float data[4][4];

public:
  Matrix4() { setIdenty(); }

  Matrix4(float values[4][4]) {
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        data[i][j] = values[i][j];
      }
    }
  }

  void setIdenty() {
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        data[i][j] = (i == j) ? 1.0f : 0.0f;
      }
    }
  }

  float& operator()(int row, int col) { return data[row][col]; }

  const float& operator()(int row, int col) const { return data[row][col]; }

  Matrix4 operator*(const Matrix4& other) const {
    Matrix4 result;

    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        result(i, j) = 0.0f;
        for (int k = 0; k < 4; k++) {
          result(i, j) += data[i][k] * other(k, j);
        }
      }
    }

    return result;
  }
};

#endif /* MATRIX4_H */