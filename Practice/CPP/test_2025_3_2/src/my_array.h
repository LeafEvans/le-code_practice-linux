#ifndef _SRC_MY_ARRAY_H_
#define _SRC_MY_ARRAY_H_
#include <cstddef>
#include <utility>

template <typename T>
class MyArray {
  using Iterator = T*;
  using ConstIterator = const T*;

 public:
  MyArray(std::size_t size);
  MyArray(const std::initializer_list<T>& arr_init);
  MyArray(std::initializer_list<T>&& arr_init);
  ~MyArray();
  Iterator begin();
  const T* cbegin() const;

 private:
  T* data_;
};

template <typename T>
MyArray<T>::MyArray(std::size_t size) : data_{size ? new T[size] : nullptr} {}

template <typename T>
MyArray<T>::MyArray(const std::initializer_list<T>& arr_init)
    : data_{arr_init.size() ? new T[arr_init.size()] : nullptr} {
  if (arr_init.size()) {
    unsigned i = 0;
    if (std::is_pointer_v<T>) {
      for (const auto& elem : arr_init) {
        data_[i++] = new std::remove_pointer_t<T>{*elem};
      }
    } else {
      for (const auto& elem : arr_init) {
        data_[i++] = elem;
      }
    }
  }
}

template <typename T>
MyArray<T>::MyArray(std::initializer_list<T>&& arr_init)
    : data_{arr_init.size() ? new T[arr_init.size()] : nullptr} {
  if (arr_init.size()) {
    unsigned i = 0;
    for (const auto& elem : arr_init) {
      data_[i++] = std::move(elem);
    }
  }
}

template <typename T>
MyArray<T>::~MyArray() {
  delete[] data_;
}

template <typename T>
typename MyArray<T>::Iterator MyArray<T>::begin() {
  return data_;
}

template <typename T>
typename MyArray<T>::ConstIterator MyArray<T>::cbegin() const {
  return data_;
}

#endif  // _SRC_MY_ARRAY_H_