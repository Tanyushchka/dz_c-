#include"vector.h"
#include"matrix.h"

using namespace mat_vec;
using namespace std;

// Конструирует вектор размера size со значениями value
 Vector::Vector(size_t size, double value = 0){
    size_arr = size;
    array = new double[size_arr];
    for(size_t i = 0;i < size;i++){
        array[i] = value;
    }
}
// Конструктор копирования
 Vector::Vector(const Vector &src){
    array = new double[src.size_arr];
    for(size_t i = 0;i < size;i++){
        array[i] = src.array[i];
    }
}

// Оператор присваивания
 Vector &Vector::operator=(const Vector &rhs){
    for(size_t i = 0; i < this->size_arr;i++){
        this->array[i] = rhs.array[i];
    }
    return *this;
}

// Деструктор
 Vector::~Vector(){
    delete array;
    return array;
  }

// Возвращает размер вектора
 size_t Vector::size() const{
    return size_arr;
}

// Доступ к n-му элементу вектора
 double Vector::operator[](size_t n) const{
    return();
}
 double &Vector::operator[](size_t n){
    return(array[n]);
}

// L2 норма вектора
 double Vector::norm() const{
    size_t sum;
    for(size_t i = 0; i < this->size_arr;i++){
        sum += sqrt(pow(i, 2));
    }
    return *this;
}

// Нормализует текущий вектор
 void Vector::normalize(){
   double n = array.norm();
   for(size_t i = 0;i < size;i++){
        array[i] = array[i] / n;
   }
   return *this;
}

// Поэлементное сложение векторов
  Vector Vector::operator+(const Vector &rhs) const{
      Vector arr = new double[size_arr];
      for(size_t i = 0;i < size;i++){
        arr.array[i] = this->array[i] + rhs.array[i];
      }

    return arr;
}

  Vector &Vector::operator+=(const Vector &rhs){
    for(size_t i = 0;i < size;i++){
        this->array[i] += rhs.array[i];

    }
    return *this;
}

 // Поэлементное вычитание векторов
  Vector Vector::operator-(const Vector &rhs) const{
       Vector arr = new double[size_arr];

      for(size_t i = 0;i < size;i++){
        arr.array[i] = this->array[i] - rhs.array[i];
      }

    return arr;
}

  Vector &Vector::operator-=(const Vector &rhs){
    for(size_t i = 0;i < size;i++){
        this->array[i] -= rhs.array[i];

    }
    return *this;
}

// Поэлементное умножение векторов
  Vector Vector::operator^(const Vector &rhs) const{
      Vector arr = new double[size_arr];

      for(size_t i = 0;i < size;i++){
        arr.array[i] = this->array[i] * rhs.array[i];
      }

    return arr;
}

  Vector &Vector::operator^=(const Vector &rhs){
     for(size_t i = 0;i < size;i++){
        this->array[i] *= rhs.array[i];
      }

    return *this;

  }

// Скалярное произведение
 double Vector::operator*(const Vector &rhs) const{
    Vector arr = new double[size_arr];
    double k = 0;
    for(size_t i = 0;i < size;i++){
        k +=this->array[i]*rhs.array[i];
    }
    return k;

  }

// Умножение всех элементов вектора на скаляр справа (v * k)
  Vector Vector::operator*(double k) const{
    Vector arr = Vector(this->size);
    for(size_t i = 0;i < size;i++){
        arr = this->array[i]*k;
    }
    return arr;
  }

  Vector &Vector::operator*=(double k){
     for(size_t i = 0;i < size;i++){
        this->array[i] *= k;
      }
    return *this;
  }

// Деление всех элементов вектора на скаляр
  Vector Vector::operator/(double k) const{
    Vector arr = Vector(this->size);
    for(size_t i = 0;i < size;i++){
        array = this->array[i]/k;
    }
    return arr;
  }

  Vector &Vector::operator/=(double k){
    for(size_t i = 0;i < size;i++){
        this->array[i] /= k;
      }
    return *this;
  }

// Поэлементное сравнение
  bool Vector::operator==(const Vector &rhs) const{
    Vector arr = Vector(this->size);
    for(size_t i = 0;i < size;i++){
        if(arr.array[i] == rsh.array[i]){
            return(true);
        }
        else{
            return(false);
        }
    }
  }

  bool Vector::operator!=(const Vector &rhs) const{
    Vector arr = Vector(this->size);
    for(size_t i = 0;i < size;i++){
        if(arr.array[i] != rhs.array[i]){
            return(true);
        }
        else{
            return(false);
        }
    }
  }
