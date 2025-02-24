#ifndef _SRC_MY_ARRAY_HPP_
#define _SRC_MY_ARRAY_HPP_
#include <cstddef>
#include <initializer_list>
#include <type_traits>

template <typename T>
struct get_type {
  using type = T;
};

template <typename T>
struct get_type<T*> {
  using type = T;
};

template <typename T>
class MyArray {
  using iterator = T*;
  using const_iterator = const T*;

 public:
  MyArray(std::size_t length);

  MyArray(const std::initializer_list<T>& arr_init);

  MyArray(std::initializer_list<T>&& arr_init);

  ~MyArray();

  iterator begin() const;

  const_iterator cbegin() const;

 private:
  T* data_;
};

template <typename T>
MyArray<T>::MyArray(std::size_t length) {
  if (length) {
    data_ = new T[length]();
  } else {
    data_ = nullptr;
  }
}

template <typename T>
MyArray<T>::~MyArray() {
  delete[] data_;
}

// 需要显示指示此为类型（否则无法判断是成员变量还是类型）
// 此为 typename 关键字被引入的原因
template <typename T>
typename MyArray<T>::iterator MyArray<T>::begin() const {
  return data_;
}

template <typename T>
typename MyArray<T>::const_iterator MyArray<T>::cbegin() const {
  return data_;
}

// 左值构造
template <typename T>
MyArray<T>::MyArray(const std::initializer_list<T>& arr_init) {
  if (arr_init.size()) {
    unsigned int count = 0;
    data_ = new T[arr_init.size()];
    if (std::is_pointer<T>::value) {
      for (auto elem : arr_init) {
        data_[count++] = new typename get_type<T>::type(*elem);
      }
    } else {
      for (const auto& elem : arr_init) {
        data_[count++] = elem;
      }
    }
  } else {
    data_ = nullptr;
  }
}

// 右值构造
template <typename T>
MyArray<T>::MyArray(std::initializer_list<T>&& arr_init) {
  if (arr_init.size()) {
    unsigned int count = 0;
    data_ = new T[arr_init.size()];
    for (const auto& elem : arr_init) {
      data_[count++] = elem;
    }
  } else {
    data_ = nullptr;
  }
}

#endif  // _SRC_MY_ARRAY_HPP_
