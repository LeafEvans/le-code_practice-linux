#if false
int main(int argc, char** argv) {
  auto i = 100;  // 定义一个变量 i，类型由编译器自动推导为 int
  auto & i2 = i;
  // 输出变量 i 的类型
  std::cout << type_id_with_cvr<decltype(i2)>() << std::endl;
  return 0;
}
#endif

#if false
int main() {
  int i = 100;
  const int& refI = i;
  auto i2 = refI;  // 与语句 auto i2 = i; 等价，直接替换
  std::cout << type_id_with_cvr<decltype(i2)>() << std::endl;
  return 0;
}
#endif

#if false
int main() {
  int i = 100;
  const int* const pi = &i;
  auto pi2 = pi;
  std::cout << type_id_with_cvr<decltype(pi2)>() << std::endl;
  return 0;
}
#endif

#if false
int main() {
  const int i = 10;
  auto i2 = i;
  std::cout << type_id_with_cvr<decltype(i2)>() << std::endl;
  return 0;
}
#endif

#if false
int main() {
  int i = 100;
  const int* const pi = &i;
  auto& i2 = pi;
  std::cout << type_id_with_cvr<decltype(i2)>() << std::endl;
  return 0;
}
#endif

#if false
int main() {
  const int i = 100;
  const auto i2 = i;
    std::cout << type_id_with_cvr<decltype(i2)>() << std::endl;
  return 0;
}
#endif

#if false
unsigned g_i = 0;

int main() {
  // 因为编译时已经初始化，所以这段代码可以正确执行
  ++g_i;
  return 0;
}
#endif

#if false
unsigned Test() {
  static unsigned call_count = 0;
  return ++call_count;
}

int main() {
  Test();
  Test();
  Test();
  unsigned test_func_call_count = Test();
  std::cout << test_func_call_count << '\n';
  return 0;
}
#endif

#if false
int main() {
  int i = 10;
  // i + 1 就是临时对象
  int i2 = (i + 1);  
  return 0;
}
#endif

#if false
int main() {
  const int i = 100;
  auto& refI = i;  // 若 const int i = 100; 的话，则该句报错
  return 0;
}
#endif

#if false
int main() {
  int i = 100;
  int&& rrefI = i + 1;
  int&& rrefJ = i++;
  int&& rrefK = 200;
  return 0;
}
#endif

#if false
#include <utility>

int main() {
  int i = 10;
  int&& i_rvalue = std::move(i);
  // 不使用类似 i = 2; 等这种使用 i 的语句
  return 0;
}
#endif

#if false
int GetI() {
  return 10;
}

int main() {
  int i = 10;
  int i2 = i + 1;           // 临时对象
  int&& i_rvalue = GetI();  // 临时对象
  return 0;
}
#endif

#if false
#include <iostream>

void Test(int i) {
  std::cout << i << std::endl;
  std::cout << "Hello, world!" << std::endl;
}

using FuncPtrType = void (*)(int);

void MyFunc(FuncPtrType func_ptr, int i) {
  func_ptr(i);
}

int main() {
  MyFunc(Test, 200);
  return 0;
}
#endif

#if false
#include <functional>
#include <iostream>

void MyFunc(std::function<void(int)> func, int i) {
  func(i);
}

int main() {
  int i = 10;
  int j = 100;
  MyFunc(
      [](int i) {
        std::cout << i << std::endl;
        std::cout << "lambda" << std::endl;
      },
      200);
  return 0;
}
#endif

#if false
#include <iostream>
#include <string>

class Test {
 public:
  Test(const std::string& name, unsigned int age) : name_(name), age_(age) {}
  ~Test() {}

  void OutPut() const {
    std::cout << "Name = " << this->name_ << ", Age = " << this->age_
              << std::endl;
  }

 private:
  std::string name_;
  unsigned int age_;
};

int main() {
  Test test("Leaf", 20);
  test.OutPut();
  return 0;
}
#endif

#if false
#include <iostream>

class Test {
 public:
  Test() : output_call_count_(0) {}

  void Output() const {
    ++output_call_count_;
    std::cout << "Output called " << output_call_count_ << " times."
              << std::endl;
  }

  unsigned int output_call_count() const { return output_call_count_; }

 private:
  mutable unsigned int output_call_count_;
};

int main() {
  Test test;
  test.Output();
  test.Output();
  test.Output();
  test.Output();
  test.Output();
  test.Output();
  return 0;
}
#endif

#if false
class Test {
 public:
  Test(unsigned int age) : age_(age) {}
  Test() = delete;
  Test(const Test& test) = delete;
  Test& operator=(const Test& test);
  ~Test() = default;

 private:
  unsigned int age_;
};
#endif

