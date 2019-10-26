#include"vector.h"
#include"matrix.h"

using namespace mat_vec;
using namespace std;

// Конструирует матрицу с размерами size x size, заполненную value
  Matrix::Matrix(size_t size, double value = 0){
    size_arr = size;
    array = new double[size_arr];
    for(size_t i = 0;i < size;i++){
        for(size_t j = 0;j < size;j++){
            array[i][j] = value;
        }
    }
}

// Возвращает единичную матрицу
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

// Возвращает матрицу с размерами rows x cols, заполненную value
  Matrix::Matrix(size_t rows, size_t cols, double value = 0){
    array = new double[src.size_arr];
    for(size_t i = 0;i < size;i++){
        for(size_t j = 0;j < size;j++){
            array[i][j] = value;
        }
    }
    return array;
  }

  // Конструктор копирования
  Matrix::Matrix(const Matrix &src){
    array = new double[src.size_arr];
    for(size_t i = 0;i < size;i++){
        for(size_t j = 0;j < size;j++){
            array[i][j] = src.array[i][j];
        }
    }
  }

  // Оператор присваивания
  Matrix &Matrix::operator=(const Matrix &rhs){
    for(size_t i = 0; i < this->size_arr;i++){
        for(size_t j = 0; j < this->size_arr;j++){
            this->array[i][j] = rhs.array[i][j];
        }
    }
    return *this;
  }

  // Деструктор
  Matrix::~Matrix(){
    delete array;
    return array;
  }

  // Поэлементное сложение
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

  // Поэлементное вычитание
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

  // Матричное умножение
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

  // Умножение всех элементов матрицы на константу
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

  // Деление всех элементов матрицы на константу
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

  // Возвращает новую матрицу, полученную транспонированием текущей (this)
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

  // Транспонирует текущую матрицу
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
