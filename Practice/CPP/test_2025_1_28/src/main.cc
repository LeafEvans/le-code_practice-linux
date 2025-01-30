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