#if false
#include <iostream>
#include <string>

class Test {
 public:
  std::string name() const { return name_; }

  unsigned int age() const { return age_; }

 private:
  std::string name_;
  unsigned int age_;
};

class Test2 {
 public:
  void Output(const Test& test) {
    std::cout << test.name() << ", " << test.age() << std::endl;
  }
};

void Output(const Test& test) {
  std::cout << test.name() << ", " << test.age() << std::endl;
}
#endif

#if false
#include <iostream>
#include <vector>

class Test {
 public:
  Test() = default;

  Test(unsigned int count) : count_(count) {}

  // 前置 ++
  Test& operator++() {
    ++count_;
    return *this;
  }

  // 后置 ++
  Test operator++(int) {
    Test temp = *this;
    ++(*this);
    return temp;
  }

  // 前置 --
  Test& operator--() {
    --count_;
    return *this;
  }

  // 后置 --
  Test operator--(int) {
    Test temp = *this;
    ++(*this);
    return temp;
  }

  int operator[](size_t i) { return numbers_.at(i); }

  void operator()() { std::cout << "Hello, world!" << '\n'; }

  friend std::ostream& operator<<(std::ostream& os, const Test& test) {
    return os << test.count_;
  }

  friend std::istream& operator>>(std::istream& is, Test& test) {
    return is >> test.count_;
  }

  Test operator+(const Test& test) const {
    return Test(this->count_ + test.count_);
  }

  Test& operator=(const Test& test) {
    if (this != &test) {
      count_ = test.count_;
      numbers_ = test.numbers_;
    }
    return *this;
  }

  bool operator<(const Test& test) { return count_ < test.count_; }

  unsigned int count() const { return count_; }

  std::vector<int> numbers() const { return numbers_; }

 private:
  unsigned int count_ = 0;
  std::vector<int> numbers_{1, 2, 3, 4, 5, 6};
};

int main() {
  Test test;
  ++test;
  std::cout << test.count() << std::endl;
  --test;
  std::cout << test.count() << std::endl;
  std::cout << test[3] << std::endl;
  test();
  std::cin >> test;
  std::cout << test;
  return 0;
}
#endif

#if false
#include <iostream>

class Spear {
 public:
  Spear() { std::cout << "Spear()" << std::endl; }
  virtual ~Spear() { std::cout << "~Spear()" << std::endl; }
  virtual void OpenFire() const { std::cout << "Spear::OpenFire" << std::endl; }
};

class FireSpear : public Spear {
 public:
  FireSpear() { std::cout << "FireSpear()" << std::endl; }
  virtual ~FireSpear() { std::cout << "~FireSpear()" << std::endl; }
  virtual void OpenFire() const override {
    std::cout << "FireSpear::OpenFire" << std::endl;
  }
};

void OpenFire(const Spear* spear_ptr) {
  spear_ptr->OpenFire();
  delete spear_ptr;
}

int main() {
  Spear* spear_ptr = new FireSpear();
  OpenFire(spear_ptr);
  return 0;
}
#endif

#if false
#include <iostream>

class Test {
 public:
  static unsigned int count() { return count_; }

  static void set_count(unsigned int count) { count_ = count; }

 private:
  static unsigned int count_;
};

unsigned int Test::count_ = 100;

int main() {
  std::cout << Test::count() << '\n';
  Test::set_count(200);
  std::cout << Test::count() << '\n';
  return 0;
}
#endif

#if false
#include <iostream>
#include <string>

class Spear {
 public:
  Spear() { std::cout << "Spear()" << std::endl; }
  virtual ~Spear() { std::cout << "~Spear()" << std::endl; }
  virtual void OpenFire() const = 0;
};

class FireSpear : public Spear {
 public:
  FireSpear() { std::cout << "FireSpear()" << std::endl; }
  virtual ~FireSpear() { std::cout << "~FireSpear()" << std::endl; }
  virtual void OpenFire() const override {
    std::cout << "FireSpear::OpenFire" << std::endl;
  }
};

int main() {
  Spear* spear_ptr = new FireSpear();
  std::string type_name = typeid(*spear_ptr).name();
  if (type_name == "class FireSpear" || type_name == "9FireSpear") {
    FireSpear* fire_spear_ptr = dynamic_cast<FireSpear*>(spear_ptr);
    if (fire_spear_ptr) {
      std::cout << "Success!" << std::endl;
    }
  }
  return 0;
}
#endif

#if false
#include <iostream>

class Base {
 public:
  Base(int num) : num_(num) { std::cout << "Base()" << std::endl; }

  int num() const { return num_; }

 protected:
  int num_ = 100;
};

class Base1 : virtual public Base {
 public:
  Base1(int num, int base1_num) : Base(num), base1_num_(base1_num) {
    std::cout << "Base1()" << std::endl;
  }

