#if false
#include <algorithm>
#include <iostream>
#include <vector>

void Test() {
  std::vector<int> v{1, 2, 2, 2, 3, 4, 5};
  auto it = std::search_n(v.begin(), v.end(), 3, 2);
  if (it != v.end()) {
    std::cout << "Found at index: " << std::distance(v.begin(), it)
              << std::endl;
  } else {
    std::cout << "Not found." << std::endl;
  }
}

int main() {
  Test();
  return 0;
}
#endif

#if false
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> v{1, 2, 2, 2, 3, 4, 5};
  auto it = std::search_n(v.begin(), v.end(), 3, 2);
  if (it != v.end()) {
    std::cout << "Found at index: " << std::distance(v.begin(), it)
              << std::endl;
  } else {
    std::cout << "Not found." << std::endl;
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
  std::vector<int> v{1, 2, 2, 2, 3, 4, 5};
  auto it = std::search_n(std::execution::par, v.begin(), v.end(), 3, 2);
  if (it != v.end()) {
    std::cout << "Found at index: " << std::distance(v.begin(), it)
              << std::endl;
  } else {
    std::cout << "Not found." << std::endl;
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
  std::vector<int> v1{1, 2, 3, 4, 5};
  std::vector<int> v2{3, 4, 5, 6, 7};
  std::vector<int> result;
  result.reserve(v1.size());
  auto it =
      std::set_difference(std::execution::par, v1.begin(), v1.end(), v2.begin(),
                          v2.end(), std::back_inserter(result));
  std::for_each(result.cbegin(), result.cend(),
                [](int i) { std::cout << i << " "; });
  std::cout << std::endl;
  return 0;
}
#endif

#if false
#include <algorithm>
#include <array>
#include <execution>
#include <iostream>

int main() {
  std::array<int, 5> a1{1, 2, 3, 4, 5};
  std::array<int, 5> a2{3, 4, 5, 6, 7};
  std::array<int, 5> result{};
  auto it = std::set_difference(std::execution::par, a1.begin(), a1.end(),
                                a2.begin(), a2.end(), result.begin());
  std::for_each(result.cbegin(), result.cend(),
                [](int i) { std::cout << i << " "; });
  std::cout << std::endl;
  return 0;
}
#endif

#if false
#include <algorithm>
#include <execution>
#include <iostream>
#include <random>
#include <vector>

int main() {
  std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::mt19937 gen(std::random_device{}());
  std::shuffle(v.begin(), v.end(), gen);
  for (const auto& i : v) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  std::sort(std::execution::par, v.begin(), v.end());
  for (const auto& i : v) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  return 0;
}
#endif

#if false
#include <algorithm>
#include <execution>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> v{4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
  std::make_heap(v.begin(), v.end());
  std::sort_heap(v.begin(), v.end());
  std::for_each(std::execution::par, v.cbegin(), v.cend(),
                [](int x) { std::cout << x << " "; });
  std::cout << std::endl;
  return 0;
}
#endif

#if false
#include <algorithm>
#include <execution>
#include <iostream>

int main() {
  std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  auto it = std::stable_partition(std::execution::par, v.begin(), v.end(),
                                  [](int x) { return x % 2 == 0; });
  std::for_each(v.cbegin(), v.cend(), [](int x) { std::cout << x << " "; });
  std::cout << std::endl;
  return 0;
}
#endif

#if false
#include <algorithm>
#include <execution>
#include <iostream>
#include <random>
#include <vector>

int main() {
  std::vector<int> vec(10);
  std::mt19937 gen(std::random_device{}());
  std::uniform_int_distribution<> dis(1, 100);

  std::generate(vec.begin(), vec.end(), [&] { return dis(gen); });

  for (const auto& num : vec) {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  std::sort(vec.begin(), vec.end());
  for (const auto& num : vec) {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  return 0;
}
#endif

#if false
#include <algorithm>
#include <execution>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> v1{1, 2, 3, 4, 5};
  std::vector<int> v2{10, 20, 30, 40, 50};
  auto it = std::swap_ranges(v1.begin(), v1.end(), v2.begin());
  for (const auto& i : v1) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  for (const auto& i : v2) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  return 0;
}
#endif

#if false
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec{1, 2, 3, 4, 5};
  std::vector<int> result(vec.size());
  std::transform(vec.cbegin(), vec.cend(), result.begin(),
                 [](int x) { return x * 2; });
  std::for_each(result.cbegin(), result.cend(),
                [](int x) { std::cout << x << " "; });
  std::cout << std::endl;
  return 0;                 
}
#endif

#include <algorithm>
#include <execution>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec{1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5};
  auto last = std::unique(vec.begin(), vec.end());
  vec.erase(last, vec.end());
  for (const auto& i : vec) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  return 0;
}