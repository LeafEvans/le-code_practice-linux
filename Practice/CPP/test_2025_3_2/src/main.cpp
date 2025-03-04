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

#if false
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
#endif

#if false
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> v{1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5};
  std::vector<int> result;
  auto last = std::unique_copy(v.begin(), v.end(), std::back_inserter(result));
  for (const auto& i : result) {
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
  std::vector<int> vec{1, 2, 4, 4, 5, 6, 7};
  auto last = std::lower_bound(vec.begin(), vec.end(), 4);
  std::cout << "Lower bound of 4 is at index: "
            << std::distance(vec.begin(), last) << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <sstream>

int main() {
  std::istringstream iss("Hello, World!");
  std::string str;
  iss >> str;
  std::cout << str << std::endl;
  return 0;
}
#endif

#if false
#include <fstream>
#include <iostream>
#include <limits>

int main() {
  int i;
  while (std::cin >> i, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input. Please try again." << std::endl;
      continue;
    }
    std::cout << "You entered: " << i << std::endl;
  }
  std::cout << "End of input." << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <limits>
#include <stdexcept>

int main() {
  int i;
  while (std::cin >> i, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input. Please try again." << std::endl;
      continue;
    }
    std::cout << "You entered: " << i << std::endl;
  }
  std::cout << "End of input." << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <limits>
#include <stdexcept>

int main() {
  int i;
  while (std::cin >> i, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input. Please try again." << std::endl;
      continue;
    }
    std::cout << "You input: " << i << std::endl;
  }
  std::cout << "End of input." << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <limits>
#include <stdexcept>

int main() {
  int i;
  while (std::cin >> i, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input. Please try again." << std::endl;
      continue;
    }
    std::cout << "You input: " << i << std::endl;
  }
  std::cout << "End of input." << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <string>

int main() {
  std::string str;
  while (std::getline(std::cin, str), !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    std::cout << "You entered: " << str << std::endl;
  }
  std::cout << "End of input." << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <string>

int main() {
  char ch;
  while (std::cin >> ch, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    std::cout << "You entered: " << ch << std::endl;
  }
  std::cout << "End of input." << std::endl;
  return 0;
}
#endif

#if false
#include <fstream>

int main() {
  std::fstream fs;
  fs.open("test.txt", std::ios::out | std::ios::in);
  if (fs.is_open()) {
    fs.close();
  }
  return 0;
}
#endif

#if false
#include <fstream>
#include <iostream>
#include <limits>
#include <string>

int main() {
  std::string file_name;
  std::string file_content;

  while (std::cin >> file_name, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }

    std::ifstream ifs(file_name);
    if (ifs.is_open()) {
      while (std::getline(ifs, file_content)) {
        std::cout << file_content << std::endl;
      }
      if (ifs.bad()) {
        throw std::runtime_error("IO stream corrupted.");
      }
      ifs.close();
    } else {
      ifs.clear();
      ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "File not found. Please try again." << std::endl;
      continue;
    }
  }
  std::cout << "File processing completed." << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <limits>
#include <stdexcept>

int main() {
  int i;
  while (std::cin >> i, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input. Please try again." << std::endl;
      continue;
    }
    std::cout << "You input: " << i << std::endl;
  }
  std::cout << "End of input." << std::endl;
  return 0;
}
#endif

#if false
#include <fstream>
#include <iostream>
#include <limits>
#include <string>

int main() {
  std::string file_name;
  std::string file_content;
  while (std::cin >> file_name, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    std::ifstream ifs(file_name);
    if (ifs.is_open()) {
      while (std::getline(ifs, file_content)) {
        std::cout << file_content << std::endl;
      }
      if (ifs.bad()) {
        throw std::runtime_error("IO stream corrupted.");
      }
      ifs.close();
    } else {
      ifs.clear();
      ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "File not found. Please try again." << std::endl;
      continue;
    }
  }
  std::cout << "File processing completed." << std::endl;
  return 0;
}
#endif

#if false
#include <fstream>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>

int main() {
  std::string file_name{};
  std::string file_content{};

  while (std::cin >> file_name, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    std::ifstream ifs(file_name);
    if (ifs.is_open()) {
      while (std::getline(ifs, file_content)) {
        std::cout << file_content << std::endl;
      }
      if (ifs.bad()) {
        std::runtime_error("IO stream corrupted.");
      }
      ifs.close();
    } else {
      ifs.clear();
      ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "File not found. Please try again." << std::endl;
      continue;
    }
  }
  std::cout << "File processing completed." << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <sstream>

int main() {
  std::istringstream iss;
  std::ostringstream oss;
  std::stringstream ss;
  return 0;
}
#endif

#if false
#include <iostream>
#include <sstream>

int main() {
  std::string str("Hello, World!");
  std::istringstream iss(str);
  iss.str("Hello, C++!");
  std::cout << iss.str() << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <limits>
#include <sstream>

int main() {
  std::string str("12");
  std::stringstream ss(str);
  int i = 0;
  ss >> i;
  if (ss.bad()) {
    throw std::runtime_error("String stream corrupted.");
  }
  if (ss.fail()) {
    ss.clear();
    ss.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Invalid input. Please try again." << std::endl;
  } else {
    std::cout << "You entered: " << i << std::endl;
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <limits>
#include <sstream>
#include <stdexcept>

int main() {
  std::string str("321");
  std::stringstream ss(str);
  int i = 0;
  ss >> i;
  if (ss.bad()) {
    throw std::runtime_error("String stream corrupted.");
  }
  if (ss.fail()) {
    ss.clear();
    ss.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Invalid input. Please try again." << std::endl;
  }
  std::cout << "You entered: "  << i << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <sstream>

int main() {
  int i = 123;
  std::stringstream ss;
  ss << i << std::endl;
  if (ss.bad()) {
    throw std::runtime_error("String stream corrupted.");
  } else {
    std::cout << ss.str();
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <sstream>

int main() {
  int num{32};
  std::string src{"Hello, World! Hello, World!"};
  std::string dest{};
  std::stringstream ss(src);
  while (ss >> dest) {
    std::cout << dest << std::endl;
  }
  if (ss.bad()) {
    throw std::runtime_error("String stream corrupted.");
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <limits>
#include <sstream>
#include <stdexcept>

int main() {
  int i;
  while (std::cin >> i, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input. Please try again." << std::endl;
      continue;
    }
    std::cout << "You entered: " << i << std::endl;
  }
  std::cout << "End of input." << std::endl;
  return 0;
}
#endif

#if false
#include <fstream>
#include <iostream>
#include <limits>
#include <string>

int main() {
  std::string file_name{};
  std::string file_content{};
  while (std::cin >> file_name, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input. Please try again." << std::endl;
      continue;
    }
    std::ifstream ifs{file_name};
    if (ifs.is_open()) {
      while (std::getline(ifs, file_content)) {
        std::cout << file_content << std::endl;
      }
      if (ifs.bad()) {
        throw std::runtime_error("Ifstream corrupted.");
      }
      ifs.close();
    }
  }
  std::cout << "File processing completed." << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <sstream>

int main() {
  std::string str{"21"};
  std::istringstream iss{str};
  int i{};
  iss >> i;
  std::cout << i << std::endl;
  return 0;
}
#endif

#if false
#include <algorithm>
#include <iostream>
#include <list>

static bool Twice(int a, int b) {
  return a == 2 * b;
}

int main() {
  std::list<int> l{50, 40, 10, 20, 20};
  std::cout << "l = ( ";
  for (const auto& i : l) {
    std::cout << i << ' ';
  }
  std::cout << ')' << std::endl;
  auto it = std::adjacent_find(l.begin(), l.end(), Twice);
  if (it == l.end()) {
    std::cout << "There are not two adjacent elements that are equal."
              << std::endl;
  } else {
    std::cout << "The first two adjacent elements that are equal are: " << *it
              << ' ' << *(++it) << std::endl;
  }

  return 0;
}
#endif

#include <iostream>
#include <thread>

void Test(int value, const int& ref_value, const int* ptr_value) {}

int main() {
  int value = 10;
  std::thread t(Test, value, value, &value);
  t.detach();
  return 0;
}