 protected:
  int base1_num_;
};

class Base2 : virtual public Base {
 public:
  Base2(int num, int base2_num) : Base(num), base2_num_(base2_num) {
    std::cout << "Base2()" << std::endl;
  }

 protected:
  int base2_num_;
};

class Dervied : public Base1, public Base2 {
 public:
  Dervied(int num, int base1_num, int base2_num, int dervied_num)
      : Base(num),
        Base1(num, base1_num),
        Base2(num, base2_num),
        dervied_num_(dervied_num) {
    std::cout << "Dervied()" << std::endl;
  }

 private:
  int dervied_num_;
};

int main() {
  Dervied dervied(0, 1, 2, 3);
  std::cout << dervied.num() << std::endl;
  return 0;
}
#endif

#if false
#include <cstring>

class Test {
 public:
  // 复制构造函数
  Test(const Test& test) {
    if (test.str_) {
      str_ = new char[strlen(test.str_) + 1];
      strcpy(str_, test.str_);
    } else {
      str_ = nullptr;
    }
  }

  // 移动构造函数
  Test(Test&& test) {  // 必须为右值
    if (test.str_) {
      str_ = test.str_;
      // test 不是 const，否则无法修改
      test.str_ = nullptr;
    } else {
      str_ = nullptr;
    }
  }

  // 拷贝赋值运算符
  Test& operator=(const Test& test) {
    if (this != &test) {
      delete[] str_;
      str_ = nullptr;

      if (test.str_) {
        str_ = new char[strlen(test.str_) + 1];
        strcpy(str_, test.str_);
      } else {
        str_ = nullptr;
      }
    }

    return *this;
  }

  // 移动赋值运算符
  Test& operator=(Test&& test) {  // 必须为右值
    if (this != &test) {
      delete[] str_;
      str_ = nullptr;

      if (test.str_) {
        str_ = test.str_;
        test.str_ = nullptr;
      } else {
        str_ = nullptr;
      }
    }

    return *this;
  }

 private:
  char* str_ = nullptr;
};
#endif

#if false
int main() {
  std::shared_ptr<int> ptr1 = std::make_shared<int>(100);
  ptr1.reset(new int(99));  // 仅能使用 new 关键字
  std::cout << *ptr1 << '\n';
  return 0;
}
#endif

#if false
int main() {
  std::shared_ptr<int> ptr1 = std::make_shared<int>(100);
  auto p = ptr1.get();  // 得到裸指针
  // 执行下述语句即会报错
  // delete p;
  return 0;
}
#endif

#if false
#include <iostream>
#include <memory>
#include <utility>

int main() {
  std::shared_ptr<int> ptr1 = std::make_shared<int>(100);
  std::shared_ptr<int> ptr2 = std::make_shared<int>(9);
  std::swap(ptr1, ptr2);
  std::cout << *ptr1 << ' ' << *ptr2 << '\n';
  ptr1.swap(ptr2);
  std::cout << *ptr1 << ' ' << *ptr2 << '\n';
  return 0;
}
#endif

#if false
#include <iostream>
#include <memory>

void Test(std::shared_ptr<int> ptr) {
  std::cout << *ptr << std::endl;
}

int main() {
  std::shared_ptr<int> ptr1 = std::make_shared<int>(10);
  Test(ptr1);
  std::cout << sizeof(ptr1) << std::endl;
  return 0;
}
#endif

#if false
#include <memory>

class B;

class A {
 public:
  std::shared_ptr<B> ptrb_;
};

class B {
 public:
  std::weak_ptr<A> ptra_;  // 使用 weak_ptr
};

int main() {
  std::shared_ptr<A> ptra = std::make_shared<A>();
  std::shared_ptr<B> ptrb = std::make_shared<B>();
  ptra->ptrb_ = ptrb;
  ptrb->ptra_ = ptra;  // 此时不增加引用计数
  return 0;
}
#endif

#if false
#include "my_array.hpp"

#include <iostream>

int main() {
  MyArray<int> arr(100);
  std::cout << *arr.begin() << '\n';
  return 0;
}
#endif

#if false
#include <vector>

int main() {
  std::initializer_list<int> vec_init{1, 2, 3, 4, 5};
  std::vector<int> vec{1, 2, 3, 4, 5};
  return 0;
}
#endif

#if false
#include <iostream>
#include <vector>

namespace my_std {
template <typename IterType, typename FuncType>
void ForEach(IterType first, IterType last, FuncType func) {
  for (auto iter = first; iter != last; ++iter) {
    func(*iter);
  }
}
}  // namespace my_std

