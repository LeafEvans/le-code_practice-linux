#include <iostream>

#include <boost/type_index.hpp>

int Add(int a, int b) {
  return a + b;
}

int main() {
  int i = 10;
  for (int i = 0; i < 10; ++i) {
    std::cout << i << ' ';
  }
  std::cout << Add(1, 2) << std::endl;
  return 0;
}
