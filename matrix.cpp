#include"vector.h"
#include"matrix.h"

using namespace mat_vec;
using namespace std;

// ������������ ������� � ��������� size x size, ����������� value
  Matrix::Matrix(size_t size, double value = 0){
    size_arr = size;
    array = new double[size_arr];
    for(size_t i = 0;i < size;i++){
        for(size_t j = 0;j < size;j++){
            array[i][j] = value;
        }
    }
}

// ���������� ��������� �������
  static Matrix::Matrix eye(size_t size){
    array = new double[src.size_arr];
    for(size_t i = 0;i < size;i++){
        for(size_t j = 0;j < size;j++){
            if((i!=j)&&(j!=(size-1)-i)){
                array[i][j]=0;
            }
        }
    }
    return array;

  }

// ���������� ������� � ��������� rows x cols, ����������� value
  Matrix::Matrix(size_t rows, size_t cols, double value = 0){
    array = new double[src.size_arr];
    for(size_t i = 0;i < size;i++){
        for(size_t j = 0;j < size;j++){
            array[i][j] = value;
        }
    }
    return array;
  }

  // ����������� �����������
  Matrix::Matrix(const Matrix &src){
    array = new double[src.size_arr];
    for(size_t i = 0;i < size;i++){
        for(size_t j = 0;j < size;j++){
            array[i][j] = src.array[i][j];
        }
    }
  }

  // �������� ������������
  Matrix &Matrix::operator=(const Matrix &rhs){
    for(size_t i = 0; i < this->size_arr;i++){
        for(size_t j = 0; j < this->size_arr;j++){
            this->array[i][j] = rhs.array[i][j];
        }
    }
    return *this;
  }

  // ����������
  Matrix::~Matrix(){
    delete array;
    return array;
  }

  // ������������ ��������
  Matrix Matrix::operator+(const Matrix &rhs) const{
    Matrix arr = new double[size_arr];

      for(size_t i = 0;i < size;i++){
        for(size_t j = 0;j < size;j++){
            arr.array[i][j] = this->array[i][j] + rhs.array[i][j];
        }
      }
      return arr;
  }

  Matrix &Matrix::operator+=(const Matrix &rhs){
    for(size_t i = 0;i < size;i++){
        for(size_t j = 0;j < size;j++){
            this->array[i][j] += rhs.array[i][j];
        }
    }
    return *this;
  }

  // ������������ ���������
  Matrix Matrix::operator-(const Matrix &rhs) const{
     Matrix arr = new double[size_arr];

      for(size_t i = 0;i < size;i++){
        for(size_t j = 0;j < size;j++){
            arr.array[i][j] = this->array[i][j] - rhs.array[i][j];
        }
      }

    return arr;
    }

  Matrix &Matrix::operator-=(const Matrix &rhs){
    for(size_t i = 0;i < size;i++){
        for(size_t j = 0;j < size;j++){
            this->array[i][j] -= rhs.array[i][j];
        }
    }
    return *this;
  }

  // ��������� ���������
  Matrix Matrix::operator*(const Matrix &rhs) const{
      Matrix arr = new double[size_arr];

      for(size_t i = 0;i < size;i++){
        for(size_t i = 0;i < size;i++){
            arr.array[i][j] = this->array[i][j] * rhs.array[i][j];
        }

        return arr;
      }
  }

  Matrix &Matrix::operator*=(const Matrix &rhs){
    for(size_t i = 0;i < size;i++){
        for(size_t j = 0;j < size;j++){
            this->array[i][j] *= rhs.array[i][j];
      }
    return *this;

    }
  }

  // ��������� ���� ��������� ������� �� ���������
  Matrix Matrix::operator*(double k) const{
    Matrix arr = Matrix(this->size);
    for(size_t i = 0;i < size;i++){
        for(size_t j = 0;j < size;j++){
            arr = this->array[i][j]*k;
        }
    return arr;
    }
  }

  Matrix &Matrix::operator*=(double k){
    for(size_t i = 0;i < size;i++){
        for(size_t j = 0;j < size;j++){
            this->array[i][j] *= k;
      }
    return *this;
    }
  }

  // ������� ���� ��������� ������� �� ���������
  Matrix Matrix::operator/(double k) const{
    Matrix arr = Matrix(this->size);
    for(size_t i = 0;i < size;i++){
        for(size_t j = 0;j < size;j++){
            array = this->array[i][j]/k;
    }
    return arr;
    }
  }

  Matrix &Matrix::operator/=(double k){
    for(size_t i = 0;i < size;i++){
        for(size_t j = 0;j < size;j++){
            this->array[i][j] /= k;
      }
    return *this;
    }
  }

  // ���������� ����� �������, ���������� ����������������� ������� (this)
  Matrix Matrix::transposed() const{
    Matrix matrix = Matrix(this->size);
    size_t x;
    for(size_t i = 0;i < size;i++){
        for(size_t j = 0;j < size;j++){
            x = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = x;
        }
    }
    return matrix;
  }

  // ������������� ������� �������
  void Matrix::transpose(){
    Matrix matrix = new double[size_arr];
    size_t x;
    for(size_t i = 0;i < size;i++){
        for(size_t j = 0;j < size;j++){
            x = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = x;
        }
    }
    return matrix;
  }