int main() {
  std::vector<int> vec{1, 2, 3, 4, 5};
  // 使用自动类型推断
  my_std::ForEach(vec.begin(), vec.end(), [](int& elem) -> void { ++elem; });
  for (int elem : vec) {
    std::cout << elem << ' ';
  }
  std::cout << '\n';
  return 0;
}
#endif

#if false
#include <iostream>

namespace my_std {
template <typename T>
class MyVec {
 public:
  template <typename U>
  void OutPut(const U& elem);
};

template <typename T>
template <typename U>
void MyVec<T>::OutPut(const U& elem) {
  std::cout << elem << std::endl;
}
}  // namespace my_std

int main() {
  my_std::MyVec<int> my_vec;
  my_vec.OutPut(20);
  return 0;
}
#endif

#if false
#include <functional>
#include <iostream>

namespace my_std {
template <typename IterType, typename FuncType = std::function<void(int)>>
void ForEach(IterType first, IterType last, FuncType func) {
  for (auto iter = first; iter != last; ++iter) {
    func(*iter);
  }
}

template <typename T>
class MyVec {
 public:
  template <typename U>
  void OutPut(const U& elem);
};

template <typename T>
template <typename U>
void MyVec<T>::OutPut(const U& elem) {
  std::cout << elem << std::endl;
}
}  // namespace my_std
#endif

#if false
#include <iostream>

namespace my_std {
template <typename T, typename Allocator = std::allocator<T>>
class MyVec {
 public:
  template <typename U>
  void OutPut(const U& elem);
};

template <typename T, typename Allocator>
template <typename U>
void MyVec<T, Allocator>::OutPut(const U& elem) {
  std::cout << elem << std::endl;
}

}  // namespace my_std
#endif

#if false
#include <iostream>

template <typename T>
void Test(const T& parm) {
  std::cout << "void Test(const T& parm)\n";
}

template <typename T>
void Test(T* parm) {
  std::cout << "void Test(T* parm)\n";
}

void Test(double parm) {
  std::cout << "void Test(double parm)\n";
}

int main() {
  Test(100);
  int i = 100;
  Test(&i);
  Test(2.2);
  return 0;
}
#endif

#if false
#include <iostream>

template <typename T, typename U>
class Test {
 public:
  Test() { std::cout << "Common Template\n"; }
};

// 偏特化
template <typename T, typename U>
class Test<T*, U*> {
 public:
  Test() { std::cout << "Pointer Semi-Special\n"; }
};

template <typename U>
class Test<int, U> {
 public:
  Test() { std::cout << "Int Semi-Special\n"; }
};

// 全特化
template <>
class Test<int, int> {
 public:
  Test() { std::cout << "Int, Int Complate Special\n"; }
};

int main() {
  Test<char, double> test;
  Test<int*, int*> test2;
  Test<int, double> test3;
  Test<int, int> test4;
  return 0;
}
#endif

#if false
#include <iostream>
#include <vector>

void BubbleSort(std::vector<int>& arr) {
  int n = arr.size();
  for (int i = 0; i < n - 1; ++i) {
    for (int j = 0; j < n - i - 1; ++j) {
      if (arr[j] > arr[j + 1]) {
        std::swap(arr[j], arr[j + 1]);
      }
    }
  }
}

void ShellSort(std::vector<int>& arr) {
  int n = arr.size();
  for (int gap = n / 2; gap > 0; gap /= 2) {
    for (int i = gap; i < n; ++i) {
      int temp = arr[i];
      int j;
      for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
        arr[j] = temp;
      }
      arr[j] = temp;
    }
  }
}

