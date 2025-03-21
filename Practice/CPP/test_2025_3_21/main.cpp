#include <iostream>

#include <boost/type_index.hpp>

const int kNum = 19;

namespace {
int Add(int num1, int num2) {
  return num1 + num2;
}
}  // namespace

int main() {
  int num = kNum;
  for (int i = 0; i < kNum; ++i) {
    std::cout << i << ' ';
  }
  std::cout << Add(1, 2) << std::endl;
  return 0;
}
