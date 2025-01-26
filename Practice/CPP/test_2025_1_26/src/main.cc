#include <cstdlib>
#include <cstring>
#include <ctime>

#include <iostream>
#include <utility>

// 整形数组，将偶数调整到数组的左侧，奇数调整到数组的右侧
void AdjustArray(int arr[], int length) {
  int left = 0, right = length - 1;
  while (left < right) {
    if (left < right && (arr[left] & 1) == 0) {
      ++left;
    }

    if (left < right && (arr[left] & 1) == 1) {
      --right;
    }

    if (left < right) {
      std::swap(arr[left++], arr[right++]);
    }
  }
}

int main() {
  int arr[10] = {0};
  srand(time(NULL));
  for (int i = 0; i < 10; ++i) {
    arr[i] = rand() % 100;
    std::cout << arr[i] << ' ';
  }
  std::cout << '\n';

  AdjustArray(arr, 10);
  for (int elem : arr) {
    std::cout << elem << ' ';
  }
  std::cout << '\n';
  return 0;
}

#if false
// 逆序字符串
void Reverse(char arr[], int length) {
  int left = 0, right = length - 1;
  while (left < right) {
    std::swap(arr[left++], arr[right--]);    
  }
}

int main() {
  char arr[] = "Hello, world!";
  Reverse(arr, strlen(arr));
  std::cout << arr << '\n';
  return 0;
}
#endif

#if false
class Array {
 public:
  Array(int capacity = 10) : capacity_(capacity), size_(0) {
    arr_ = new int[capacity_]();
  }

  ~Array() {
    delete[] arr_;
    arr_ = nullptr;
  }

 public:
  // 末尾增加元素：O(1)
  void PushBack(int val) {
    if (size_ == capacity_) {
      expand(2 * capacity_);
    }
    arr_[size_++] = val;
  }

  // 末尾删除元素：O(1)
  void PopBack() {
    if (size_ == 0)
      return;
    --size_;
  }

  // 按位置增加元素：O(n)
  void Insert(int pos, int val) {
    if (pos < 0 || pos > size_) {
      throw "Pos is invalid!";
    }

    if (size_ == capacity_) {
      expand(2 * capacity_);
    }

    // 移动元素
    memmove(arr_ + pos + 1, arr_ + pos, sizeof(int) * (size_ - pos));

    arr_[pos] = val;
    ++size_;
  }

  // 按位置删除：O(n)
  void Erase(int pos) {
    if (pos < 0 || pos >= size_) {
      throw "Pos is invalid!";
    }

    // 移动元素
    memmove(arr_ + pos, arr_ + pos + 1, sizeof(int) * (size_ - pos - 1));

    --size_;
  }

  // 元素查询：O(n)
  int Find(int val) {
    for (int i = 0; i < size_; ++i) {
      if (arr_[i] == val) {
        return i;
      }
    }
    return -1;
  }

  // 打印数据
  void Show() {
    for (int i = 0; i < size_; ++i) {
      std::cout << arr_[i] << ' ';
    }
    std::cout << '\n';
  }

 private:
  // 内部数组扩容接口
  void expand(int capacity) {
    int* new_arr = new int[capacity];
    memcpy(new_arr, arr_, sizeof(int) * size_);
    delete[] arr_;
    arr_ = new_arr;
    capacity_ = capacity;
  }

 private:
  int* arr_;      // 指向可扩容的数组内存
  int capacity_;  // 数组的容量
  int size_;      // 数组有效元素个数
};

int main() {
  Array arr;
  srand(time(0));
  for (int i = 0; i < 10; ++i) {
    arr.PushBack(rand() % 10);
  }
  arr.Show();
  arr.PopBack();
  arr.Show();

  arr.Insert(0, 100);
  arr.Show();
  arr.Insert(10, 200);
  arr.Show();

  int pos = arr.Find(100);
  if (pos != -1) {
    arr.Erase(pos);
  }
  arr.Show();
  return 0;
}
#endif