int main() {
  std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
  BubbleSort(arr);
  std::cout << "Sorted array: \n";
  for (int i = 0; i < arr.size(); ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec{1, 2, 3, 4};
  try {
    std::cout << vec.at(1) << std::endl;
  } catch (const std::out_of_range& exception) {
    std::cerr << exception.what() << std::endl;
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec{1, 2, 3, 4};
  std::cout << vec.size() << std::endl;
  vec.resize(10);
  std::cout << vec.size() << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>

int main() {
  []() -> void {
    std::cout << "Hello World!" << std::endl;
  }();
  return 0;
}
#endif

#if false
#include <iostream>

class Spear {
 public:
  Spear() { std::cout << "Spear()" << std::endl; }
  virtual ~Spear() { std::cout << "~Spear()" << std::endl; }
  virtual void OpenFire() const { std::cout << "Spear::OpenFire" << std::endl; }
};

class FireSpear : public Spear {
 public:
  FireSpear() { std::cout << "FireSpear()" << std::endl; }
  virtual ~FireSpear() { std::cout << "~FireSpear()" << std::endl; }
  virtual void OpenFire() const override {
    std::cout << "FireSpear::OpenFire" << std::endl;
  }
};

void OpenFire(const Spear* spear_ptr) {
  spear_ptr->OpenFire();
  delete spear_ptr;
}

int main() {
  Spear* spear_ptr = new FireSpear();
  std::string type_name = typeid(*spear_ptr).name();
  if (type_name == "class FireSpear" || type_name == "9FireSpear") {
    FireSpear* fire_spear_ptr = dynamic_cast<FireSpear*>(spear_ptr);
    if (fire_spear_ptr) {
      std::cout << "Success!" << std::endl;
    }
  }
  return 0;
}
#endif

#if false
#include <cstring>
#include <iostream>

class Test {
 public:
  Test() = default;

  Test(const Test& test) {
    if (test.str_) {
      if (test.str_) {
        str_ = new char[strlen(test.str_) + 1];
        strcpy(str_, test.str_);
      } else {
        str_ = nullptr;
      }
    }
  }

  Test(Test&& test) {
    if (test.str_) {
      str_ = test.str_;
      test.str_ = nullptr;
    } else {
      str_ = nullptr;
    }
  }

  Test& operator=(const Test& test) {
    if (this != &test) {
      delete[] str_;
      str_ = nullptr;
    }
  }

 private:
  char* str_ = nullptr;
};
#endif

#if false
#include <iostream>
#include <memory>

int main() {
  std::shared_ptr<int> ptr1 = std::make_shared<int>(100);
  std::shared_ptr<int> ptr2(ptr1);
  std::cout << ptr1.use_count() << '\n';
  std::cout << ptr1.unique() << '\n';
  return 0;
}
#endif

#if false
#include <iostream>
#include <memory>

int main() {
  std::shared_ptr<int> ptr1 = std::make_shared<int>(99);
  std::shared_ptr<int> ptr2 = std::make_shared<int>(100);
  std::cout << *ptr1 << ' ' << *ptr2 << '\n';
  ptr1.swap(ptr2);
  std::cout << *ptr1 << ' ' << *ptr2 << '\n';
  return 0;
}
#endif

#if false
#include <iostream>
#include <memory>

int main() {
  std::shared_ptr<int> ptr1(new int[100]());
  std::cout << ptr1.get()[10] << '\n';
  return 0;
}
#endif

#if false
#include <iostream>
#include <memory>

class B;

class A {
 public:
  std::shared_ptr<B> ptrb_;
};

class B {
 public:
  std::weak_ptr<A> ptra_;
};

int main() {
  std::shared_ptr<A> ptra = std::make_shared<A>();
  std::shared_ptr<B> ptrb = std::make_shared<B>();
  std::unique_ptr<int> ptr1 = std::make_unique<int>(100);
  std::cout << *ptr1 << '\n';
  ptra->ptrb_ = ptrb;
  ptrb->ptra_ = ptra;
  return 0;
}
#endif

#if false
#include <vector>

int main() {
  std::initializer_list<int> vec_init{1, 2, 3, 4, 5};
  std::vector<int> vec{1, 2, 3, 4, 5};
  return 0;
}
#endif

#if false
#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec1{1, 2, 3, 4, 5};
  std::vector<int> vec2(vec1.begin() + 1, vec1.end() - 2);
  std::vector<int> vec3(10, 3);
  vec1.push_back(10);
  vec1.insert(vec1.begin(), vec2.begin() + 2, vec2.end());
  vec1.erase(vec1.begin() + 2, vec1.end());
  std::cout << vec1.empty() << std::endl;
  std::cout << vec1.capacity() << std::endl;
  std::cout << vec1.max_size() << std::endl;
  vec1.resize(100, 1);
  std::cout << vec1.size() << std::endl;
  return 0;
}
#endif

#if false
#include <deque>
#include <iostream>

int main() {
  std::deque<int> deq{1, 2, 3, 4, 5};
  deq.push_front(0);
  std::cout << deq.at(1) << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <list>

int main() {
  std::list<int> list{1, 2, 3, 4, 5};
  list.push_back(1);
  return 0;
}
#endif

#if false
#include <forward_list>

int main() {
  std::forward_list<int> flist{1, 2, 3, 4, 5};
  auto iter = flist.begin();

  return 0;
}
#endif

#if false
#include <iostream>
#include <string>

int main() {
  std::string str("Hello, world!");
  std::cout << str.c_str() << std::endl;
  std::string str2 = "Hello, Alice!";
  str.copy(str2.data(), 5, 7);
  std::cout << str2 << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <set>

int main() {
  std::set<int> set{13, 2, 4, 4, 4, 20};
  set.insert(6);
  for (auto elem : set) {
    std::cout << elem << ' ';
  }
  std::cout << '\n';
  std::multiset<int> multiset{13, 2, 4, 4, 4, 20};
  multiset.insert(6);
  for (auto elem : multiset) {
    std::cout << elem << ' ';
  }
  std::cout << '\n';
  return 0;
}
#endif

#if false
#include <iostream>
#include <map>
#include <string>

int main() {
  std::map<int, std::string> int_string_map;
  int_string_map.insert(std::pair<int, std::string>(10, "Alice"));
  int_string_map.insert(std::pair<int, std::string>(20, "Bob"));
  int_string_map.insert(std::pair<int, std::string>(30, "Cindy"));
  int_string_map.insert(std::pair<int, std::string>(40, "David"));
  int_string_map.insert(std::pair<int, std::string>(50, "Eva"));
  for (auto iter = int_string_map.begin(); iter != int_string_map.end();
       ++iter) {
    std::cout << iter->first << ' ' << iter->second << '\n';
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <string>
#include <unordered_map>

int main() {
  std::unordered_map<int, std::string> int_string_map;
  int_string_map.insert(std::pair<int, std::string>(10, "Alice"));
  int_string_map.insert(std::pair<int, std::string>(20, "Bob"));
  int_string_map.insert(std::pair<int, std::string>(30, "Cindy"));
  for (auto elem : int_string_map) {
    std::cout << elem.first << ' ' << elem.second << '\n';
  }
  return 0;
}
#endif

#if false
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec{1, 2, 3, 4, 5};
  auto iter = std::adjacent_find(vec.cbegin(), vec.cend());
  if (iter == vec.cend()) {
    std::cout << "Container don't have adjacent elements." << std::endl;
  } else {
    std::cout << std::distance(vec.cbegin(), iter) << std::endl;
  }
  auto iter2 =
      std::adjacent_find(vec.cbegin(), vec.cend(),
                         [](int a, int b) -> bool { return a >= 3 && b >= 3; });
  if (iter2 == vec.cend()) {
    std::cout << "Container don't have adjacent elements." << std::endl;
  } else {
    std::cout << std::distance(vec.cbegin(), iter2) << std::endl;
  }
  return 0;
}
#endif

#if false
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec{1, 2, 3, 4, 5, 6};
  std::sort(vec.begin(), vec.end());
  std::cout << std::binary_search(vec.cbegin(), vec.cend(), 3) << std::endl;
  std::sort(vec.begin(), vec.end(), std::greater<int>());
  // 这里使用的 std::greater<int>() 来进行比较，必须与 std::sort() 时的比较器一致
  std::cout << std::binary_search(vec.cbegin(), vec.cend(), 4,
                                  std::greater<int>())
            << std::endl;
  return 0;
}
#endif

#if false
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec{1, 2, 3, 4, 5, 6};
  auto count = std::count(vec.cbegin(), vec.cend(), 3);
  std::cout << count << std::endl;
  return 0;
}
#endif

#if false
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec{1, 2, 3, 4, 5, 6};
  auto count = std::count_if(vec.cbegin(), vec.cend(),
                             [](int x) -> bool { return x % 2 == 0; });
  std::cout << count << std::endl;
  return 0;
}
#endif

#if false
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec{1, 2, 2, 3, 3, 3, 4, 5, 5, 5, 5, 6};
  int target = 3;
  auto range = std::equal_range(vec.begin(), vec.end(), target);
  std::cout << std::distance(vec.begin(), range.first) << ' '
            << std::distance(vec.begin(), range.second) << std::endl;
  return 0;
}
#endif

#if false
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec{1, 2, 3, 2, 3, 4, 5};
  std::vector<int> sub{2, 3};
  auto result = std::find_end(vec.begin(), vec.end(), sub.begin(), sub.end());
  std::cout << std::distance(vec.begin(), result) << '\n';
  return 0;
}
#endif

