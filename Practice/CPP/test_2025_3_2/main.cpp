#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::cout << "Hello, World!" << std::endl;
  std::vector<int> v = {1, 2, 3, 4, 5};
  std::for_each(v.cbegin(), v.cend(),
                [](int i) { std::cout << i << std::endl; });
  return 0;
}
