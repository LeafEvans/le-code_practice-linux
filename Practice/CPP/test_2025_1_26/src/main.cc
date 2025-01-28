#include <cstdlib>
#include <cstring>
#include <ctime>

int main() {
  const int i = 100;
  auto i2 = 100;
  auto& ri = i;
  return 0;
}

#if false
int main() {
  // i 与 i2 在内存上相邻，从内存角度来看没有区别
  int i = 100;
  const int i2 = 10;
  // 下面为真正的常量
  100, "adca";
  return 0;
}
#endif

#if false
// 节点类型
struct Node {
  Node(int data = 0) : data(data), next(nullptr) {}

  int data;
  Node* next;
};

// 单向链表
class Clink {
 public:
  Clink() {
    head_ = new Node();
    tail_ = head_;
  }

  ~Clink() {
    // 节点的释放
    Node* curr_node = head_;

    while (curr_node != nullptr) {
      Node* temp = curr_node;
      curr_node = curr_node->next;
      delete temp;
    }

    head_ = nullptr;
  }

  // 链表尾插法
  void InsertTail(int val) {
    Node* node = new Node(val);
    tail_->next = node;
    tail_ = node;
  }

  // 链表头插法
  void InsertHead(int val) {
    Node* node = new Node(val);
    node->next = head_->next;
    head_->next = node;
    if (tail_ == head_) {
      tail_ = node;
    }
  }

  // 链表节点的删除
  void Remove(int val) {
    Node* prev_node = head_;
    Node* curr_node = head_->next;

    // 遍历链表，查找值为 val 的节点
    while (curr_node != nullptr && curr_node->data != val) {
      prev_node = curr_node;
      curr_node = curr_node->next;
    }

    // 如果找到目标节点
    if (curr_node != nullptr) {
      prev_node->next = curr_node->next;

      // 如果删除的是尾节点，更新 tail_
      if (curr_node == tail_) {
        tail_ = prev_node;
      }

      delete curr_node;  // 释放节点内存
    }
  }

  // 删除所有节点
  void RemoveAll(int val) {
    Node* prev_node = head_;
    Node* curr_node = head_->next;

    // 遍历整个链表
    while (curr_node != nullptr) {
      if (curr_node->data == val) {
        // 找到匹配的节点，删除它
        prev_node->next = curr_node->next;  // 跳过当前节点

        // 如果删除的是尾节点，更新 tail_
        if (curr_node == tail_) {
          tail_ = prev_node;
        }

        Node* temp = curr_node;       // 保存当前节点以便释放内存
        curr_node = curr_node->next;  // 移动到下一个节点
        delete temp;                  // 释放内存
      } else {
        prev_node = curr_node;  // 没有匹配，继续遍历
        curr_node = curr_node->next;
      }
    }
  }

  bool Find(int val) {
    Node* curr_node = head_->next;
    while (curr_node != nullptr) {
      if (curr_node->data == val) {
        return true;
      }
      curr_node = curr_node->next;
    }
    return false;
  }

  // 打印链表
  void Show() {
    Node* curr_node = head_->next;
    while (curr_node != nullptr) {
      std::cout << curr_node->data << ' ';
      curr_node = curr_node->next;
    }
    std::cout << '\n';
  }

 private:
  Node* head_;
  Node* tail_;
};

int main() {
  Clink link;
  srand(time(NULL));
  for (int i = 0; i < 10; ++i) {
    int val = rand() % 100;
    link.InsertHead(val);
    std::cout << val << ' ';
  }
  std::cout << '\n';
  link.InsertTail(200);
  link.Show();
  std::cout << link.Find(200) << '\n';
  return 0;
}
#endif

#if false
// 整形数组，将偶数调整到数组的左侧，奇数调整到数组的右侧
void AdjustArray(int arr[], int length) {
  int left = 0, right = length - 1;
  while (left < right) {

    while (left < right && (arr[left] & 1) == 0) {
      ++left;
    }

    while (left < right && (arr[right] & 1) == 1) {
      --right;
    }
    if (left < right) {
      std::swap(arr[left++], arr[right--]);
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
#endif

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