#if false
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::vector<int> sub{7, 8, 10};

  auto result =
      std::find_first_of(vec.begin(), vec.end(), sub.begin(), sub.end());

  if (result == vec.end()) {
    std::cout << "No element in vec is equal to any element in sub.\n";
  } else {
    std::cout
        << "The first element in vec that is equal to an element in sub is "
        << *result << '\n';
  }
}
#endif

#if false
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> v{1, 2, 3, 3, 4, 5};
  auto it = std::adjacent_find(v.begin(), v.end());
  if (it != v.end()) {
    std::cout << "Found adjacent duplicates: " << *it << std::endl;
  } else {
    std::cout << "No adjacent duplicates found." << std::endl;
  }
  return 0;
}
#endif

#if false
#include <algorithm>
#include <execution>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> v{1, 2, 3, 4, 5, 6};
  auto it = std::adjacent_find(std::execution::par, v.begin(), v.end(),
                               [](int a, int b) { return a + 1 == b; });
  if (it != v.end()) {
    std::cout << "Found adjacent elements satisfying the condition: " << *it
              << " and " << *(it + 1) << std::endl;
  } else {
    std::cout << "No adjacent elements satisfying the condition found."
              << std::endl;
  }
  return 0;
}
#endif

#if false
#include <algorithm>
#include <execution>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> v{3, 4, 6, 8, 10};
  bool result = std::all_of(std::execution::par_unseq, v.cbegin(), v.cend(),
                            [](int x) -> bool { return x % 2 != 0; });
  if (result) {
    std::cout << "All elements are even." << std::endl;
  } else {
    std::cout << "Not all elements are even." << std::endl;
  }
  return 0;
}
#endif

