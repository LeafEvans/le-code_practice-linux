#ifndef _SRC_MY_ARRAY_HPP_
#define _SRC_MY_ARRAY_HPP_
#include <cstddef>
#include <initializer_list>
#include <type_traits>
#include <utility>

template <typename T>
class MyArray {
  using iterator = T*;
  using const_iterator = const T*;

 public:
  MyArray(std::size_t length);

  MyArray(const std::initializer_list<T>& arr_init);

  MyArray(std::initializer_list<T>&& arr_init);

  ~MyArray();

  iterator begin();

  const_iterator cbegin() const;

 private:
  T* data_;
};

template <typename T>
MyArray<T>::MyArray(std::size_t length) {
  if (length) {
    data_ = new T[length];
  } else {
    data_ = nullptr;
  }
}

template <typename T>
MyArray<T>::~MyArray() {
  delete[] data_;
}

template <typename T>
typename MyArray<T>::iterator MyArray<T>::begin() {
  return data_;
}

template <typename T>
typename MyArray<T>::const_iterator MyArray<T>::cbegin() const {
  return data_;
}

template <typename T>
MyArray<T>::MyArray(const std::initializer_list<T>& arr_init) {
  if (arr_init.size()) {
    size_t count = 0;
    data_ = new T[arr_init.size()];
    if (std::is_pointer<T>::value) {
      for (auto elem : arr_init) {
        data_[count++] = new typename std::remove_pointer<T>::type(*elem);
      }
    } else {
      for (const auto& elem : arr_init) {
        data_[count++] = elem;
      }
    }
  }
}

template <typename T>
MyArray<T>::MyArray(std::initializer_list<T>&& arr_init) {
  if (arr_init.size()) {
    size_t count = 0;
    data_ = new T[arr_init.size()];
    for (auto& elem : arr_init) {
      data_[count++] = std::move(elem);
    }
  } else {
    data_ = nullptr;
  }
}

#endif  // _SRC_MY_ARRAY_HPP_
