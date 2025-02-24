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

#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec{1, 2, 3, 4};
  std::cout << vec.size() << std::endl;
  vec.resize(10);
  std::cout << vec.size() << std::endl;
  return 0;
}