#if false
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> v{9, 8, 7, 6, 5, 4, 3, 2, 1};
  bool found = std::binary_search(v.begin(), v.end(), 5, std::greater<int>());
  if (found) {
    std::cout << "Value 5 is found in the range.\n";
  } else {
    std::cout << "Value 5 is not found in the range.\n";
  }
  return 0;
}
#endif

#if false
#include <algorithm>
#include <iostream>

int main() {
  int value = 10;
  int lower = 5;
  int upper = 20;
  int clamped_value = std::clamp(value, lower, upper);
  std::cout << "Clamped value: " << clamped_value << std::endl;
  value = 3;
  clamped_value = std::clamp(value, lower, upper);
  std::cout << "Clamped value: " << clamped_value << std::endl;
  value = 25;
  clamped_value = std::clamp(value, lower, upper);
  std::cout << "Clamped value: " << clamped_value << std::endl;
  return 0;
}
#endif

#if false
#include <algorithm>
#include <iostream>

int main() {
  int value = 10;
  int lower = 5;
  int upper = 20;

  auto greater_than = [](int a, int b) {
    return a > b;
  };

  int clamped_value = std::clamp(value, lower, upper, greater_than);
  std::cout << "Clamped value: " << clamped_value << std::endl;

  value = 3;
  clamped_value = std::clamp(value, lower, upper, greater_than);
  std::cout << "Clamped value: " << clamped_value << std::endl;

  value = 25;
  clamped_value = std::clamp(value, lower, upper, greater_than);
  std::cout << "Clamped value: " << clamped_value << std::endl;

  return 0;
}
#endif

#if false
#include <algorithm>
#include <execution>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> src{1, 2, 3, 4, 5};
  std::vector<int> dest(5);
  std::copy(std::execution::par, src.begin(), src.end(), dest.begin());
  for (const auto elem : dest) {
    std::cout << elem << ' ';
  }
  std::cout << '\n';
  return 0;
}
#endif

#if false
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector data{1, 2, 3, 4, 5};
  std::copy_backward(data.begin(), data.begin() + 4, data.begin() + 6);
  for (const auto elem : data) {
    std::cout << elem << ' ';
  }
  std::cout << '\n';
  return 0;
}
#endif

#if false
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> src{1, 2, 3, 4, 5, 6};
  std::vector<int> dest;
  std::copy_if(src.begin(), src.end(), std::back_inserter(dest),
               [](int x) -> bool { return x % 2 == 0; });
  for (const auto val : dest) {
    std::cout << val << ' ';
  }
  return 0;
}
#endif

#if false
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec{1, 2, 3, 4, 5, 6};
  std::vector<int> dest(3);
  return 0;
}
#endif

#if false
#include <algorithm>
#include <execution>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> src{1, 2, 3, 4, 5};
  std::vector<int> dest(3);

  std::copy_n(std::execution::par, src.begin(), 3, dest.begin());

  for (const auto elem : dest) {
    std::cout << elem << ' ';
  }
  std::cout << '\n';

  return 0;
}
#endif

#if false
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec{1, 2, 3, 4, 2, 2, 5};
  int count = std::count(vec.begin(), vec.end(), 2);
  std::cout << count << std::endl;
  return 0;
}
#endif

#if false
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec{1, 2, 3, 4, 2, 2, 5};
  int count =
      std::count_if(vec.begin(), vec.end(), [](int x) { return x > 3; });
  std::cout << count << std::endl;
  return 0;      
}
#endif

#if false
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec1{1, 2, 3, 4};
  std::vector<int> vec2{1, 2, 3, 4};
  bool result = std::equal(vec1.cbegin(), vec1.cend(), vec2.cbegin());
  std::cout << "The two vectors are equal: " << result << std::endl;
  return 0;
}
#endif

#if false
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

int main() {
  std::vector<int> vec{1, 2, 2, 3, 3, 3, 4, 5};
  auto result =
      std::equal_range(vec.begin(), vec.end(), 3, std::greater<int>());
  std::cout << std::distance(vec.begin(), result.first) << ' '
            << std::distance(vec.begin(), result.second) << std::endl;
  return 0;
}
#endif

#if false
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec(10);
  std::fill(vec.begin(), vec.end(), 5);
  for (const auto elem : vec) {
    std::cout << elem << ' ';
  }
  std::cout << '\n';
  return 0;
}
#endif

#if false
#include <algorithm>
#include <execution>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec(10);
  auto end = std::fill_n(std::execution::par, vec.begin() + 2, 5, 42);
  for (const auto elem : vec) {
    std::cout << elem << ' ';
  }
  std::cout << "\nEnd iterator: " << *end << std::endl;
  return 0;
}
#endif

#if false
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec{1, 2, 3, 4, 5, 6};
  auto it = std::find(vec.begin(), vec.end(), 3);
  if (it != vec.end()) {
    std::cout << "Found value: " << *it
              << " at position: " << std::distance(vec.begin(), it)
              << std::endl;
  } else {
    std::cout << "Value not found." << std::endl;
  }
  return 0;
}
#endif

#if false
#include <algorithm>
#include <execution>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec1{1, 2, 3, 4, 2, 3, 4};
  std::vector<int> vec2{2, 3, 4};
  auto it = std::find_end(std::execution::par, vec1.begin(), vec1.end(),
                          vec2.cbegin(), vec2.cend());
  if (it != vec1.end()) {
    std::cout << "Found subsequence at position: "
              << std::distance(vec1.begin(), it) << std::endl;
  } else {
    std::cout << "Subsequence not found." << std::endl;
  }
  return 0;
}
#endif

#if false
#include <algorithm>
#include <execution>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec1{1, 2, 3, 4, 5};
  std::vector<int> vec2{3, 4, 6};
  auto it = std::find_first_of(std::execution::par, vec1.begin(), vec1.end(),
                               vec2.begin(), vec2.end());
  if (it != vec1.end()) {
    std::cout << "Found element: " << *it
              << " at position: " << std::distance(vec1.begin(), it)
              << std::endl;
  } else {
    std::cout << "Element not found." << std::endl;
  }
  return 0;
}
#endif

#if false
#include <algorithm>
#include <execution>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec{1, 2, 3, 4, 5, 6};
  auto it = std::find_if(std::execution::par, vec.cbegin(), vec.cend(),
                         [](int x) { return x > 3; });
  if (it != vec.end()) {
    std::cout << "Found element: " << *it
              << " at position: " << std::distance(vec.cbegin(), it)
              << std::endl;
  } else {
    std::cout << "No element found." << std::endl;
  }
  return 0;
}
#endif

#if false
#include <algorithm>
#include <execution>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> data{1, 2, 3, 4, 5, 6};
  auto it = std::find_if_not(std::execution::par, data.begin(), data.end(),
                             [](int x) -> bool { return x % 2 == 0; });
  if (it != data.end()) {
    std::cout << "Found the first odd element: " << *it << std::endl;
  } else {
    std::cout << "No odd element found." << std::endl;
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec{1, 2, 3, 4, 5, 6};
  for (const auto val : vec) {
    std::cout << val << ' ';
  }
  std::cout << '\n';
  return 0;
}
#endif

#if false
#include <algorithm>
#include <execution>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec(10);
  std::generate(std::execution::par, vec.begin(), vec.end(),
                []() { return rand() % 100; });
  for (const auto val : vec) {
    std::cout << val << ' ';
  }
  std::cout << '\n';
  return 0;
}
#endif

#if false
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> v(10);
  std::generate_n(v.begin(), 5, []() -> int { return rand() % 100; });
  std::for_each_n(v.cbegin(), 5, [](int x) -> void { std::cout << x << ' '; });
  std::cout << '\n';
  return 0;
}
#endif

#if false
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> v1{5, 4, 3, 2, 1};
  std::vector<int> v2{4, 3, 2};
  bool result = std::includes(v1.cbegin(), v1.cend(), v2.cbegin(), v2.cend(),
                              std::greater<int>());
  std::cout << "Does v1 include v2? " << (result ? "Yes" : "No") << std::endl;
  return 0;
}
#endif

#if false
#include <algorithm>
#include <execution>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> v = {1, 3, 5, 7, 2, 4, 6, 8};
  auto middle = v.begin() + 4;
  std::inplace_merge(std::execution::par, v.begin(), middle, v.end());
  std::for_each(v.cbegin(), v.cend(),
                [](int x) -> void { std::cout << x << ' '; });
  std::cout << '\n';
  return 0;
}
#endif

