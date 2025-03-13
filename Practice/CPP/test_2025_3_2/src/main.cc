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

#if false
#include <iostream>
#include <thread>

void Test(int value, const int& ref_value, const int* ptr_value) {
  for (unsigned j = 0; j < 1e6; ++j) {
    int k = *ptr_value;
  }
}

int main() {
  int value = 10;
  std::thread t{Test, value, std::ref(value), &value};
  t.detach();
  return 0;
}
#endif

#if false
#include <iostream>
#include <string>
#include <thread>

class Test {
 public:
  Test(int value) {
    std::cout << std::this_thread::get_id() << " Constructor called."
              << std::endl;
  }
};

void TestFunction(const Test& test) {
  std::cout << "Child thread: " << std::this_thread::get_id() << std::endl;
}

int main() {
  std::cout << "Main thread: " << std::this_thread::get_id() << std::endl;
  int value = 100;
  // 使用了隐式转换
  std::thread t{TestFunction, value};
  t.detach();
  return 0;
}
#endif

#if false
#include <iostream>
#include <thread>

int main() {
  std::cout << "Main thread: " << std::this_thread::get_id() << std::endl;
  return 0;
}
#endif

#if false
#include <atomic>
#include <iostream>
#include <thread>

std::atomic<unsigned> g_num{0};

void Test() {
  for (unsigned i = 0; i < 1e5; ++i) {
    ++g_num;
  }
}

int main() {
  std::thread t1{Test};
  std::thread t2{Test};
  t1.join();
  t2.join();
  std::cout << "g_num = " << g_num << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <mutex>
#include <thread>

unsigned g_num{0};
std::mutex g_mutex1{};
std::mutex g_mutex2{};

void Test() {
  for (unsigned i = 0; i < 1e5; ++i) {
    std::scoped_lock lock{g_mutex1, g_mutex2};
    ++g_num;
  }
}

int main() {
  std::thread t{Test};
  for (unsigned i = 0; i < 1e5; ++i) {
    std::scoped_lock lock{g_mutex1, g_mutex2};
    ++g_num;
  }
  t.join();
  std::cout << "g_num = " << g_num << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <string>
#include <thread>

void PrintStr(const std::string& str) {
  for (size_t i = 0; i < 1e6; ++i) {
    std::cout << i;
  }
  std::cout << str << std::endl;
}

int main() {
  std::thread t{PrintStr, "Hello, World!"};
  bool is_joinable = t.joinable();
  if (is_joinable) {
    t.join();
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <thread>

void Foo(int& x) {
  x += 1;
}

int main() {
  int num{1};
  std::thread t{Foo, std::ref(num)};
  t.join();
  std::cout << num << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <thread>

void ThreadFunction() {
  std::cout << "Child thread: " << std::this_thread::get_id() << std::endl;
}

int main() {
  std::thread t{ThreadFunction};
  std::cout << "Main thread: " << std::this_thread::get_id() << std::endl;
  t.join();
  return 0;
}
#endif

#if false
#include <cstddef>
#include <iostream>
#include <mutex>
#include <thread>

int g_count{0};
std::mutex g_mutex{};

void Test() {
  for (size_t i = 0; i < 136; ++i) {
    std::scoped_lock lock{g_mutex};
    ++g_count;
  }
}

int main() {
  std::thread t1{Test};
  std::thread t2{Test};
  t1.join();
  t2.join();
  std::cout << "g_count = " << g_count << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <mutex>

std::mutex g_mutex1{};
std::mutex g_mutex2{};

void Test() {
  std::scoped_lock lock{g_mutex1, g_mutex2};

}
#endif

#if false
#include <iostream>
#include <string>

double Divide(double divisior, double dividend) {
  if (dividend == 0) {
    throw std::runtime_error("Dividend cannot be zero.");
  }
  return divisior / dividend;
}

void InputNum(const std::string& str, double& num) {
  std::cout << str << std::endl;
  while (std::cin >> num, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input. Please try again." << std::endl;
      continue;
    }
    break;
  }
}

int main() {
  double divisior{.0};
  double dividend{.0};
  InputNum("Enter the divisior: ", divisior);
  InputNum("Enter the dividend: ", dividend);
  try {
    double result = Divide(divisior, dividend);
    std::cout << "Result of " << divisior << " / " << dividend << " = "
              << result << std::endl;
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
#endif

#if false
#include <fstream>
#include <iostream>

void OutputFileContent(const std::string& file_name) {
  std::ifstream ifs(file_name);
  std::string file_line_content;
  if (ifs.is_open()) {
    while (std::getline(ifs, file_line_content)) {
      std::cout << file_line_content << std::endl;
    }
    if (ifs.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    ifs.close();
  } else {
    if (ifs.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (ifs.fail()) {
      throw std::runtime_error("File not found.");
    }
  }
}

int main() {
  std::string file_name;
  while (std::cin >> file_name, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    try {
      OutputFileContent(file_name);
    } catch (const std::exception& e) {
      std::cerr << e.what() << std::endl;
    } catch (...) {
      std::cerr << "Unknown exception." << std::endl;
    }
  }
  return 0;
}
#endif

#if false
#include <fstream>
#include <iostream>

int main() {
  try {
    while (true) {
      int* ptr = new int[100000]{};
    }
  } catch (const std::bad_alloc& e) {
    std::cerr << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown exception." << std::endl;
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <stdexcept>
#include <vector>

int main() {
  std::vector<int> vec{1, 2, 3, 4, 5};
  try {
    vec.at(10);
  } catch (const std::out_of_range& e) {
    std::cerr << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown exception." << std::endl;
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <limits>

int main() {
  int i = 10;
  while (std::cin >> i, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cerr << "Invalid input. Please try again." << std::endl;
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
  std::string file_name;
  std::string file_line_content;
  while (std::cin >> file_name, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    std::ifstream ifs(file_name);
    if (ifs.is_open()) {
      while (std::getline(ifs, file_line_content)) {
        std::cout << file_line_content << std::endl;
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
#include <sstream>

int main() {
  std::string str{"12"};
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

#if false
#include <iostream>
#include <thread>

void Test(int value, const int& ref_value, const int* ptr_value) {
  for (unsigned j = 0; j < 1e6; ++j) {
    int k = *ptr_value;
  }
}

int main() {
  int value = 10;
  std::thread t{Test, value, std::ref(value), &value};
  t.detach();
  return 0;
}
#endif

#if false
#include <iostream>
#include <string>
#include <thread>

class Test {
 public:
  Test(int value) {
    std::cout << std::this_thread::get_id() << " Constructor called."
              << std::endl;
  }
};

void TestFunction(const Test& test) {
  std::cout << "Child thread: " << std::this_thread::get_id() << std::endl;
}

int main() {
  std::cout << "Main thread: " << std::this_thread::get_id() << std::endl;
  int value = 100;
  // 使用了隐式转换
  std::thread t{TestFunction, value};
  t.detach();
  return 0;
}
#endif

#if false
#include <iostream>
#include <thread>

int main() {
  std::cout << "Main thread: " << std::this_thread::get_id() << std::endl;
  return 0;
}
#endif

#if false
#include <atomic>
#include <iostream>
#include <thread>

std::atomic<unsigned> g_num{0};

void Test() {
  for (unsigned i = 0; i < 1e5; ++i) {
    ++g_num;
  }
}

int main() {
  std::thread t1{Test};
  std::thread t2{Test};
  t1.join();
  t2.join();
  std::cout << "g_num = " << g_num << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <mutex>
#include <thread>

unsigned g_num{0};
std::mutex g_mutex1{};
std::mutex g_mutex2{};

void Test() {
  for (unsigned i = 0; i < 1e5; ++i) {
    std::scoped_lock lock{g_mutex1, g_mutex2};
    ++g_num;
  }
}

int main() {
  std::thread t{Test};
  for (unsigned i = 0; i < 1e5; ++i) {
    std::scoped_lock lock{g_mutex1, g_mutex2};
    ++g_num;
  }
  t.join();
  std::cout << "g_num = " << g_num << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <string>
#include <thread>

void PrintStr(const std::string& str) {
  for (size_t i = 0; i < 1e6; ++i) {
    std::cout << i;
  }
  std::cout << str << std::endl;
}

int main() {
  std::thread t{PrintStr, "Hello, World!"};
  bool is_joinable = t.joinable();
  if (is_joinable) {
    t.join();
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <thread>

void Foo(int& x) {
  x += 1;
}

int main() {
  int num{1};
  std::thread t{Foo, std::ref(num)};
  t.join();
  std::cout << num << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <thread>

void ThreadFunction() {
  std::cout << "Child thread: " << std::this_thread::get_id() << std::endl;
}

int main() {
  std::thread t{ThreadFunction};
  std::cout << "Main thread: " << std::this_thread::get_id() << std::endl;
  t.join();
  return 0;
}
#endif

#if false
#include <cstddef>
#include <iostream>
#include <mutex>
#include <thread>

int g_count{0};
std::mutex g_mutex{};

void Test() {
  for (size_t i = 0; i < 136; ++i) {
    std::scoped_lock lock{g_mutex};
    ++g_count;
  }
}

int main() {
  std::thread t1{Test};
  std::thread t2{Test};
  t1.join();
  t2.join();
  std::cout << "g_count = " << g_count << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <mutex>

std::mutex g_mutex1{};
std::mutex g_mutex2{};

void Test() {
  std::scoped_lock lock{g_mutex1, g_mutex2};

}
#endif

#if false
#include <iostream>
#include <string>

double Divide(double divisior, double dividend) {
  if (dividend == 0) {
    throw std::runtime_error("Dividend cannot be zero.");
  }
  return divisior / dividend;
}

void InputNum(const std::string& str, double& num) {
  std::cout << str << std::endl;
  while (std::cin >> num, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input. Please try again." << std::endl;
      continue;
    }
    break;
  }
}

int main() {
  double divisior{.0};
  double dividend{.0};
  InputNum("Enter the divisior: ", divisior);
  InputNum("Enter the dividend: ", dividend);
  try {
    double result = Divide(divisior, dividend);
    std::cout << "Result of " << divisior << " / " << dividend << " = "
              << result << std::endl;
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
#endif

#if false
#include <fstream>
#include <iostream>

void OutputFileContent(const std::string& file_name) {
  std::ifstream ifs(file_name);
  std::string file_line_content;
  if (ifs.is_open()) {
    while (std::getline(ifs, file_line_content)) {
      std::cout << file_line_content << std::endl;
    }
    if (ifs.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    ifs.close();
  } else {
    if (ifs.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (ifs.fail()) {
      throw std::runtime_error("File not found.");
    }
  }
}

int main() {
  std::string file_name;
  while (std::cin >> file_name, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    try {
      OutputFileContent(file_name);
    } catch (const std::exception& e) {
      std::cerr << e.what() << std::endl;
    } catch (...) {
      std::cerr << "Unknown exception." << std::endl;
    }
  }
  return 0;
}
#endif

#if false
#include <fstream>
#include <iostream>

int main() {
  try {
    while (true) {
      int* ptr = new int[100000]{};
    }
  } catch (const std::bad_alloc& e) {
    std::cerr << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown exception." << std::endl;
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <stdexcept>
#include <vector>

int main() {
  std::vector<int> vec{1, 2, 3, 4, 5};
  try {
    vec.at(10);
  } catch (const std::out_of_range& e) {
    std::cerr << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown exception." << std::endl;
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <limits>

int main() {
  int i = 10;
  while (std::cin >> i, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cerr << "Invalid input. Please try again." << std::endl;
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
  std::string file_name;
  std::string file_line_content;
  while (std::cin >> file_name, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    std::ifstream ifs(file_name);
    if (ifs.is_open()) {
      while (std::getline(ifs, file_line_content)) {
        std::cout << file_line_content << std::endl;
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
#include <sstream>

int main() {
  std::string str{"12"};
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

#if false
#include <iostream>
#include <thread>

void Test(int value, const int& ref_value, const int* ptr_value) {
  for (unsigned j = 0; j < 1e6; ++j) {
    int k = *ptr_value;
  }
}

int main() {
  int value = 10;
  std::thread t{Test, value, std::ref(value), &value};
  t.detach();
  return 0;
}
#endif

#if false
#include <iostream>
#include <string>
#include <thread>

class Test {
 public:
  Test(int value) {
    std::cout << std::this_thread::get_id() << " Constructor called."
              << std::endl;
  }
};

void TestFunction(const Test& test) {
  std::cout << "Child thread: " << std::this_thread::get_id() << std::endl;
}

int main() {
  std::cout << "Main thread: " << std::this_thread::get_id() << std::endl;
  int value = 100;
  // 使用了隐式转换
  std::thread t{TestFunction, value};
  t.detach();
  return 0;
}
#endif

#if false
#include <iostream>
#include <thread>

int main() {
  std::cout << "Main thread: " << std::this_thread::get_id() << std::endl;
  return 0;
}
#endif

#if false
#include <atomic>
#include <iostream>
#include <thread>

std::atomic<unsigned> g_num{0};

void Test() {
  for (unsigned i = 0; i < 1e5; ++i) {
    ++g_num;
  }
}

int main() {
  std::thread t1{Test};
  std::thread t2{Test};
  t1.join();
  t2.join();
  std::cout << "g_num = " << g_num << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <mutex>
#include <thread>

unsigned g_num{0};
std::mutex g_mutex1{};
std::mutex g_mutex2{};

void Test() {
  for (unsigned i = 0; i < 1e5; ++i) {
    std::scoped_lock lock{g_mutex1, g_mutex2};
    ++g_num;
  }
}

int main() {
  std::thread t{Test};
  for (unsigned i = 0; i < 1e5; ++i) {
    std::scoped_lock lock{g_mutex1, g_mutex2};
    ++g_num;
  }
  t.join();
  std::cout << "g_num = " << g_num << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <string>
#include <thread>

void PrintStr(const std::string& str) {
  for (size_t i = 0; i < 1e6; ++i) {
    std::cout << i;
  }
  std::cout << str << std::endl;
}

int main() {
  std::thread t{PrintStr, "Hello, World!"};
  bool is_joinable = t.joinable();
  if (is_joinable) {
    t.join();
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <thread>

void Foo(int& x) {
  x += 1;
}

int main() {
  int num{1};
  std::thread t{Foo, std::ref(num)};
  t.join();
  std::cout << num << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <thread>

void ThreadFunction() {
  std::cout << "Child thread: " << std::this_thread::get_id() << std::endl;
}

int main() {
  std::thread t{ThreadFunction};
  std::cout << "Main thread: " << std::this_thread::get_id() << std::endl;
  t.join();
  return 0;
}
#endif

#if false
#include <cstddef>
#include <iostream>
#include <mutex>
#include <thread>

int g_count{0};
std::mutex g_mutex{};

void Test() {
  for (size_t i = 0; i < 136; ++i) {
    std::scoped_lock lock{g_mutex};
    ++g_count;
  }
}

int main() {
  std::thread t1{Test};
  std::thread t2{Test};
  t1.join();
  t2.join();
  std::cout << "g_count = " << g_count << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <mutex>

std::mutex g_mutex1{};
std::mutex g_mutex2{};

void Test() {
  std::scoped_lock lock{g_mutex1, g_mutex2};

}
#endif

#if false
#include <iostream>
#include <string>

double Divide(double divisior, double dividend) {
  if (dividend == 0) {
    throw std::runtime_error("Dividend cannot be zero.");
  }
  return divisior / dividend;
}

void InputNum(const std::string& str, double& num) {
  std::cout << str << std::endl;
  while (std::cin >> num, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input. Please try again." << std::endl;
      continue;
    }
    break;
  }
}

int main() {
  double divisior{.0};
  double dividend{.0};
  InputNum("Enter the divisior: ", divisior);
  InputNum("Enter the dividend: ", dividend);
  try {
    double result = Divide(divisior, dividend);
    std::cout << "Result of " << divisior << " / " << dividend << " = "
              << result << std::endl;
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
#endif

#if false
#include <fstream>
#include <iostream>

void OutputFileContent(const std::string& file_name) {
  std::ifstream ifs(file_name);
  std::string file_line_content;
  if (ifs.is_open()) {
    while (std::getline(ifs, file_line_content)) {
      std::cout << file_line_content << std::endl;
    }
    if (ifs.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    ifs.close();
  } else {
    if (ifs.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (ifs.fail()) {
      throw std::runtime_error("File not found.");
    }
  }
}

int main() {
  std::string file_name;
  while (std::cin >> file_name, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    try {
      OutputFileContent(file_name);
    } catch (const std::exception& e) {
      std::cerr << e.what() << std::endl;
    } catch (...) {
      std::cerr << "Unknown exception." << std::endl;
    }
  }
  return 0;
}
#endif

#if false
#include <fstream>
#include <iostream>

int main() {
  try {
    while (true) {
      int* ptr = new int[100000]{};
    }
  } catch (const std::bad_alloc& e) {
    std::cerr << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown exception." << std::endl;
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <stdexcept>
#include <vector>

int main() {
  std::vector<int> vec{1, 2, 3, 4, 5};
  try {
    vec.at(10);
  } catch (const std::out_of_range& e) {
    std::cerr << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown exception." << std::endl;
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <limits>

int main() {
  int i = 10;
  while (std::cin >> i, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cerr << "Invalid input. Please try again." << std::endl;
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
  std::string file_name;
  std::string file_line_content;
  while (std::cin >> file_name, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    std::ifstream ifs(file_name);
    if (ifs.is_open()) {
      while (std::getline(ifs, file_line_content)) {
        std::cout << file_line_content << std::endl;
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
#include <sstream>

int main() {
  std::string str{"12"};
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

#if false
#include <iostream>
#include <thread>

void Test(int value, const int& ref_value, const int* ptr_value) {
  for (unsigned j = 0; j < 1e6; ++j) {
    int k = *ptr_value;
  }
}

int main() {
  int value = 10;
  std::thread t{Test, value, std::ref(value), &value};
  t.detach();
  return 0;
}
#endif

#if false
#include <iostream>
#include <string>
#include <thread>

class Test {
 public:
  Test(int value) {
    std::cout << std::this_thread::get_id() << " Constructor called."
              << std::endl;
  }
};

void TestFunction(const Test& test) {
  std::cout << "Child thread: " << std::this_thread::get_id() << std::endl;
}

int main() {
  std::cout << "Main thread: " << std::this_thread::get_id() << std::endl;
  int value = 100;
  // 使用了隐式转换
  std::thread t{TestFunction, value};
  t.detach();
  return 0;
}
#endif

#if false
#include <iostream>
#include <thread>

int main() {
  std::cout << "Main thread: " << std::this_thread::get_id() << std::endl;
  return 0;
}
#endif

#if false
#include <atomic>
#include <iostream>
#include <thread>

std::atomic<unsigned> g_num{0};

void Test() {
  for (unsigned i = 0; i < 1e5; ++i) {
    ++g_num;
  }
}

int main() {
  std::thread t1{Test};
  std::thread t2{Test};
  t1.join();
  t2.join();
  std::cout << "g_num = " << g_num << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <mutex>
#include <thread>

unsigned g_num{0};
std::mutex g_mutex1{};
std::mutex g_mutex2{};

void Test() {
  for (unsigned i = 0; i < 1e5; ++i) {
    std::scoped_lock lock{g_mutex1, g_mutex2};
    ++g_num;
  }
}

int main() {
  std::thread t{Test};
  for (unsigned i = 0; i < 1e5; ++i) {
    std::scoped_lock lock{g_mutex1, g_mutex2};
    ++g_num;
  }
  t.join();
  std::cout << "g_num = " << g_num << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <string>
#include <thread>

void PrintStr(const std::string& str) {
  for (size_t i = 0; i < 1e6; ++i) {
    std::cout << i;
  }
  std::cout << str << std::endl;
}

int main() {
  std::thread t{PrintStr, "Hello, World!"};
  bool is_joinable = t.joinable();
  if (is_joinable) {
    t.join();
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <thread>

void Foo(int& x) {
  x += 1;
}

int main() {
  int num{1};
  std::thread t{Foo, std::ref(num)};
  t.join();
  std::cout << num << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <thread>

void ThreadFunction() {
  std::cout << "Child thread: " << std::this_thread::get_id() << std::endl;
}

int main() {
  std::thread t{ThreadFunction};
  std::cout << "Main thread: " << std::this_thread::get_id() << std::endl;
  t.join();
  return 0;
}
#endif

#if false
#include <cstddef>
#include <iostream>
#include <mutex>
#include <thread>

int g_count{0};
std::mutex g_mutex{};

void Test() {
  for (size_t i = 0; i < 136; ++i) {
    std::scoped_lock lock{g_mutex};
    ++g_count;
  }
}

int main() {
  std::thread t1{Test};
  std::thread t2{Test};
  t1.join();
  t2.join();
  std::cout << "g_count = " << g_count << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <mutex>

std::mutex g_mutex1{};
std::mutex g_mutex2{};

void Test() {
  std::scoped_lock lock{g_mutex1, g_mutex2};

}
#endif

#if false
#include <iostream>
#include <string>

double Divide(double divisior, double dividend) {
  if (dividend == 0) {
    throw std::runtime_error("Dividend cannot be zero.");
  }
  return divisior / dividend;
}

void InputNum(const std::string& str, double& num) {
  std::cout << str << std::endl;
  while (std::cin >> num, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input. Please try again." << std::endl;
      continue;
    }
    break;
  }
}

int main() {
  double divisior{.0};
  double dividend{.0};
  InputNum("Enter the divisior: ", divisior);
  InputNum("Enter the dividend: ", dividend);
  try {
    double result = Divide(divisior, dividend);
    std::cout << "Result of " << divisior << " / " << dividend << " = "
              << result << std::endl;
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
#endif

#if false
#include <fstream>
#include <iostream>

void OutputFileContent(const std::string& file_name) {
  std::ifstream ifs(file_name);
  std::string file_line_content;
  if (ifs.is_open()) {
    while (std::getline(ifs, file_line_content)) {
      std::cout << file_line_content << std::endl;
    }
    if (ifs.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    ifs.close();
  } else {
    if (ifs.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (ifs.fail()) {
      throw std::runtime_error("File not found.");
    }
  }
}

int main() {
  std::string file_name;
  while (std::cin >> file_name, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    try {
      OutputFileContent(file_name);
    } catch (const std::exception& e) {
      std::cerr << e.what() << std::endl;
    } catch (...) {
      std::cerr << "Unknown exception." << std::endl;
    }
  }
  return 0;
}
#endif

#if false
#include <fstream>
#include <iostream>

int main() {
  try {
    while (true) {
      int* ptr = new int[100000]{};
    }
  } catch (const std::bad_alloc& e) {
    std::cerr << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown exception." << std::endl;
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <stdexcept>
#include <vector>

int main() {
  std::vector<int> vec{1, 2, 3, 4, 5};
  try {
    vec.at(10);
  } catch (const std::out_of_range& e) {
    std::cerr << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown exception." << std::endl;
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <limits>

int main() {
  int i = 10;
  while (std::cin >> i, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cerr << "Invalid input. Please try again." << std::endl;
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
  std::string file_name;
  std::string file_line_content;
  while (std::cin >> file_name, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    std::ifstream ifs(file_name);
    if (ifs.is_open()) {
      while (std::getline(ifs, file_line_content)) {
        std::cout << file_line_content << std::endl;
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
#include <sstream>

int main() {
  std::string str{"12"};
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

#if false
#include <iostream>
#include <thread>

void Test(int value, const int& ref_value, const int* ptr_value) {
  for (unsigned j = 0; j < 1e6; ++j) {
    int k = *ptr_value;
  }
}

int main() {
  int value = 10;
  std::thread t{Test, value, std::ref(value), &value};
  t.detach();
  return 0;
}
#endif

#if false
#include <iostream>
#include <string>
#include <thread>

class Test {
 public:
  Test(int value) {
    std::cout << std::this_thread::get_id() << " Constructor called."
              << std::endl;
  }
};

void TestFunction(const Test& test) {
  std::cout << "Child thread: " << std::this_thread::get_id() << std::endl;
}

int main() {
  std::cout << "Main thread: " << std::this_thread::get_id() << std::endl;
  int value = 100;
  // 使用了隐式转换
  std::thread t{TestFunction, value};
  t.detach();
  return 0;
}
#endif

#if false
#include <iostream>
#include <thread>

int main() {
  std::cout << "Main thread: " << std::this_thread::get_id() << std::endl;
  return 0;
}
#endif

#if false
#include <atomic>
#include <iostream>
#include <thread>

std::atomic<unsigned> g_num{0};

void Test() {
  for (unsigned i = 0; i < 1e5; ++i) {
    ++g_num;
  }
}

int main() {
  std::thread t1{Test};
  std::thread t2{Test};
  t1.join();
  t2.join();
  std::cout << "g_num = " << g_num << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <mutex>
#include <thread>

unsigned g_num{0};
std::mutex g_mutex1{};
std::mutex g_mutex2{};

void Test() {
  for (unsigned i = 0; i < 1e5; ++i) {
    std::scoped_lock lock{g_mutex1, g_mutex2};
    ++g_num;
  }
}

int main() {
  std::thread t{Test};
  for (unsigned i = 0; i < 1e5; ++i) {
    std::scoped_lock lock{g_mutex1, g_mutex2};
    ++g_num;
  }
  t.join();
  std::cout << "g_num = " << g_num << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <string>
#include <thread>

void PrintStr(const std::string& str) {
  for (size_t i = 0; i < 1e6; ++i) {
    std::cout << i;
  }
  std::cout << str << std::endl;
}

int main() {
  std::thread t{PrintStr, "Hello, World!"};
  bool is_joinable = t.joinable();
  if (is_joinable) {
    t.join();
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <thread>

void Foo(int& x) {
  x += 1;
}

int main() {
  int num{1};
  std::thread t{Foo, std::ref(num)};
  t.join();
  std::cout << num << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <thread>

void ThreadFunction() {
  std::cout << "Child thread: " << std::this_thread::get_id() << std::endl;
}

int main() {
  std::thread t{ThreadFunction};
  std::cout << "Main thread: " << std::this_thread::get_id() << std::endl;
  t.join();
  return 0;
}
#endif

#if false
#include <cstddef>
#include <iostream>
#include <mutex>
#include <thread>

int g_count{0};
std::mutex g_mutex{};

void Test() {
  for (size_t i = 0; i < 136; ++i) {
    std::scoped_lock lock{g_mutex};
    ++g_count;
  }
}

int main() {
  std::thread t1{Test};
  std::thread t2{Test};
  t1.join();
  t2.join();
  std::cout << "g_count = " << g_count << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <mutex>

std::mutex g_mutex1{};
std::mutex g_mutex2{};

void Test() {
  std::scoped_lock lock{g_mutex1, g_mutex2};

}
#endif

#if false
#include <iostream>
#include <string>

double Divide(double divisior, double dividend) {
  if (dividend == 0) {
    throw std::runtime_error("Dividend cannot be zero.");
  }
  return divisior / dividend;
}

void InputNum(const std::string& str, double& num) {
  std::cout << str << std::endl;
  while (std::cin >> num, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input. Please try again." << std::endl;
      continue;
    }
    break;
  }
}

int main() {
  double divisior{.0};
  double dividend{.0};
  InputNum("Enter the divisior: ", divisior);
  InputNum("Enter the dividend: ", dividend);
  try {
    double result = Divide(divisior, dividend);
    std::cout << "Result of " << divisior << " / " << dividend << " = "
              << result << std::endl;
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
#endif

#if false
#include <fstream>
#include <iostream>

void OutputFileContent(const std::string& file_name) {
  std::ifstream ifs(file_name);
  std::string file_line_content;
  if (ifs.is_open()) {
    while (std::getline(ifs, file_line_content)) {
      std::cout << file_line_content << std::endl;
    }
    if (ifs.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    ifs.close();
  } else {
    if (ifs.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (ifs.fail()) {
      throw std::runtime_error("File not found.");
    }
  }
}

int main() {
  std::string file_name;
  while (std::cin >> file_name, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    try {
      OutputFileContent(file_name);
    } catch (const std::exception& e) {
      std::cerr << e.what() << std::endl;
    } catch (...) {
      std::cerr << "Unknown exception." << std::endl;
    }
  }
  return 0;
}
#endif

#if false
#include <fstream>
#include <iostream>

int main() {
  try {
    while (true) {
      int* ptr = new int[100000]{};
    }
  } catch (const std::bad_alloc& e) {
    std::cerr << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown exception." << std::endl;
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <stdexcept>
#include <vector>

int main() {
  std::vector<int> vec{1, 2, 3, 4, 5};
  try {
    vec.at(10);
  } catch (const std::out_of_range& e) {
    std::cerr << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown exception." << std::endl;
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <limits>

int main() {
  int i = 10;
  while (std::cin >> i, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cerr << "Invalid input. Please try again." << std::endl;
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
  std::string file_name;
  std::string file_line_content;
  while (std::cin >> file_name, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    std::ifstream ifs(file_name);
    if (ifs.is_open()) {
      while (std::getline(ifs, file_line_content)) {
        std::cout << file_line_content << std::endl;
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
#include <sstream>

int main() {
  std::string str{"12"};
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

#if false
#include <iostream>
#include <thread>

void Test(int value, const int& ref_value, const int* ptr_value) {
  for (unsigned j = 0; j < 1e6; ++j) {
    int k = *ptr_value;
  }
}

int main() {
  int value = 10;
  std::thread t{Test, value, std::ref(value), &value};
  t.detach();
  return 0;
}
#endif

#if false
#include <iostream>
#include <string>
#include <thread>

class Test {
 public:
  Test(int value) {
    std::cout << std::this_thread::get_id() << " Constructor called."
              << std::endl;
  }
};

void TestFunction(const Test& test) {
  std::cout << "Child thread: " << std::this_thread::get_id() << std::endl;
}

int main() {
  std::cout << "Main thread: " << std::this_thread::get_id() << std::endl;
  int value = 100;
  // 使用了隐式转换
  std::thread t{TestFunction, value};
  t.detach();
  return 0;
}
#endif

#if false
#include <iostream>
#include <thread>

int main() {
  std::cout << "Main thread: " << std::this_thread::get_id() << std::endl;
  return 0;
}
#endif

#if false
#include <atomic>
#include <iostream>
#include <thread>

std::atomic<unsigned> g_num{0};

void Test() {
  for (unsigned i = 0; i < 1e5; ++i) {
    ++g_num;
  }
}

int main() {
  std::thread t1{Test};
  std::thread t2{Test};
  t1.join();
  t2.join();
  std::cout << "g_num = " << g_num << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <mutex>
#include <thread>

unsigned g_num{0};
std::mutex g_mutex1{};
std::mutex g_mutex2{};

void Test() {
  for (unsigned i = 0; i < 1e5; ++i) {
    std::scoped_lock lock{g_mutex1, g_mutex2};
    ++g_num;
  }
}

int main() {
  std::thread t{Test};
  for (unsigned i = 0; i < 1e5; ++i) {
    std::scoped_lock lock{g_mutex1, g_mutex2};
    ++g_num;
  }
  t.join();
  std::cout << "g_num = " << g_num << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <string>
#include <thread>

void PrintStr(const std::string& str) {
  for (size_t i = 0; i < 1e6; ++i) {
    std::cout << i;
  }
  std::cout << str << std::endl;
}

int main() {
  std::thread t{PrintStr, "Hello, World!"};
  bool is_joinable = t.joinable();
  if (is_joinable) {
    t.join();
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <thread>

void Foo(int& x) {
  x += 1;
}

int main() {
  int num{1};
  std::thread t{Foo, std::ref(num)};
  t.join();
  std::cout << num << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <thread>

void ThreadFunction() {
  std::cout << "Child thread: " << std::this_thread::get_id() << std::endl;
}

int main() {
  std::thread t{ThreadFunction};
  std::cout << "Main thread: " << std::this_thread::get_id() << std::endl;
  t.join();
  return 0;
}
#endif

#if false
#include <cstddef>
#include <iostream>
#include <mutex>
#include <thread>

int g_count{0};
std::mutex g_mutex{};

void Test() {
  for (size_t i = 0; i < 136; ++i) {
    std::scoped_lock lock{g_mutex};
    ++g_count;
  }
}

int main() {
  std::thread t1{Test};
  std::thread t2{Test};
  t1.join();
  t2.join();
  std::cout << "g_count = " << g_count << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <mutex>

std::mutex g_mutex1{};
std::mutex g_mutex2{};

void Test() {
  std::scoped_lock lock{g_mutex1, g_mutex2};

}
#endif

#if false
#include <iostream>
#include <string>

double Divide(double divisior, double dividend) {
  if (dividend == 0) {
    throw std::runtime_error("Dividend cannot be zero.");
  }
  return divisior / dividend;
}

void InputNum(const std::string& str, double& num) {
  std::cout << str << std::endl;
  while (std::cin >> num, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input. Please try again." << std::endl;
      continue;
    }
    break;
  }
}

int main() {
  double divisior{.0};
  double dividend{.0};
  InputNum("Enter the divisior: ", divisior);
  InputNum("Enter the dividend: ", dividend);
  try {
    double result = Divide(divisior, dividend);
    std::cout << "Result of " << divisior << " / " << dividend << " = "
              << result << std::endl;
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
#endif

#if false
#include <fstream>
#include <iostream>

void OutputFileContent(const std::string& file_name) {
  std::ifstream ifs(file_name);
  std::string file_line_content;
  if (ifs.is_open()) {
    while (std::getline(ifs, file_line_content)) {
      std::cout << file_line_content << std::endl;
    }
    if (ifs.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    ifs.close();
  } else {
    if (ifs.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (ifs.fail()) {
      throw std::runtime_error("File not found.");
    }
  }
}

int main() {
  std::string file_name;
  while (std::cin >> file_name, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    try {
      OutputFileContent(file_name);
    } catch (const std::exception& e) {
      std::cerr << e.what() << std::endl;
    } catch (...) {
      std::cerr << "Unknown exception." << std::endl;
    }
  }
  return 0;
}
#endif

#if false
#include <fstream>
#include <iostream>

int main() {
  try {
    while (true) {
      int* ptr = new int[100000]{};
    }
  } catch (const std::bad_alloc& e) {
    std::cerr << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown exception." << std::endl;
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <stdexcept>
#include <vector>

int main() {
  std::vector<int> vec{1, 2, 3, 4, 5};
  try {
    vec.at(10);
  } catch (const std::out_of_range& e) {
    std::cerr << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown exception." << std::endl;
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <limits>

int main() {
  int i = 10;
  while (std::cin >> i, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cerr << "Invalid input. Please try again." << std::endl;
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
  std::string file_name;
  std::string file_line_content;
  while (std::cin >> file_name, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    std::ifstream ifs(file_name);
    if (ifs.is_open()) {
      while (std::getline(ifs, file_line_content)) {
        std::cout << file_line_content << std::endl;
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
#include <sstream>

int main() {
  std::string str{"12"};
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

#if false
#include <iostream>
#include <thread>

void Test(int value, const int& ref_value, const int* ptr_value) {
  for (unsigned j = 0; j < 1e6; ++j) {
    int k = *ptr_value;
  }
}

int main() {
  int value = 10;
  std::thread t{Test, value, std::ref(value), &value};
  t.detach();
  return 0;
}
#endif

#if false
#include <iostream>
#include <string>
#include <thread>

class Test {
 public:
  Test(int value) {
    std::cout << std::this_thread::get_id() << " Constructor called."
              << std::endl;
  }
};

void TestFunction(const Test& test) {
  std::cout << "Child thread: " << std::this_thread::get_id() << std::endl;
}

int main() {
  std::cout << "Main thread: " << std::this_thread::get_id() << std::endl;
  int value = 100;
  // 使用了隐式转换
  std::thread t{TestFunction, value};
  t.detach();
  return 0;
}
#endif

#if false
#include <iostream>
#include <thread>

int main() {
  std::cout << "Main thread: " << std::this_thread::get_id() << std::endl;
  return 0;
}
#endif

#if false
#include <atomic>
#include <iostream>
#include <thread>

std::atomic<unsigned> g_num{0};

void Test() {
  for (unsigned i = 0; i < 1e5; ++i) {
    ++g_num;
  }
}

int main() {
  std::thread t1{Test};
  std::thread t2{Test};
  t1.join();
  t2.join();
  std::cout << "g_num = " << g_num << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <mutex>
#include <thread>

unsigned g_num{0};
std::mutex g_mutex1{};
std::mutex g_mutex2{};

void Test() {
  for (unsigned i = 0; i < 1e5; ++i) {
    std::scoped_lock lock{g_mutex1, g_mutex2};
    ++g_num;
  }
}

int main() {
  std::thread t{Test};
  for (unsigned i = 0; i < 1e5; ++i) {
    std::scoped_lock lock{g_mutex1, g_mutex2};
    ++g_num;
  }
  t.join();
  std::cout << "g_num = " << g_num << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <string>
#include <thread>

void PrintStr(const std::string& str) {
  for (size_t i = 0; i < 1e6; ++i) {
    std::cout << i;
  }
  std::cout << str << std::endl;
}

int main() {
  std::thread t{PrintStr, "Hello, World!"};
  bool is_joinable = t.joinable();
  if (is_joinable) {
    t.join();
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <thread>

void Foo(int& x) {
  x += 1;
}

int main() {
  int num{1};
  std::thread t{Foo, std::ref(num)};
  t.join();
  std::cout << num << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <thread>

void ThreadFunction() {
  std::cout << "Child thread: " << std::this_thread::get_id() << std::endl;
}

int main() {
  std::thread t{ThreadFunction};
  std::cout << "Main thread: " << std::this_thread::get_id() << std::endl;
  t.join();
  return 0;
}
#endif

#if false
#include <cstddef>
#include <iostream>
#include <mutex>
#include <thread>

int g_count{0};
std::mutex g_mutex{};

void Test() {
  for (size_t i = 0; i < 136; ++i) {
    std::scoped_lock lock{g_mutex};
    ++g_count;
  }
}

int main() {
  std::thread t1{Test};
  std::thread t2{Test};
  t1.join();
  t2.join();
  std::cout << "g_count = " << g_count << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <mutex>

std::mutex g_mutex1{};
std::mutex g_mutex2{};

void Test() {
  std::scoped_lock lock{g_mutex1, g_mutex2};

}
#endif

#if false
#include <iostream>
#include <string>

double Divide(double divisior, double dividend) {
  if (dividend == 0) {
    throw std::runtime_error("Dividend cannot be zero.");
  }
  return divisior / dividend;
}

void InputNum(const std::string& str, double& num) {
  std::cout << str << std::endl;
  while (std::cin >> num, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input. Please try again." << std::endl;
      continue;
    }
    break;
  }
}

int main() {
  double divisior{.0};
  double dividend{.0};
  InputNum("Enter the divisior: ", divisior);
  InputNum("Enter the dividend: ", dividend);
  try {
    double result = Divide(divisior, dividend);
    std::cout << "Result of " << divisior << " / " << dividend << " = "
              << result << std::endl;
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
#endif

#if false
#include <fstream>
#include <iostream>

void OutputFileContent(const std::string& file_name) {
  std::ifstream ifs(file_name);
  std::string file_line_content;
  if (ifs.is_open()) {
    while (std::getline(ifs, file_line_content)) {
      std::cout << file_line_content << std::endl;
    }
    if (ifs.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    ifs.close();
  } else {
    if (ifs.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (ifs.fail()) {
      throw std::runtime_error("File not found.");
    }
  }
}

int main() {
  std::string file_name;
  while (std::cin >> file_name, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    try {
      OutputFileContent(file_name);
    } catch (const std::exception& e) {
      std::cerr << e.what() << std::endl;
    } catch (...) {
      std::cerr << "Unknown exception." << std::endl;
    }
  }
  return 0;
}
#endif

#if false
#include <fstream>
#include <iostream>

int main() {
  try {
    while (true) {
      int* ptr = new int[100000]{};
    }
  } catch (const std::bad_alloc& e) {
    std::cerr << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown exception." << std::endl;
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <stdexcept>
#include <vector>

int main() {
  std::vector<int> vec{1, 2, 3, 4, 5};
  try {
    vec.at(10);
  } catch (const std::out_of_range& e) {
    std::cerr << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown exception." << std::endl;
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <limits>

int main() {
  int i = 10;
  while (std::cin >> i, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cerr << "Invalid input. Please try again." << std::endl;
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
  std::string file_name;
  std::string file_line_content;
  while (std::cin >> file_name, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    std::ifstream ifs(file_name);
    if (ifs.is_open()) {
      while (std::getline(ifs, file_line_content)) {
        std::cout << file_line_content << std::endl;
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
#include <sstream>

int main() {
  std::string str{"12"};
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

#if false
#include <iostream>
#include <thread>

void Test(int value, const int& ref_value, const int* ptr_value) {
  for (unsigned j = 0; j < 1e6; ++j) {
    int k = *ptr_value;
  }
}

int main() {
  int value = 10;
  std::thread t{Test, value, std::ref(value), &value};
  t.detach();
  return 0;
}
#endif

#if false
#include <iostream>
#include <string>
#include <thread>

class Test {
 public:
  Test(int value) {
    std::cout << std::this_thread::get_id() << " Constructor called."
              << std::endl;
  }
};

void TestFunction(const Test& test) {
  std::cout << "Child thread: " << std::this_thread::get_id() << std::endl;
}

int main() {
  std::cout << "Main thread: " << std::this_thread::get_id() << std::endl;
  int value = 100;
  // 使用了隐式转换
  std::thread t{TestFunction, value};
  t.detach();
  return 0;
}
#endif

#if false
#include <iostream>
#include <thread>

int main() {
  std::cout << "Main thread: " << std::this_thread::get_id() << std::endl;
  return 0;
}
#endif

#if false
#include <atomic>
#include <iostream>
#include <thread>

std::atomic<unsigned> g_num{0};

void Test() {
  for (unsigned i = 0; i < 1e5; ++i) {
    ++g_num;
  }
}

int main() {
  std::thread t1{Test};
  std::thread t2{Test};
  t1.join();
  t2.join();
  std::cout << "g_num = " << g_num << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <mutex>
#include <thread>

unsigned g_num{0};
std::mutex g_mutex1{};
std::mutex g_mutex2{};

void Test() {
  for (unsigned i = 0; i < 1e5; ++i) {
    std::scoped_lock lock{g_mutex1, g_mutex2};
    ++g_num;
  }
}

int main() {
  std::thread t{Test};
  for (unsigned i = 0; i < 1e5; ++i) {
    std::scoped_lock lock{g_mutex1, g_mutex2};
    ++g_num;
  }
  t.join();
  std::cout << "g_num = " << g_num << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <string>
#include <thread>

void PrintStr(const std::string& str) {
  for (size_t i = 0; i < 1e6; ++i) {
    std::cout << i;
  }
  std::cout << str << std::endl;
}

int main() {
  std::thread t{PrintStr, "Hello, World!"};
  bool is_joinable = t.joinable();
  if (is_joinable) {
    t.join();
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <thread>

void Foo(int& x) {
  x += 1;
}

int main() {
  int num{1};
  std::thread t{Foo, std::ref(num)};
  t.join();
  std::cout << num << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <thread>

void ThreadFunction() {
  std::cout << "Child thread: " << std::this_thread::get_id() << std::endl;
}

int main() {
  std::thread t{ThreadFunction};
  std::cout << "Main thread: " << std::this_thread::get_id() << std::endl;
  t.join();
  return 0;
}
#endif

#if false
#include <cstddef>
#include <iostream>
#include <mutex>
#include <thread>

int g_count{0};
std::mutex g_mutex{};

void Test() {
  for (size_t i = 0; i < 136; ++i) {
    std::scoped_lock lock{g_mutex};
    ++g_count;
  }
}

int main() {
  std::thread t1{Test};
  std::thread t2{Test};
  t1.join();
  t2.join();
  std::cout << "g_count = " << g_count << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <mutex>

std::mutex g_mutex1{};
std::mutex g_mutex2{};

void Test() {
  std::scoped_lock lock{g_mutex1, g_mutex2};

}
#endif

#if false
#include <iostream>
#include <string>

double Divide(double divisior, double dividend) {
  if (dividend == 0) {
    throw std::runtime_error("Dividend cannot be zero.");
  }
  return divisior / dividend;
}

void InputNum(const std::string& str, double& num) {
  std::cout << str << std::endl;
  while (std::cin >> num, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input. Please try again." << std::endl;
      continue;
    }
    break;
  }
}

int main() {
  double divisior{.0};
  double dividend{.0};
  InputNum("Enter the divisior: ", divisior);
  InputNum("Enter the dividend: ", dividend);
  try {
    double result = Divide(divisior, dividend);
    std::cout << "Result of " << divisior << " / " << dividend << " = "
              << result << std::endl;
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
#endif

#if false
#include <fstream>
#include <iostream>

void OutputFileContent(const std::string& file_name) {
  std::ifstream ifs(file_name);
  std::string file_line_content;
  if (ifs.is_open()) {
    while (std::getline(ifs, file_line_content)) {
      std::cout << file_line_content << std::endl;
    }
    if (ifs.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    ifs.close();
  } else {
    if (ifs.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (ifs.fail()) {
      throw std::runtime_error("File not found.");
    }
  }
}

int main() {
  std::string file_name;
  while (std::cin >> file_name, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    try {
      OutputFileContent(file_name);
    } catch (const std::exception& e) {
      std::cerr << e.what() << std::endl;
    } catch (...) {
      std::cerr << "Unknown exception." << std::endl;
    }
  }
  return 0;
}
#endif

#if false
#include <fstream>
#include <iostream>

int main() {
  try {
    while (true) {
      int* ptr = new int[100000]{};
    }
  } catch (const std::bad_alloc& e) {
    std::cerr << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown exception." << std::endl;
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <stdexcept>
#include <vector>

int main() {
  std::vector<int> vec{1, 2, 3, 4, 5};
  try {
    vec.at(10);
  } catch (const std::out_of_range& e) {
    std::cerr << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown exception." << std::endl;
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <limits>

int main() {
  int i = 10;
  while (std::cin >> i, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cerr << "Invalid input. Please try again." << std::endl;
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
  std::string file_name;
  std::string file_line_content;
  while (std::cin >> file_name, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    std::ifstream ifs(file_name);
    if (ifs.is_open()) {
      while (std::getline(ifs, file_line_content)) {
        std::cout << file_line_content << std::endl;
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
#include <sstream>

int main() {
  std::string str{"12"};
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

#if false
#include <iostream>
#include <thread>

void Test(int value, const int& ref_value, const int* ptr_value) {
  for (unsigned j = 0; j < 1e6; ++j) {
    int k = *ptr_value;
  }
}

int main() {
  int value = 10;
  std::thread t{Test, value, std::ref(value), &value};
  t.detach();
  return 0;
}
#endif

#if false
#include <iostream>
#include <string>
#include <thread>

class Test {
 public:
  Test(int value) {
    std::cout << std::this_thread::get_id() << " Constructor called."
              << std::endl;
  }
};

void TestFunction(const Test& test) {
  std::cout << "Child thread: " << std::this_thread::get_id() << std::endl;
}

int main() {
  std::cout << "Main thread: " << std::this_thread::get_id() << std::endl;
  int value = 100;
  // 使用了隐式转换
  std::thread t{TestFunction, value};
  t.detach();
  return 0;
}
#endif

#if false
#include <iostream>
#include <thread>

int main() {
  std::cout << "Main thread: " << std::this_thread::get_id() << std::endl;
  return 0;
}
#endif

#if false
#include <atomic>
#include <iostream>
#include <thread>

std::atomic<unsigned> g_num{0};

void Test() {
  for (unsigned i = 0; i < 1e5; ++i) {
    ++g_num;
  }
}

int main() {
  std::thread t1{Test};
  std::thread t2{Test};
  t1.join();
  t2.join();
  std::cout << "g_num = " << g_num << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <mutex>
#include <thread>

unsigned g_num{0};
std::mutex g_mutex1{};
std::mutex g_mutex2{};

void Test() {
  for (unsigned i = 0; i < 1e5; ++i) {
    std::scoped_lock lock{g_mutex1, g_mutex2};
    ++g_num;
  }
}

int main() {
  std::thread t{Test};
  for (unsigned i = 0; i < 1e5; ++i) {
    std::scoped_lock lock{g_mutex1, g_mutex2};
    ++g_num;
  }
  t.join();
  std::cout << "g_num = " << g_num << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <string>
#include <thread>

void PrintStr(const std::string& str) {
  for (size_t i = 0; i < 1e6; ++i) {
    std::cout << i;
  }
  std::cout << str << std::endl;
}

int main() {
  std::thread t{PrintStr, "Hello, World!"};
  bool is_joinable = t.joinable();
  if (is_joinable) {
    t.join();
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <thread>

void Foo(int& x) {
  x += 1;
}

int main() {
  int num{1};
  std::thread t{Foo, std::ref(num)};
  t.join();
  std::cout << num << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <thread>

void ThreadFunction() {
  std::cout << "Child thread: " << std::this_thread::get_id() << std::endl;
}

int main() {
  std::thread t{ThreadFunction};
  std::cout << "Main thread: " << std::this_thread::get_id() << std::endl;
  t.join();
  return 0;
}
#endif

#if false
#include <cstddef>
#include <iostream>
#include <mutex>
#include <thread>

int g_count{0};
std::mutex g_mutex{};

void Test() {
  for (size_t i = 0; i < 136; ++i) {
    std::scoped_lock lock{g_mutex};
    ++g_count;
  }
}

int main() {
  std::thread t1{Test};
  std::thread t2{Test};
  t1.join();
  t2.join();
  std::cout << "g_count = " << g_count << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <mutex>

std::mutex g_mutex1{};
std::mutex g_mutex2{};

void Test() {
  std::scoped_lock lock{g_mutex1, g_mutex2};

}
#endif

#if false
#include <iostream>
#include <string>

double Divide(double divisior, double dividend) {
  if (dividend == 0) {
    throw std::runtime_error("Dividend cannot be zero.");
  }
  return divisior / dividend;
}

void InputNum(const std::string& str, double& num) {
  std::cout << str << std::endl;
  while (std::cin >> num, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input. Please try again." << std::endl;
      continue;
    }
    break;
  }
}

int main() {
  double divisior{.0};
  double dividend{.0};
  InputNum("Enter the divisior: ", divisior);
  InputNum("Enter the dividend: ", dividend);
  try {
    double result = Divide(divisior, dividend);
    std::cout << "Result of " << divisior << " / " << dividend << " = "
              << result << std::endl;
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
#endif

#if false
#include <fstream>
#include <iostream>

void OutputFileContent(const std::string& file_name) {
  std::ifstream ifs(file_name);
  std::string file_line_content;
  if (ifs.is_open()) {
    while (std::getline(ifs, file_line_content)) {
      std::cout << file_line_content << std::endl;
    }
    if (ifs.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    ifs.close();
  } else {
    if (ifs.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (ifs.fail()) {
      throw std::runtime_error("File not found.");
    }
  }
}

int main() {
  std::string file_name;
  while (std::cin >> file_name, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    try {
      OutputFileContent(file_name);
    } catch (const std::exception& e) {
      std::cerr << e.what() << std::endl;
    } catch (...) {
      std::cerr << "Unknown exception." << std::endl;
    }
  }
  return 0;
}
#endif

#if false
#include <fstream>
#include <iostream>

int main() {
  try {
    while (true) {
      int* ptr = new int[100000]{};
    }
  } catch (const std::bad_alloc& e) {
    std::cerr << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown exception." << std::endl;
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <stdexcept>
#include <vector>

int main() {
  std::vector<int> vec{1, 2, 3, 4, 5};
  try {
    vec.at(10);
  } catch (const std::out_of_range& e) {
    std::cerr << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown exception." << std::endl;
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <limits>

int main() {
  int i = 10;
  while (std::cin >> i, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cerr << "Invalid input. Please try again." << std::endl;
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
  std::string file_name;
  std::string file_line_content;
  while (std::cin >> file_name, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    std::ifstream ifs(file_name);
    if (ifs.is_open()) {
      while (std::getline(ifs, file_line_content)) {
        std::cout << file_line_content << std::endl;
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
#include <sstream>

int main() {
  std::string str{"12"};
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

#if false
#include <iostream>
#include <thread>

void Test(int value, const int& ref_value, const int* ptr_value) {
  for (unsigned j = 0; j < 1e6; ++j) {
    int k = *ptr_value;
  }
}

int main() {
  int value = 10;
  std::thread t{Test, value, std::ref(value), &value};
  t.detach();
  return 0;
}
#endif

#if false
#include <iostream>
#include <string>
#include <thread>

class Test {
 public:
  Test(int value) {
    std::cout << std::this_thread::get_id() << " Constructor called."
              << std::endl;
  }
};

void TestFunction(const Test& test) {
  std::cout << "Child thread: " << std::this_thread::get_id() << std::endl;
}

int main() {
  std::cout << "Main thread: " << std::this_thread::get_id() << std::endl;
  int value = 100;
  // 使用了隐式转换
  std::thread t{TestFunction, value};
  t.detach();
  return 0;
}
#endif

#if false
#include <iostream>
#include <thread>

int main() {
  std::cout << "Main thread: " << std::this_thread::get_id() << std::endl;
  return 0;
}
#endif

#if false
#include <atomic>
#include <iostream>
#include <thread>

std::atomic<unsigned> g_num{0};

void Test() {
  for (unsigned i = 0; i < 1e5; ++i) {
    ++g_num;
  }
}

int main() {
  std::thread t1{Test};
  std::thread t2{Test};
  t1.join();
  t2.join();
  std::cout << "g_num = " << g_num << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <mutex>
#include <thread>

unsigned g_num{0};
std::mutex g_mutex1{};
std::mutex g_mutex2{};

void Test() {
  for (unsigned i = 0; i < 1e5; ++i) {
    std::scoped_lock lock{g_mutex1, g_mutex2};
    ++g_num;
  }
}

int main() {
  std::thread t{Test};
  for (unsigned i = 0; i < 1e5; ++i) {
    std::scoped_lock lock{g_mutex1, g_mutex2};
    ++g_num;
  }
  t.join();
  std::cout << "g_num = " << g_num << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <string>
#include <thread>

void PrintStr(const std::string& str) {
  for (size_t i = 0; i < 1e6; ++i) {
    std::cout << i;
  }
  std::cout << str << std::endl;
}

int main() {
  std::thread t{PrintStr, "Hello, World!"};
  bool is_joinable = t.joinable();
  if (is_joinable) {
    t.join();
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <thread>

void Foo(int& x) {
  x += 1;
}

int main() {
  int num{1};
  std::thread t{Foo, std::ref(num)};
  t.join();
  std::cout << num << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <thread>

void ThreadFunction() {
  std::cout << "Child thread: " << std::this_thread::get_id() << std::endl;
}

int main() {
  std::thread t{ThreadFunction};
  std::cout << "Main thread: " << std::this_thread::get_id() << std::endl;
  t.join();
  return 0;
}
#endif

#if false
#include <cstddef>
#include <iostream>
#include <mutex>
#include <thread>

int g_count{0};
std::mutex g_mutex{};

void Test() {
  for (size_t i = 0; i < 136; ++i) {
    std::scoped_lock lock{g_mutex};
    ++g_count;
  }
}

int main() {
  std::thread t1{Test};
  std::thread t2{Test};
  t1.join();
  t2.join();
  std::cout << "g_count = " << g_count << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <mutex>

std::mutex g_mutex1{};
std::mutex g_mutex2{};

void Test() {
  std::scoped_lock lock{g_mutex1, g_mutex2};

}
#endif

#if false
#include <iostream>
#include <string>

double Divide(double divisior, double dividend) {
  if (dividend == 0) {
    throw std::runtime_error("Dividend cannot be zero.");
  }
  return divisior / dividend;
}

void InputNum(const std::string& str, double& num) {
  std::cout << str << std::endl;
  while (std::cin >> num, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input. Please try again." << std::endl;
      continue;
    }
    break;
  }
}

int main() {
  double divisior{.0};
  double dividend{.0};
  InputNum("Enter the divisior: ", divisior);
  InputNum("Enter the dividend: ", dividend);
  try {
    double result = Divide(divisior, dividend);
    std::cout << "Result of " << divisior << " / " << dividend << " = "
              << result << std::endl;
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
#endif

#if false
#include <fstream>
#include <iostream>

void OutputFileContent(const std::string& file_name) {
  std::ifstream ifs(file_name);
  std::string file_line_content;
  if (ifs.is_open()) {
    while (std::getline(ifs, file_line_content)) {
      std::cout << file_line_content << std::endl;
    }
    if (ifs.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    ifs.close();
  } else {
    if (ifs.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (ifs.fail()) {
      throw std::runtime_error("File not found.");
    }
  }
}

int main() {
  std::string file_name;
  while (std::cin >> file_name, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    try {
      OutputFileContent(file_name);
    } catch (const std::exception& e) {
      std::cerr << e.what() << std::endl;
    } catch (...) {
      std::cerr << "Unknown exception." << std::endl;
    }
  }
  return 0;
}
#endif

#if false
#include <fstream>
#include <iostream>

int main() {
  try {
    while (true) {
      int* ptr = new int[100000]{};
    }
  } catch (const std::bad_alloc& e) {
    std::cerr << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown exception." << std::endl;
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <stdexcept>
#include <vector>

int main() {
  std::vector<int> vec{1, 2, 3, 4, 5};
  try {
    vec.at(10);
  } catch (const std::out_of_range& e) {
    std::cerr << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown exception." << std::endl;
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <limits>

int main() {
  int i = 10;
  while (std::cin >> i, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cerr << "Invalid input. Please try again." << std::endl;
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
  std::string file_name;
  std::string file_line_content;
  while (std::cin >> file_name, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    std::ifstream ifs(file_name);
    if (ifs.is_open()) {
      while (std::getline(ifs, file_line_content)) {
        std::cout << file_line_content << std::endl;
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
#include <sstream>

int main() {
  std::string str{"12"};
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

#if false
#include <iostream>
#include <thread>

void Test(int value, const int& ref_value, const int* ptr_value) {
  for (unsigned j = 0; j < 1e6; ++j) {
    int k = *ptr_value;
  }
}

int main() {
  int value = 10;
  std::thread t{Test, value, std::ref(value), &value};
  t.detach();
  return 0;
}
#endif

#if false
#include <iostream>
#include <string>
#include <thread>

class Test {
 public:
  Test(int value) {
    std::cout << std::this_thread::get_id() << " Constructor called."
              << std::endl;
  }
};

void TestFunction(const Test& test) {
  std::cout << "Child thread: " << std::this_thread::get_id() << std::endl;
}

int main() {
  std::cout << "Main thread: " << std::this_thread::get_id() << std::endl;
  int value = 100;
  // 使用了隐式转换
  std::thread t{TestFunction, value};
  t.detach();
  return 0;
}
#endif

#if false
#include <iostream>
#include <thread>

int main() {
  std::cout << "Main thread: " << std::this_thread::get_id() << std::endl;
  return 0;
}
#endif

#if false
#include <atomic>
#include <iostream>
#include <thread>

std::atomic<unsigned> g_num{0};

void Test() {
  for (unsigned i = 0; i < 1e5; ++i) {
    ++g_num;
  }
}

int main() {
  std::thread t1{Test};
  std::thread t2{Test};
  t1.join();
  t2.join();
  std::cout << "g_num = " << g_num << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <mutex>
#include <thread>

unsigned g_num{0};
std::mutex g_mutex1{};
std::mutex g_mutex2{};

void Test() {
  for (unsigned i = 0; i < 1e5; ++i) {
    std::scoped_lock lock{g_mutex1, g_mutex2};
    ++g_num;
  }
}

int main() {
  std::thread t{Test};
  for (unsigned i = 0; i < 1e5; ++i) {
    std::scoped_lock lock{g_mutex1, g_mutex2};
    ++g_num;
  }
  t.join();
  std::cout << "g_num = " << g_num << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <string>
#include <thread>

void PrintStr(const std::string& str) {
  for (size_t i = 0; i < 1e6; ++i) {
    std::cout << i;
  }
  std::cout << str << std::endl;
}

int main() {
  std::thread t{PrintStr, "Hello, World!"};
  bool is_joinable = t.joinable();
  if (is_joinable) {
    t.join();
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <thread>

void Foo(int& x) {
  x += 1;
}

int main() {
  int num{1};
  std::thread t{Foo, std::ref(num)};
  t.join();
  std::cout << num << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <thread>

void ThreadFunction() {
  std::cout << "Child thread: " << std::this_thread::get_id() << std::endl;
}

int main() {
  std::thread t{ThreadFunction};
  std::cout << "Main thread: " << std::this_thread::get_id() << std::endl;
  t.join();
  return 0;
}
#endif

#if false
#include <cstddef>
#include <iostream>
#include <mutex>
#include <thread>

int g_count{0};
std::mutex g_mutex{};

void Test() {
  for (size_t i = 0; i < 136; ++i) {
    std::scoped_lock lock{g_mutex};
    ++g_count;
  }
}

int main() {
  std::thread t1{Test};
  std::thread t2{Test};
  t1.join();
  t2.join();
  std::cout << "g_count = " << g_count << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <mutex>

std::mutex g_mutex1{};
std::mutex g_mutex2{};

void Test() {
  std::scoped_lock lock{g_mutex1, g_mutex2};

}
#endif

#if false
#include <iostream>
#include <string>

double Divide(double divisior, double dividend) {
  if (dividend == 0) {
    throw std::runtime_error("Dividend cannot be zero.");
  }
  return divisior / dividend;
}

void InputNum(const std::string& str, double& num) {
  std::cout << str << std::endl;
  while (std::cin >> num, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input. Please try again." << std::endl;
      continue;
    }
    break;
  }
}

int main() {
  double divisior{.0};
  double dividend{.0};
  InputNum("Enter the divisior: ", divisior);
  InputNum("Enter the dividend: ", dividend);
  try {
    double result = Divide(divisior, dividend);
    std::cout << "Result of " << divisior << " / " << dividend << " = "
              << result << std::endl;
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
#endif

#if false
#include <fstream>
#include <iostream>

void OutputFileContent(const std::string& file_name) {
  std::ifstream ifs(file_name);
  std::string file_line_content;
  if (ifs.is_open()) {
    while (std::getline(ifs, file_line_content)) {
      std::cout << file_line_content << std::endl;
    }
    if (ifs.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    ifs.close();
  } else {
    if (ifs.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (ifs.fail()) {
      throw std::runtime_error("File not found.");
    }
  }
}

int main() {
  std::string file_name;
  while (std::cin >> file_name, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    try {
      OutputFileContent(file_name);
    } catch (const std::exception& e) {
      std::cerr << e.what() << std::endl;
    } catch (...) {
      std::cerr << "Unknown exception." << std::endl;
    }
  }
  return 0;
}
#endif

#if false
#include <fstream>
#include <iostream>

int main() {
  try {
    while (true) {
      int* ptr = new int[100000]{};
    }
  } catch (const std::bad_alloc& e) {
    std::cerr << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown exception." << std::endl;
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <stdexcept>
#include <vector>

int main() {
  std::vector<int> vec{1, 2, 3, 4, 5};
  try {
    vec.at(10);
  } catch (const std::out_of_range& e) {
    std::cerr << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown exception." << std::endl;
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <limits>

int main() {
  int i = 10;
  while (std::cin >> i, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cerr << "Invalid input. Please try again." << std::endl;
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
  std::string file_name;
  std::string file_line_content;
  while (std::cin >> file_name, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    std::ifstream ifs(file_name);
    if (ifs.is_open()) {
      while (std::getline(ifs, file_line_content)) {
        std::cout << file_line_content << std::endl;
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
#include <sstream>

int main() {
  std::string str{"12"};
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

#if false
#include <iostream>
#include <thread>

void Test(int value, const int& ref_value, const int* ptr_value) {
  for (unsigned j = 0; j < 1e6; ++j) {
    int k = *ptr_value;
  }
}

int main() {
  int value = 10;
  std::thread t{Test, value, std::ref(value), &value};
  t.detach();
  return 0;
}
#endif

#if false
#include <iostream>
#include <string>
#include <thread>

class Test {
 public:
  Test(int value) {
    std::cout << std::this_thread::get_id() << " Constructor called."
              << std::endl;
  }
};

void TestFunction(const Test& test) {
  std::cout << "Child thread: " << std::this_thread::get_id() << std::endl;
}

int main() {
  std::cout << "Main thread: " << std::this_thread::get_id() << std::endl;
  int value = 100;
  // 使用了隐式转换
  std::thread t{TestFunction, value};
  t.detach();
  return 0;
}
#endif

#if false
#include <iostream>
#include <thread>

int main() {
  std::cout << "Main thread: " << std::this_thread::get_id() << std::endl;
  return 0;
}
#endif

#if false
#include <atomic>
#include <iostream>
#include <thread>

std::atomic<unsigned> g_num{0};

void Test() {
  for (unsigned i = 0; i < 1e5; ++i) {
    ++g_num;
  }
}

int main() {
  std::thread t1{Test};
  std::thread t2{Test};
  t1.join();
  t2.join();
  std::cout << "g_num = " << g_num << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <mutex>
#include <thread>

unsigned g_num{0};
std::mutex g_mutex1{};
std::mutex g_mutex2{};

void Test() {
  for (unsigned i = 0; i < 1e5; ++i) {
    std::scoped_lock lock{g_mutex1, g_mutex2};
    ++g_num;
  }
}

int main() {
  std::thread t{Test};
  for (unsigned i = 0; i < 1e5; ++i) {
    std::scoped_lock lock{g_mutex1, g_mutex2};
    ++g_num;
  }
  t.join();
  std::cout << "g_num = " << g_num << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <string>
#include <thread>

void PrintStr(const std::string& str) {
  for (size_t i = 0; i < 1e6; ++i) {
    std::cout << i;
  }
  std::cout << str << std::endl;
}

int main() {
  std::thread t{PrintStr, "Hello, World!"};
  bool is_joinable = t.joinable();
  if (is_joinable) {
    t.join();
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <thread>

void Foo(int& x) {
  x += 1;
}

int main() {
  int num{1};
  std::thread t{Foo, std::ref(num)};
  t.join();
  std::cout << num << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <thread>

void ThreadFunction() {
  std::cout << "Child thread: " << std::this_thread::get_id() << std::endl;
}

int main() {
  std::thread t{ThreadFunction};
  std::cout << "Main thread: " << std::this_thread::get_id() << std::endl;
  t.join();
  return 0;
}
#endif

#if false
#include <cstddef>
#include <iostream>
#include <mutex>
#include <thread>

int g_count{0};
std::mutex g_mutex{};

void Test() {
  for (size_t i = 0; i < 136; ++i) {
    std::scoped_lock lock{g_mutex};
    ++g_count;
  }
}

int main() {
  std::thread t1{Test};
  std::thread t2{Test};
  t1.join();
  t2.join();
  std::cout << "g_count = " << g_count << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <mutex>

std::mutex g_mutex1{};
std::mutex g_mutex2{};

void Test() {
  std::scoped_lock lock{g_mutex1, g_mutex2};

}
#endif

#if false
#include <iostream>
#include <string>

double Divide(double divisior, double dividend) {
  if (dividend == 0) {
    throw std::runtime_error("Dividend cannot be zero.");
  }
  return divisior / dividend;
}

void InputNum(const std::string& str, double& num) {
  std::cout << str << std::endl;
  while (std::cin >> num, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input. Please try again." << std::endl;
      continue;
    }
    break;
  }
}

int main() {
  double divisior{.0};
  double dividend{.0};
  InputNum("Enter the divisior: ", divisior);
  InputNum("Enter the dividend: ", dividend);
  try {
    double result = Divide(divisior, dividend);
    std::cout << "Result of " << divisior << " / " << dividend << " = "
              << result << std::endl;
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
#endif

#if false
#include <fstream>
#include <iostream>

void OutputFileContent(const std::string& file_name) {
  std::ifstream ifs(file_name);
  std::string file_line_content;
  if (ifs.is_open()) {
    while (std::getline(ifs, file_line_content)) {
      std::cout << file_line_content << std::endl;
    }
    if (ifs.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    ifs.close();
  } else {
    if (ifs.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (ifs.fail()) {
      throw std::runtime_error("File not found.");
    }
  }
}

int main() {
  std::string file_name;
  while (std::cin >> file_name, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    try {
      OutputFileContent(file_name);
    } catch (const std::exception& e) {
      std::cerr << e.what() << std::endl;
    } catch (...) {
      std::cerr << "Unknown exception." << std::endl;
    }
  }
  return 0;
}
#endif

#if false
#include <fstream>
#include <iostream>

int main() {
  try {
    while (true) {
      int* ptr = new int[100000]{};
    }
  } catch (const std::bad_alloc& e) {
    std::cerr << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown exception." << std::endl;
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <stdexcept>
#include <vector>

int main() {
  std::vector<int> vec{1, 2, 3, 4, 5};
  try {
    vec.at(10);
  } catch (const std::out_of_range& e) {
    std::cerr << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown exception." << std::endl;
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <limits>

int main() {
  int i = 10;
  while (std::cin >> i, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cerr << "Invalid input. Please try again." << std::endl;
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
  std::string file_name;
  std::string file_line_content;
  while (std::cin >> file_name, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    std::ifstream ifs(file_name);
    if (ifs.is_open()) {
      while (std::getline(ifs, file_line_content)) {
        std::cout << file_line_content << std::endl;
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
#include <sstream>

int main() {
  std::string str{"12"};
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

#if false
#include <iostream>
#include <thread>

void Test(int value, const int& ref_value, const int* ptr_value) {
  for (unsigned j = 0; j < 1e6; ++j) {
    int k = *ptr_value;
  }
}

int main() {
  int value = 10;
  std::thread t{Test, value, std::ref(value), &value};
  t.detach();
  return 0;
}
#endif

#if false
#include <iostream>
#include <string>
#include <thread>

class Test {
 public:
  Test(int value) {
    std::cout << std::this_thread::get_id() << " Constructor called."
              << std::endl;
  }
};

void TestFunction(const Test& test) {
  std::cout << "Child thread: " << std::this_thread::get_id() << std::endl;
}

int main() {
  std::cout << "Main thread: " << std::this_thread::get_id() << std::endl;
  int value = 100;
  // 使用了隐式转换
  std::thread t{TestFunction, value};
  t.detach();
  return 0;
}
#endif

#if false
#include <iostream>
#include <thread>

int main() {
  std::cout << "Main thread: " << std::this_thread::get_id() << std::endl;
  return 0;
}
#endif

#if false
#include <atomic>
#include <iostream>
#include <thread>

std::atomic<unsigned> g_num{0};

void Test() {
  for (unsigned i = 0; i < 1e5; ++i) {
    ++g_num;
  }
}

int main() {
  std::thread t1{Test};
  std::thread t2{Test};
  t1.join();
  t2.join();
  std::cout << "g_num = " << g_num << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <mutex>
#include <thread>

unsigned g_num{0};
std::mutex g_mutex1{};
std::mutex g_mutex2{};

void Test() {
  for (unsigned i = 0; i < 1e5; ++i) {
    std::scoped_lock lock{g_mutex1, g_mutex2};
    ++g_num;
  }
}

int main() {
  std::thread t{Test};
  for (unsigned i = 0; i < 1e5; ++i) {
    std::scoped_lock lock{g_mutex1, g_mutex2};
    ++g_num;
  }
  t.join();
  std::cout << "g_num = " << g_num << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <string>
#include <thread>

void PrintStr(const std::string& str) {
  for (size_t i = 0; i < 1e6; ++i) {
    std::cout << i;
  }
  std::cout << str << std::endl;
}

int main() {
  std::thread t{PrintStr, "Hello, World!"};
  bool is_joinable = t.joinable();
  if (is_joinable) {
    t.join();
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <thread>

void Foo(int& x) {
  x += 1;
}

int main() {
  int num{1};
  std::thread t{Foo, std::ref(num)};
  t.join();
  std::cout << num << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <thread>

void ThreadFunction() {
  std::cout << "Child thread: " << std::this_thread::get_id() << std::endl;
}

int main() {
  std::thread t{ThreadFunction};
  std::cout << "Main thread: " << std::this_thread::get_id() << std::endl;
  t.join();
  return 0;
}
#endif

#if false
#include <cstddef>
#include <iostream>
#include <mutex>
#include <thread>

int g_count{0};
std::mutex g_mutex{};

void Test() {
  for (size_t i = 0; i < 136; ++i) {
    std::scoped_lock lock{g_mutex};
    ++g_count;
  }
}

int main() {
  std::thread t1{Test};
  std::thread t2{Test};
  t1.join();
  t2.join();
  std::cout << "g_count = " << g_count << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <mutex>

std::mutex g_mutex1{};
std::mutex g_mutex2{};

void Test() {
  std::scoped_lock lock{g_mutex1, g_mutex2};

}
#endif

#if false
#include <iostream>
#include <string>

double Divide(double divisior, double dividend) {
  if (dividend == 0) {
    throw std::runtime_error("Dividend cannot be zero.");
  }
  return divisior / dividend;
}

void InputNum(const std::string& str, double& num) {
  std::cout << str << std::endl;
  while (std::cin >> num, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input. Please try again." << std::endl;
      continue;
    }
    break;
  }
}

int main() {
  double divisior{.0};
  double dividend{.0};
  InputNum("Enter the divisior: ", divisior);
  InputNum("Enter the dividend: ", dividend);
  try {
    double result = Divide(divisior, dividend);
    std::cout << "Result of " << divisior << " / " << dividend << " = "
              << result << std::endl;
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
#endif

#if false
#include <fstream>
#include <iostream>

void OutputFileContent(const std::string& file_name) {
  std::ifstream ifs(file_name);
  std::string file_line_content;
  if (ifs.is_open()) {
    while (std::getline(ifs, file_line_content)) {
      std::cout << file_line_content << std::endl;
    }
    if (ifs.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    ifs.close();
  } else {
    if (ifs.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (ifs.fail()) {
      throw std::runtime_error("File not found.");
    }
  }
}

int main() {
  std::string file_name;
  while (std::cin >> file_name, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    try {
      OutputFileContent(file_name);
    } catch (const std::exception& e) {
      std::cerr << e.what() << std::endl;
    } catch (...) {
      std::cerr << "Unknown exception." << std::endl;
    }
  }
  return 0;
}
#endif

#if false
#include <fstream>
#include <iostream>

int main() {
  try {
    while (true) {
      int* ptr = new int[100000]{};
    }
  } catch (const std::bad_alloc& e) {
    std::cerr << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown exception." << std::endl;
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <stdexcept>
#include <vector>

int main() {
  std::vector<int> vec{1, 2, 3, 4, 5};
  try {
    vec.at(10);
  } catch (const std::out_of_range& e) {
    std::cerr << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown exception." << std::endl;
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <limits>

int main() {
  int i = 10;
  while (std::cin >> i, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cerr << "Invalid input. Please try again." << std::endl;
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
  std::string file_name;
  std::string file_line_content;
  while (std::cin >> file_name, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    std::ifstream ifs(file_name);
    if (ifs.is_open()) {
      while (std::getline(ifs, file_line_content)) {
        std::cout << file_line_content << std::endl;
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
#include <sstream>

int main() {
  std::string str{"12"};
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

#if false
#include <iostream>
#include <thread>

void Test(int value, const int& ref_value, const int* ptr_value) {
  for (unsigned j = 0; j < 1e6; ++j) {
    int k = *ptr_value;
  }
}

int main() {
  int value = 10;
  std::thread t{Test, value, std::ref(value), &value};
  t.detach();
  return 0;
}
#endif

#if false
#include <iostream>
#include <string>
#include <thread>

class Test {
 public:
  Test(int value) {
    std::cout << std::this_thread::get_id() << " Constructor called."
              << std::endl;
  }
};

void TestFunction(const Test& test) {
  std::cout << "Child thread: " << std::this_thread::get_id() << std::endl;
}

int main() {
  std::cout << "Main thread: " << std::this_thread::get_id() << std::endl;
  int value = 100;
  // 使用了隐式转换
  std::thread t{TestFunction, value};
  t.detach();
  return 0;
}
#endif

#if false
#include <iostream>
#include <thread>

int main() {
  std::cout << "Main thread: " << std::this_thread::get_id() << std::endl;
  return 0;
}
#endif

#if false
#include <atomic>
#include <iostream>
#include <thread>

std::atomic<unsigned> g_num{0};

void Test() {
  for (unsigned i = 0; i < 1e5; ++i) {
    ++g_num;
  }
}

int main() {
  std::thread t1{Test};
  std::thread t2{Test};
  t1.join();
  t2.join();
  std::cout << "g_num = " << g_num << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <mutex>
#include <thread>

unsigned g_num{0};
std::mutex g_mutex1{};
std::mutex g_mutex2{};

void Test() {
  for (unsigned i = 0; i < 1e5; ++i) {
    std::scoped_lock lock{g_mutex1, g_mutex2};
    ++g_num;
  }
}

int main() {
  std::thread t{Test};
  for (unsigned i = 0; i < 1e5; ++i) {
    std::scoped_lock lock{g_mutex1, g_mutex2};
    ++g_num;
  }
  t.join();
  std::cout << "g_num = " << g_num << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <string>
#include <thread>

void PrintStr(const std::string& str) {
  for (size_t i = 0; i < 1e6; ++i) {
    std::cout << i;
  }
  std::cout << str << std::endl;
}

int main() {
  std::thread t{PrintStr, "Hello, World!"};
  bool is_joinable = t.joinable();
  if (is_joinable) {
    t.join();
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <thread>

void Foo(int& x) {
  x += 1;
}

int main() {
  int num{1};
  std::thread t{Foo, std::ref(num)};
  t.join();
  std::cout << num << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <thread>

void ThreadFunction() {
  std::cout << "Child thread: " << std::this_thread::get_id() << std::endl;
}

int main() {
  std::thread t{ThreadFunction};
  std::cout << "Main thread: " << std::this_thread::get_id() << std::endl;
  t.join();
  return 0;
}
#endif

#if false
#include <cstddef>
#include <iostream>
#include <mutex>
#include <thread>

int g_count{0};
std::mutex g_mutex{};

void Test() {
  for (size_t i = 0; i < 136; ++i) {
    std::scoped_lock lock{g_mutex};
    ++g_count;
  }
}

int main() {
  std::thread t1{Test};
  std::thread t2{Test};
  t1.join();
  t2.join();
  std::cout << "g_count = " << g_count << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <mutex>

std::mutex g_mutex1{};
std::mutex g_mutex2{};

void Test() {
  std::scoped_lock lock{g_mutex1, g_mutex2};

}
#endif

#if false
#include <iostream>
#include <string>

double Divide(double divisior, double dividend) {
  if (dividend == 0) {
    throw std::runtime_error("Dividend cannot be zero.");
  }
  return divisior / dividend;
}

void InputNum(const std::string& str, double& num) {
  std::cout << str << std::endl;
  while (std::cin >> num, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input. Please try again." << std::endl;
      continue;
    }
    break;
  }
}

int main() {
  double divisior{.0};
  double dividend{.0};
  InputNum("Enter the divisior: ", divisior);
  InputNum("Enter the dividend: ", dividend);
  try {
    double result = Divide(divisior, dividend);
    std::cout << "Result of " << divisior << " / " << dividend << " = "
              << result << std::endl;
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
#endif

#if false
#include <fstream>
#include <iostream>

void OutputFileContent(const std::string& file_name) {
  std::ifstream ifs(file_name);
  std::string file_line_content;
  if (ifs.is_open()) {
    while (std::getline(ifs, file_line_content)) {
      std::cout << file_line_content << std::endl;
    }
    if (ifs.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    ifs.close();
  } else {
    if (ifs.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (ifs.fail()) {
      throw std::runtime_error("File not found.");
    }
  }
}

int main() {
  std::string file_name;
  while (std::cin >> file_name, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    try {
      OutputFileContent(file_name);
    } catch (const std::exception& e) {
      std::cerr << e.what() << std::endl;
    } catch (...) {
      std::cerr << "Unknown exception." << std::endl;
    }
  }
  return 0;
}
#endif

#if false
#include <fstream>
#include <iostream>

int main() {
  try {
    while (true) {
      int* ptr = new int[100000]{};
    }
  } catch (const std::bad_alloc& e) {
    std::cerr << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown exception." << std::endl;
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <stdexcept>
#include <vector>

int main() {
  std::vector<int> vec{1, 2, 3, 4, 5};
  try {
    vec.at(10);
  } catch (const std::out_of_range& e) {
    std::cerr << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown exception." << std::endl;
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <limits>

int main() {
  int i = 10;
  while (std::cin >> i, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cerr << "Invalid input. Please try again." << std::endl;
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
  std::string file_name;
  std::string file_line_content;
  while (std::cin >> file_name, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    std::ifstream ifs(file_name);
    if (ifs.is_open()) {
      while (std::getline(ifs, file_line_content)) {
        std::cout << file_line_content << std::endl;
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
#include <sstream>

int main() {
  std::string str{"12"};
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

#if false
#include <iostream>
#include <thread>

void Test(int value, const int& ref_value, const int* ptr_value) {
  for (unsigned j = 0; j < 1e6; ++j) {
    int k = *ptr_value;
  }
}

int main() {
  int value = 10;
  std::thread t{Test, value, std::ref(value), &value};
  t.detach();
  return 0;
}
#endif

#if false
#include <iostream>
#include <string>
#include <thread>

class Test {
 public:
  Test(int value) {
    std::cout << std::this_thread::get_id() << " Constructor called."
              << std::endl;
  }
};

void TestFunction(const Test& test) {
  std::cout << "Child thread: " << std::this_thread::get_id() << std::endl;
}

int main() {
  std::cout << "Main thread: " << std::this_thread::get_id() << std::endl;
  int value = 100;
  // 使用了隐式转换
  std::thread t{TestFunction, value};
  t.detach();
  return 0;
}
#endif

#if false
#include <iostream>
#include <thread>

int main() {
  std::cout << "Main thread: " << std::this_thread::get_id() << std::endl;
  return 0;
}
#endif

#if false
#include <atomic>
#include <iostream>
#include <thread>

std::atomic<unsigned> g_num{0};

void Test() {
  for (unsigned i = 0; i < 1e5; ++i) {
    ++g_num;
  }
}

int main() {
  std::thread t1{Test};
  std::thread t2{Test};
  t1.join();
  t2.join();
  std::cout << "g_num = " << g_num << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <mutex>
#include <thread>

unsigned g_num{0};
std::mutex g_mutex1{};
std::mutex g_mutex2{};

void Test() {
  for (unsigned i = 0; i < 1e5; ++i) {
    std::scoped_lock lock{g_mutex1, g_mutex2};
    ++g_num;
  }
}

int main() {
  std::thread t{Test};
  for (unsigned i = 0; i < 1e5; ++i) {
    std::scoped_lock lock{g_mutex1, g_mutex2};
    ++g_num;
  }
  t.join();
  std::cout << "g_num = " << g_num << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <string>
#include <thread>

void PrintStr(const std::string& str) {
  for (size_t i = 0; i < 1e6; ++i) {
    std::cout << i;
  }
  std::cout << str << std::endl;
}

int main() {
  std::thread t{PrintStr, "Hello, World!"};
  bool is_joinable = t.joinable();
  if (is_joinable) {
    t.join();
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <thread>

void Foo(int& x) {
  x += 1;
}

int main() {
  int num{1};
  std::thread t{Foo, std::ref(num)};
  t.join();
  std::cout << num << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <thread>

void ThreadFunction() {
  std::cout << "Child thread: " << std::this_thread::get_id() << std::endl;
}

int main() {
  std::thread t{ThreadFunction};
  std::cout << "Main thread: " << std::this_thread::get_id() << std::endl;
  t.join();
  return 0;
}
#endif

#if false
#include <cstddef>
#include <iostream>
#include <mutex>
#include <thread>

int g_count{0};
std::mutex g_mutex{};

void Test() {
  for (size_t i = 0; i < 136; ++i) {
    std::scoped_lock lock{g_mutex};
    ++g_count;
  }
}

int main() {
  std::thread t1{Test};
  std::thread t2{Test};
  t1.join();
  t2.join();
  std::cout << "g_count = " << g_count << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <mutex>

std::mutex g_mutex1{};
std::mutex g_mutex2{};

void Test() {
  std::scoped_lock lock{g_mutex1, g_mutex2};

}
#endif

#if false
#include <iostream>
#include <string>

double Divide(double divisior, double dividend) {
  if (dividend == 0) {
    throw std::runtime_error("Dividend cannot be zero.");
  }
  return divisior / dividend;
}

void InputNum(const std::string& str, double& num) {
  std::cout << str << std::endl;
  while (std::cin >> num, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input. Please try again." << std::endl;
      continue;
    }
    break;
  }
}

int main() {
  double divisior{.0};
  double dividend{.0};
  InputNum("Enter the divisior: ", divisior);
  InputNum("Enter the dividend: ", dividend);
  try {
    double result = Divide(divisior, dividend);
    std::cout << "Result of " << divisior << " / " << dividend << " = "
              << result << std::endl;
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
#endif

#if false
#include <fstream>
#include <iostream>

void OutputFileContent(const std::string& file_name) {
  std::ifstream ifs(file_name);
  std::string file_line_content;
  if (ifs.is_open()) {
    while (std::getline(ifs, file_line_content)) {
      std::cout << file_line_content << std::endl;
    }
    if (ifs.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    ifs.close();
  } else {
    if (ifs.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (ifs.fail()) {
      throw std::runtime_error("File not found.");
    }
  }
}

int main() {
  std::string file_name;
  while (std::cin >> file_name, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    try {
      OutputFileContent(file_name);
    } catch (const std::exception& e) {
      std::cerr << e.what() << std::endl;
    } catch (...) {
      std::cerr << "Unknown exception." << std::endl;
    }
  }
  return 0;
}
#endif

#if false
#include <fstream>
#include <iostream>

int main() {
  try {
    while (true) {
      int* ptr = new int[100000]{};
    }
  } catch (const std::bad_alloc& e) {
    std::cerr << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown exception." << std::endl;
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <stdexcept>
#include <vector>

int main() {
  std::vector<int> vec{1, 2, 3, 4, 5};
  try {
    vec.at(10);
  } catch (const std::out_of_range& e) {
    std::cerr << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown exception." << std::endl;
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <limits>

int main() {
  int i = 10;
  while (std::cin >> i, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cerr << "Invalid input. Please try again." << std::endl;
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
  std::string file_name;
  std::string file_line_content;
  while (std::cin >> file_name, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    std::ifstream ifs(file_name);
    if (ifs.is_open()) {
      while (std::getline(ifs, file_line_content)) {
        std::cout << file_line_content << std::endl;
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
#include <sstream>

int main() {
  std::string str{"12"};
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

#if false
#include <iostream>
#include <thread>

void Test(int value, const int& ref_value, const int* ptr_value) {
  for (unsigned j = 0; j < 1e6; ++j) {
    int k = *ptr_value;
  }
}

int main() {
  int value = 10;
  std::thread t{Test, value, std::ref(value), &value};
  t.detach();
  return 0;
}
#endif

#if false
#include <iostream>
#include <string>
#include <thread>

class Test {
 public:
  Test(int value) {
    std::cout << std::this_thread::get_id() << " Constructor called."
              << std::endl;
  }
};

void TestFunction(const Test& test) {
  std::cout << "Child thread: " << std::this_thread::get_id() << std::endl;
}

int main() {
  std::cout << "Main thread: " << std::this_thread::get_id() << std::endl;
  int value = 100;
  // 使用了隐式转换
  std::thread t{TestFunction, value};
  t.detach();
  return 0;
}
#endif

#if false
#include <iostream>
#include <thread>

int main() {
  std::cout << "Main thread: " << std::this_thread::get_id() << std::endl;
  return 0;
}
#endif

#if false
#include <atomic>
#include <iostream>
#include <thread>

std::atomic<unsigned> g_num{0};

void Test() {
  for (unsigned i = 0; i < 1e5; ++i) {
    ++g_num;
  }
}

int main() {
  std::thread t1{Test};
  std::thread t2{Test};
  t1.join();
  t2.join();
  std::cout << "g_num = " << g_num << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <mutex>
#include <thread>

unsigned g_num{0};
std::mutex g_mutex1{};
std::mutex g_mutex2{};

void Test() {
  for (unsigned i = 0; i < 1e5; ++i) {
    std::scoped_lock lock{g_mutex1, g_mutex2};
    ++g_num;
  }
}

int main() {
  std::thread t{Test};
  for (unsigned i = 0; i < 1e5; ++i) {
    std::scoped_lock lock{g_mutex1, g_mutex2};
    ++g_num;
  }
  t.join();
  std::cout << "g_num = " << g_num << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <string>
#include <thread>

void PrintStr(const std::string& str) {
  for (size_t i = 0; i < 1e6; ++i) {
    std::cout << i;
  }
  std::cout << str << std::endl;
}

int main() {
  std::thread t{PrintStr, "Hello, World!"};
  bool is_joinable = t.joinable();
  if (is_joinable) {
    t.join();
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <thread>

void Foo(int& x) {
  x += 1;
}

int main() {
  int num{1};
  std::thread t{Foo, std::ref(num)};
  t.join();
  std::cout << num << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <thread>

void ThreadFunction() {
  std::cout << "Child thread: " << std::this_thread::get_id() << std::endl;
}

int main() {
  std::thread t{ThreadFunction};
  std::cout << "Main thread: " << std::this_thread::get_id() << std::endl;
  t.join();
  return 0;
}
#endif

#if false
#include <cstddef>
#include <iostream>
#include <mutex>
#include <thread>

int g_count{0};
std::mutex g_mutex{};

void Test() {
  for (size_t i = 0; i < 136; ++i) {
    std::scoped_lock lock{g_mutex};
    ++g_count;
  }
}

int main() {
  std::thread t1{Test};
  std::thread t2{Test};
  t1.join();
  t2.join();
  std::cout << "g_count = " << g_count << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <mutex>

std::mutex g_mutex1{};
std::mutex g_mutex2{};

void Test() {
  std::scoped_lock lock{g_mutex1, g_mutex2};

}
#endif

#if false
#include <iostream>
#include <string>

double Divide(double divisior, double dividend) {
  if (dividend == 0) {
    throw std::runtime_error("Dividend cannot be zero.");
  }
  return divisior / dividend;
}

void InputNum(const std::string& str, double& num) {
  std::cout << str << std::endl;
  while (std::cin >> num, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input. Please try again." << std::endl;
      continue;
    }
    break;
  }
}

int main() {
  double divisior{.0};
  double dividend{.0};
  InputNum("Enter the divisior: ", divisior);
  InputNum("Enter the dividend: ", dividend);
  try {
    double result = Divide(divisior, dividend);
    std::cout << "Result of " << divisior << " / " << dividend << " = "
              << result << std::endl;
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
#endif

#if false
#include <fstream>
#include <iostream>

void OutputFileContent(const std::string& file_name) {
  std::ifstream ifs(file_name);
  std::string file_line_content;
  if (ifs.is_open()) {
    while (std::getline(ifs, file_line_content)) {
      std::cout << file_line_content << std::endl;
    }
    if (ifs.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    ifs.close();
  } else {
    if (ifs.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (ifs.fail()) {
      throw std::runtime_error("File not found.");
    }
  }
}

int main() {
  std::string file_name;
  while (std::cin >> file_name, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    try {
      OutputFileContent(file_name);
    } catch (const std::exception& e) {
      std::cerr << e.what() << std::endl;
    } catch (...) {
      std::cerr << "Unknown exception." << std::endl;
    }
  }
  return 0;
}
#endif

#if false
#include <fstream>
#include <iostream>

int main() {
  try {
    while (true) {
      int* ptr = new int[100000]{};
    }
  } catch (const std::bad_alloc& e) {
    std::cerr << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown exception." << std::endl;
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <stdexcept>
#include <vector>

int main() {
  std::vector<int> vec{1, 2, 3, 4, 5};
  try {
    vec.at(10);
  } catch (const std::out_of_range& e) {
    std::cerr << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown exception." << std::endl;
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <limits>

int main() {
  int i = 10;
  while (std::cin >> i, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cerr << "Invalid input. Please try again." << std::endl;
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
  std::string file_name;
  std::string file_line_content;
  while (std::cin >> file_name, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    std::ifstream ifs(file_name);
    if (ifs.is_open()) {
      while (std::getline(ifs, file_line_content)) {
        std::cout << file_line_content << std::endl;
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
#include <sstream>

int main() {
  std::string str{"12"};
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

#if false
#include <iostream>
#include <thread>

void Test(int value, const int& ref_value, const int* ptr_value) {
  for (unsigned j = 0; j < 1e6; ++j) {
    int k = *ptr_value;
  }
}

int main() {
  int value = 10;
  std::thread t{Test, value, std::ref(value), &value};
  t.detach();
  return 0;
}
#endif

#if false
#include <iostream>
#include <string>
#include <thread>

class Test {
 public:
  Test(int value) {
    std::cout << std::this_thread::get_id() << " Constructor called."
              << std::endl;
  }
};

void TestFunction(const Test& test) {
  std::cout << "Child thread: " << std::this_thread::get_id() << std::endl;
}

int main() {
  std::cout << "Main thread: " << std::this_thread::get_id() << std::endl;
  int value = 100;
  // 使用了隐式转换
  std::thread t{TestFunction, value};
  t.detach();
  return 0;
}
#endif

#if false
#include <iostream>
#include <thread>

int main() {
  std::cout << "Main thread: " << std::this_thread::get_id() << std::endl;
  return 0;
}
#endif

#if false
#include <atomic>
#include <iostream>
#include <thread>

std::atomic<unsigned> g_num{0};

void Test() {
  for (unsigned i = 0; i < 1e5; ++i) {
    ++g_num;
  }
}

int main() {
  std::thread t1{Test};
  std::thread t2{Test};
  t1.join();
  t2.join();
  std::cout << "g_num = " << g_num << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <mutex>
#include <thread>

unsigned g_num{0};
std::mutex g_mutex1{};
std::mutex g_mutex2{};

void Test() {
  for (unsigned i = 0; i < 1e5; ++i) {
    std::scoped_lock lock{g_mutex1, g_mutex2};
    ++g_num;
  }
}

int main() {
  std::thread t{Test};
  for (unsigned i = 0; i < 1e5; ++i) {
    std::scoped_lock lock{g_mutex1, g_mutex2};
    ++g_num;
  }
  t.join();
  std::cout << "g_num = " << g_num << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <string>
#include <thread>

void PrintStr(const std::string& str) {
  for (size_t i = 0; i < 1e6; ++i) {
    std::cout << i;
  }
  std::cout << str << std::endl;
}

int main() {
  std::thread t{PrintStr, "Hello, World!"};
  bool is_joinable = t.joinable();
  if (is_joinable) {
    t.join();
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <thread>

void Foo(int& x) {
  x += 1;
}

int main() {
  int num{1};
  std::thread t{Foo, std::ref(num)};
  t.join();
  std::cout << num << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <thread>

void ThreadFunction() {
  std::cout << "Child thread: " << std::this_thread::get_id() << std::endl;
}

int main() {
  std::thread t{ThreadFunction};
  std::cout << "Main thread: " << std::this_thread::get_id() << std::endl;
  t.join();
  return 0;
}
#endif

#if false
#include <cstddef>
#include <iostream>
#include <mutex>
#include <thread>

int g_count{0};
std::mutex g_mutex{};

void Test() {
  for (size_t i = 0; i < 136; ++i) {
    std::scoped_lock lock{g_mutex};
    ++g_count;
  }
}

int main() {
  std::thread t1{Test};
  std::thread t2{Test};
  t1.join();
  t2.join();
  std::cout << "g_count = " << g_count << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <mutex>

std::mutex g_mutex1{};
std::mutex g_mutex2{};

void Test() {
  std::scoped_lock lock{g_mutex1, g_mutex2};

}
#endif

#if false
#include <iostream>
#include <string>

double Divide(double divisior, double dividend) {
  if (dividend == 0) {
    throw std::runtime_error("Dividend cannot be zero.");
  }
  return divisior / dividend;
}

void InputNum(const std::string& str, double& num) {
  std::cout << str << std::endl;
  while (std::cin >> num, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input. Please try again." << std::endl;
      continue;
    }
    break;
  }
}

int main() {
  double divisior{.0};
  double dividend{.0};
  InputNum("Enter the divisior: ", divisior);
  InputNum("Enter the dividend: ", dividend);
  try {
    double result = Divide(divisior, dividend);
    std::cout << "Result of " << divisior << " / " << dividend << " = "
              << result << std::endl;
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
#endif

#if false
#include <fstream>
#include <iostream>

void OutputFileContent(const std::string& file_name) {
  std::ifstream ifs(file_name);
  std::string file_line_content;
  if (ifs.is_open()) {
    while (std::getline(ifs, file_line_content)) {
      std::cout << file_line_content << std::endl;
    }
    if (ifs.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    ifs.close();
  } else {
    if (ifs.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (ifs.fail()) {
      throw std::runtime_error("File not found.");
    }
  }
}

int main() {
  std::string file_name;
  while (std::cin >> file_name, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    try {
      OutputFileContent(file_name);
    } catch (const std::exception& e) {
      std::cerr << e.what() << std::endl;
    } catch (...) {
      std::cerr << "Unknown exception." << std::endl;
    }
  }
  return 0;
}
#endif

#if false
#include <fstream>
#include <iostream>

int main() {
  try {
    while (true) {
      int* ptr = new int[100000]{};
    }
  } catch (const std::bad_alloc& e) {
    std::cerr << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown exception." << std::endl;
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <stdexcept>
#include <vector>

int main() {
  std::vector<int> vec{1, 2, 3, 4, 5};
  try {
    vec.at(10);
  } catch (const std::out_of_range& e) {
    std::cerr << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown exception." << std::endl;
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <limits>

int main() {
  int i = 10;
  while (std::cin >> i, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cerr << "Invalid input. Please try again." << std::endl;
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
  std::string file_name;
  std::string file_line_content;
  while (std::cin >> file_name, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    std::ifstream ifs(file_name);
    if (ifs.is_open()) {
      while (std::getline(ifs, file_line_content)) {
        std::cout << file_line_content << std::endl;
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
#include <sstream>

int main() {
  std::string str{"12"};
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

#if false
#include <iostream>
#include <thread>

void Test(int value, const int& ref_value, const int* ptr_value) {
  for (unsigned j = 0; j < 1e6; ++j) {
    int k = *ptr_value;
  }
}

int main() {
  int value = 10;
  std::thread t{Test, value, std::ref(value), &value};
  t.detach();
  return 0;
}
#endif

#if false
#include <iostream>
#include <string>
#include <thread>

class Test {
 public:
  Test(int value) {
    std::cout << std::this_thread::get_id() << " Constructor called."
              << std::endl;
  }
};

void TestFunction(const Test& test) {
  std::cout << "Child thread: " << std::this_thread::get_id() << std::endl;
}

int main() {
  std::cout << "Main thread: " << std::this_thread::get_id() << std::endl;
  int value = 100;
  // 使用了隐式转换
  std::thread t{TestFunction, value};
  t.detach();
  return 0;
}
#endif

#if false
#include <iostream>
#include <thread>

int main() {
  std::cout << "Main thread: " << std::this_thread::get_id() << std::endl;
  return 0;
}
#endif

#if false
#include <atomic>
#include <iostream>
#include <thread>

std::atomic<unsigned> g_num{0};

void Test() {
  for (unsigned i = 0; i < 1e5; ++i) {
    ++g_num;
  }
}

int main() {
  std::thread t1{Test};
  std::thread t2{Test};
  t1.join();
  t2.join();
  std::cout << "g_num = " << g_num << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <mutex>
#include <thread>

unsigned g_num{0};
std::mutex g_mutex1{};
std::mutex g_mutex2{};

void Test() {
  for (unsigned i = 0; i < 1e5; ++i) {
    std::scoped_lock lock{g_mutex1, g_mutex2};
    ++g_num;
  }
}

int main() {
  std::thread t{Test};
  for (unsigned i = 0; i < 1e5; ++i) {
    std::scoped_lock lock{g_mutex1, g_mutex2};
    ++g_num;
  }
  t.join();
  std::cout << "g_num = " << g_num << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <string>
#include <thread>

void PrintStr(const std::string& str) {
  for (size_t i = 0; i < 1e6; ++i) {
    std::cout << i;
  }
  std::cout << str << std::endl;
}

int main() {
  std::thread t{PrintStr, "Hello, World!"};
  bool is_joinable = t.joinable();
  if (is_joinable) {
    t.join();
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <thread>

void Foo(int& x) {
  x += 1;
}

int main() {
  int num{1};
  std::thread t{Foo, std::ref(num)};
  t.join();
  std::cout << num << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <thread>

void ThreadFunction() {
  std::cout << "Child thread: " << std::this_thread::get_id() << std::endl;
}

int main() {
  std::thread t{ThreadFunction};
  std::cout << "Main thread: " << std::this_thread::get_id() << std::endl;
  t.join();
  return 0;
}
#endif

#if false
#include <cstddef>
#include <iostream>
#include <mutex>
#include <thread>

int g_count{0};
std::mutex g_mutex{};

void Test() {
  for (size_t i = 0; i < 136; ++i) {
    std::scoped_lock lock{g_mutex};
    ++g_count;
  }
}

int main() {
  std::thread t1{Test};
  std::thread t2{Test};
  t1.join();
  t2.join();
  std::cout << "g_count = " << g_count << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <mutex>

std::mutex g_mutex1{};
std::mutex g_mutex2{};

void Test() {
  std::scoped_lock lock{g_mutex1, g_mutex2};

}
#endif

#if false
#include <iostream>
#include <string>

double Divide(double divisior, double dividend) {
  if (dividend == 0) {
    throw std::runtime_error("Dividend cannot be zero.");
  }
  return divisior / dividend;
}

void InputNum(const std::string& str, double& num) {
  std::cout << str << std::endl;
  while (std::cin >> num, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input. Please try again." << std::endl;
      continue;
    }
    break;
  }
}

int main() {
  double divisior{.0};
  double dividend{.0};
  InputNum("Enter the divisior: ", divisior);
  InputNum("Enter the dividend: ", dividend);
  try {
    double result = Divide(divisior, dividend);
    std::cout << "Result of " << divisior << " / " << dividend << " = "
              << result << std::endl;
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
#endif

#if false
#include <fstream>
#include <iostream>

void OutputFileContent(const std::string& file_name) {
  std::ifstream ifs(file_name);
  std::string file_line_content;
  if (ifs.is_open()) {
    while (std::getline(ifs, file_line_content)) {
      std::cout << file_line_content << std::endl;
    }
    if (ifs.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    ifs.close();
  } else {
    if (ifs.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (ifs.fail()) {
      throw std::runtime_error("File not found.");
    }
  }
}

int main() {
  std::string file_name;
  while (std::cin >> file_name, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    try {
      OutputFileContent(file_name);
    } catch (const std::exception& e) {
      std::cerr << e.what() << std::endl;
    } catch (...) {
      std::cerr << "Unknown exception." << std::endl;
    }
  }
  return 0;
}
#endif

#if false
#include <fstream>
#include <iostream>

int main() {
  try {
    while (true) {
      int* ptr = new int[100000]{};
    }
  } catch (const std::bad_alloc& e) {
    std::cerr << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown exception." << std::endl;
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <stdexcept>
#include <vector>

int main() {
  std::vector<int> vec{1, 2, 3, 4, 5};
  try {
    vec.at(10);
  } catch (const std::out_of_range& e) {
    std::cerr << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown exception." << std::endl;
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <limits>

int main() {
  int i = 10;
  while (std::cin >> i, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cerr << "Invalid input. Please try again." << std::endl;
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
  std::string file_name;
  std::string file_line_content;
  while (std::cin >> file_name, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    std::ifstream ifs(file_name);
    if (ifs.is_open()) {
      while (std::getline(ifs, file_line_content)) {
        std::cout << file_line_content << std::endl;
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
#include <sstream>

int main() {
  std::string str{"12"};
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

#if false
#include <iostream>
#include <thread>

void Test(int value, const int& ref_value, const int* ptr_value) {
  for (unsigned j = 0; j < 1e6; ++j) {
    int k = *ptr_value;
  }
}

int main() {
  int value = 10;
  std::thread t{Test, value, std::ref(value), &value};
  t.detach();
  return 0;
}
#endif

#if false
#include <iostream>
#include <string>
#include <thread>

class Test {
 public:
  Test(int value) {
    std::cout << std::this_thread::get_id() << " Constructor called."
              << std::endl;
  }
};

void TestFunction(const Test& test) {
  std::cout << "Child thread: " << std::this_thread::get_id() << std::endl;
}

int main() {
  std::cout << "Main thread: " << std::this_thread::get_id() << std::endl;
  int value = 100;
  // 使用了隐式转换
  std::thread t{TestFunction, value};
  t.detach();
  return 0;
}
#endif

#if false
#include <iostream>
#include <thread>

int main() {
  std::cout << "Main thread: " << std::this_thread::get_id() << std::endl;
  return 0;
}
#endif

#if false
#include <atomic>
#include <iostream>
#include <thread>

std::atomic<unsigned> g_num{0};

void Test() {
  for (unsigned i = 0; i < 1e5; ++i) {
    ++g_num;
  }
}

int main() {
  std::thread t1{Test};
  std::thread t2{Test};
  t1.join();
  t2.join();
  std::cout << "g_num = " << g_num << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <mutex>
#include <thread>

unsigned g_num{0};
std::mutex g_mutex1{};
std::mutex g_mutex2{};

void Test() {
  for (unsigned i = 0; i < 1e5; ++i) {
    std::scoped_lock lock{g_mutex1, g_mutex2};
    ++g_num;
  }
}

int main() {
  std::thread t{Test};
  for (unsigned i = 0; i < 1e5; ++i) {
    std::scoped_lock lock{g_mutex1, g_mutex2};
    ++g_num;
  }
  t.join();
  std::cout << "g_num = " << g_num << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <string>
#include <thread>

void PrintStr(const std::string& str) {
  for (size_t i = 0; i < 1e6; ++i) {
    std::cout << i;
  }
  std::cout << str << std::endl;
}

int main() {
  std::thread t{PrintStr, "Hello, World!"};
  bool is_joinable = t.joinable();
  if (is_joinable) {
    t.join();
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <thread>

void Foo(int& x) {
  x += 1;
}

int main() {
  int num{1};
  std::thread t{Foo, std::ref(num)};
  t.join();
  std::cout << num << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <thread>

void ThreadFunction() {
  std::cout << "Child thread: " << std::this_thread::get_id() << std::endl;
}

int main() {
  std::thread t{ThreadFunction};
  std::cout << "Main thread: " << std::this_thread::get_id() << std::endl;
  t.join();
  return 0;
}
#endif

#if false
#include <cstddef>
#include <iostream>
#include <mutex>
#include <thread>

int g_count{0};
std::mutex g_mutex{};

void Test() {
  for (size_t i = 0; i < 136; ++i) {
    std::scoped_lock lock{g_mutex};
    ++g_count;
  }
}

int main() {
  std::thread t1{Test};
  std::thread t2{Test};
  t1.join();
  t2.join();
  std::cout << "g_count = " << g_count << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <mutex>

std::mutex g_mutex1{};
std::mutex g_mutex2{};

void Test() {
  std::scoped_lock lock{g_mutex1, g_mutex2};

}
#endif

#if false
#include <iostream>
#include <string>

double Divide(double divisior, double dividend) {
  if (dividend == 0) {
    throw std::runtime_error("Dividend cannot be zero.");
  }
  return divisior / dividend;
}

void InputNum(const std::string& str, double& num) {
  std::cout << str << std::endl;
  while (std::cin >> num, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input. Please try again." << std::endl;
      continue;
    }
    break;
  }
}

int main() {
  double divisior{.0};
  double dividend{.0};
  InputNum("Enter the divisior: ", divisior);
  InputNum("Enter the dividend: ", dividend);
  try {
    double result = Divide(divisior, dividend);
    std::cout << "Result of " << divisior << " / " << dividend << " = "
              << result << std::endl;
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
#endif

#if false
#include <fstream>
#include <iostream>

void OutputFileContent(const std::string& file_name) {
  std::ifstream ifs(file_name);
  std::string file_line_content;
  if (ifs.is_open()) {
    while (std::getline(ifs, file_line_content)) {
      std::cout << file_line_content << std::endl;
    }
    if (ifs.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    ifs.close();
  } else {
    if (ifs.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (ifs.fail()) {
      throw std::runtime_error("File not found.");
    }
  }
}

int main() {
  std::string file_name;
  while (std::cin >> file_name, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    try {
      OutputFileContent(file_name);
    } catch (const std::exception& e) {
      std::cerr << e.what() << std::endl;
    } catch (...) {
      std::cerr << "Unknown exception." << std::endl;
    }
  }
  return 0;
}
#endif

#if false
#include <fstream>
#include <iostream>

int main() {
  try {
    while (true) {
      int* ptr = new int[100000]{};
    }
  } catch (const std::bad_alloc& e) {
    std::cerr << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown exception." << std::endl;
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <stdexcept>
#include <vector>

int main() {
  std::vector<int> vec{1, 2, 3, 4, 5};
  try {
    vec.at(10);
  } catch (const std::out_of_range& e) {
    std::cerr << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown exception." << std::endl;
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <limits>

int main() {
  int i = 10;
  while (std::cin >> i, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cerr << "Invalid input. Please try again." << std::endl;
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
  std::string file_name;
  std::string file_line_content;
  while (std::cin >> file_name, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    std::ifstream ifs(file_name);
    if (ifs.is_open()) {
      while (std::getline(ifs, file_line_content)) {
        std::cout << file_line_content << std::endl;
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
#include <sstream>

int main() {
  std::string str{"12"};
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

#if false
#include <iostream>
#include <thread>

void Test(int value, const int& ref_value, const int* ptr_value) {
  for (unsigned j = 0; j < 1e6; ++j) {
    int k = *ptr_value;
  }
}

int main() {
  int value = 10;
  std::thread t{Test, value, std::ref(value), &value};
  t.detach();
  return 0;
}
#endif

#if false
#include <iostream>
#include <string>
#include <thread>

class Test {
 public:
  Test(int value) {
    std::cout << std::this_thread::get_id() << " Constructor called."
              << std::endl;
  }
};

void TestFunction(const Test& test) {
  std::cout << "Child thread: " << std::this_thread::get_id() << std::endl;
}

int main() {
  std::cout << "Main thread: " << std::this_thread::get_id() << std::endl;
  int value = 100;
  // 使用了隐式转换
  std::thread t{TestFunction, value};
  t.detach();
  return 0;
}
#endif

#if false
#include <iostream>
#include <thread>

int main() {
  std::cout << "Main thread: " << std::this_thread::get_id() << std::endl;
  return 0;
}
#endif

#if false
#include <atomic>
#include <iostream>
#include <thread>

std::atomic<unsigned> g_num{0};

void Test() {
  for (unsigned i = 0; i < 1e5; ++i) {
    ++g_num;
  }
}

int main() {
  std::thread t1{Test};
  std::thread t2{Test};
  t1.join();
  t2.join();
  std::cout << "g_num = " << g_num << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <mutex>
#include <thread>

unsigned g_num{0};
std::mutex g_mutex1{};
std::mutex g_mutex2{};

void Test() {
  for (unsigned i = 0; i < 1e5; ++i) {
    std::scoped_lock lock{g_mutex1, g_mutex2};
    ++g_num;
  }
}

int main() {
  std::thread t{Test};
  for (unsigned i = 0; i < 1e5; ++i) {
    std::scoped_lock lock{g_mutex1, g_mutex2};
    ++g_num;
  }
  t.join();
  std::cout << "g_num = " << g_num << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <string>
#include <thread>

void PrintStr(const std::string& str) {
  for (size_t i = 0; i < 1e6; ++i) {
    std::cout << i;
  }
  std::cout << str << std::endl;
}

int main() {
  std::thread t{PrintStr, "Hello, World!"};
  bool is_joinable = t.joinable();
  if (is_joinable) {
    t.join();
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <thread>

void Foo(int& x) {
  x += 1;
}

int main() {
  int num{1};
  std::thread t{Foo, std::ref(num)};
  t.join();
  std::cout << num << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <thread>

void ThreadFunction() {
  std::cout << "Child thread: " << std::this_thread::get_id() << std::endl;
}

int main() {
  std::thread t{ThreadFunction};
  std::cout << "Main thread: " << std::this_thread::get_id() << std::endl;
  t.join();
  return 0;
}
#endif

#if false
#include <cstddef>
#include <iostream>
#include <mutex>
#include <thread>

int g_count{0};
std::mutex g_mutex{};

void Test() {
  for (size_t i = 0; i < 136; ++i) {
    std::scoped_lock lock{g_mutex};
    ++g_count;
  }
}

int main() {
  std::thread t1{Test};
  std::thread t2{Test};
  t1.join();
  t2.join();
  std::cout << "g_count = " << g_count << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <mutex>

std::mutex g_mutex1{};
std::mutex g_mutex2{};

void Test() {
  std::scoped_lock lock{g_mutex1, g_mutex2};

}
#endif

#if false
#include <iostream>
#include <string>

double Divide(double divisior, double dividend) {
  if (dividend == 0) {
    throw std::runtime_error("Dividend cannot be zero.");
  }
  return divisior / dividend;
}

void InputNum(const std::string& str, double& num) {
  std::cout << str << std::endl;
  while (std::cin >> num, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input. Please try again." << std::endl;
      continue;
    }
    break;
  }
}

int main() {
  double divisior{.0};
  double dividend{.0};
  InputNum("Enter the divisior: ", divisior);
  InputNum("Enter the dividend: ", dividend);
  try {
    double result = Divide(divisior, dividend);
    std::cout << "Result of " << divisior << " / " << dividend << " = "
              << result << std::endl;
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
#endif

#if false
#include <fstream>
#include <iostream>

void OutputFileContent(const std::string& file_name) {
  std::ifstream ifs(file_name);
  std::string file_line_content;
  if (ifs.is_open()) {
    while (std::getline(ifs, file_line_content)) {
      std::cout << file_line_content << std::endl;
    }
    if (ifs.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    ifs.close();
  } else {
    if (ifs.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (ifs.fail()) {
      throw std::runtime_error("File not found.");
    }
  }
}

int main() {
  std::string file_name;
  while (std::cin >> file_name, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    try {
      OutputFileContent(file_name);
    } catch (const std::exception& e) {
      std::cerr << e.what() << std::endl;
    } catch (...) {
      std::cerr << "Unknown exception." << std::endl;
    }
  }
  return 0;
}
#endif

#if false
#include <fstream>
#include <iostream>

int main() {
  try {
    while (true) {
      int* ptr = new int[100000]{};
    }
  } catch (const std::bad_alloc& e) {
    std::cerr << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown exception." << std::endl;
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <stdexcept>
#include <vector>

int main() {
  std::vector<int> vec{1, 2, 3, 4, 5};
  try {
    vec.at(10);
  } catch (const std::out_of_range& e) {
    std::cerr << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown exception." << std::endl;
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <limits>

int main() {
  int i = 10;
  while (std::cin >> i, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cerr << "Invalid input. Please try again." << std::endl;
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
  std::string file_name;
  std::string file_line_content;
  while (std::cin >> file_name, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    std::ifstream ifs(file_name);
    if (ifs.is_open()) {
      while (std::getline(ifs, file_line_content)) {
        std::cout << file_line_content << std::endl;
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
#include <sstream>

int main() {
  std::string str{"12"};
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

#if false
#include <iostream>
#include <thread>

void Test(int value, const int& ref_value, const int* ptr_value) {
  for (unsigned j = 0; j < 1e6; ++j) {
    int k = *ptr_value;
  }
}

int main() {
  int value = 10;
  std::thread t{Test, value, std::ref(value), &value};
  t.detach();
  return 0;
}
#endif

#if false
#include <iostream>
#include <string>
#include <thread>

class Test {
 public:
  Test(int value) {
    std::cout << std::this_thread::get_id() << " Constructor called."
              << std::endl;
  }
};

void TestFunction(const Test& test) {
  std::cout << "Child thread: " << std::this_thread::get_id() << std::endl;
}

int main() {
  std::cout << "Main thread: " << std::this_thread::get_id() << std::endl;
  int value = 100;
  // 使用了隐式转换
  std::thread t{TestFunction, value};
  t.detach();
  return 0;
}
#endif

#if false
#include <iostream>
#include <thread>

int main() {
  std::cout << "Main thread: " << std::this_thread::get_id() << std::endl;
  return 0;
}
#endif

#if false
#include <atomic>
#include <iostream>
#include <thread>

std::atomic<unsigned> g_num{0};

void Test() {
  for (unsigned i = 0; i < 1e5; ++i) {
    ++g_num;
  }
}

int main() {
  std::thread t1{Test};
  std::thread t2{Test};
  t1.join();
  t2.join();
  std::cout << "g_num = " << g_num << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <mutex>
#include <thread>

unsigned g_num{0};
std::mutex g_mutex1{};
std::mutex g_mutex2{};

void Test() {
  for (unsigned i = 0; i < 1e5; ++i) {
    std::scoped_lock lock{g_mutex1, g_mutex2};
    ++g_num;
  }
}

int main() {
  std::thread t{Test};
  for (unsigned i = 0; i < 1e5; ++i) {
    std::scoped_lock lock{g_mutex1, g_mutex2};
    ++g_num;
  }
  t.join();
  std::cout << "g_num = " << g_num << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <string>
#include <thread>

void PrintStr(const std::string& str) {
  for (size_t i = 0; i < 1e6; ++i) {
    std::cout << i;
  }
  std::cout << str << std::endl;
}

int main() {
  std::thread t{PrintStr, "Hello, World!"};
  bool is_joinable = t.joinable();
  if (is_joinable) {
    t.join();
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <thread>

void Foo(int& x) {
  x += 1;
}

int main() {
  int num{1};
  std::thread t{Foo, std::ref(num)};
  t.join();
  std::cout << num << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <thread>

void ThreadFunction() {
  std::cout << "Child thread: " << std::this_thread::get_id() << std::endl;
}

int main() {
  std::thread t{ThreadFunction};
  std::cout << "Main thread: " << std::this_thread::get_id() << std::endl;
  t.join();
  return 0;
}
#endif

#if false
#include <cstddef>
#include <iostream>
#include <mutex>
#include <thread>

int g_count{0};
std::mutex g_mutex{};

void Test() {
  for (size_t i = 0; i < 136; ++i) {
    std::scoped_lock lock{g_mutex};
    ++g_count;
  }
}

int main() {
  std::thread t1{Test};
  std::thread t2{Test};
  t1.join();
  t2.join();
  std::cout << "g_count = " << g_count << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <mutex>

std::mutex g_mutex1{};
std::mutex g_mutex2{};

void Test() {
  std::scoped_lock lock{g_mutex1, g_mutex2};

}
#endif

#if false
#include <iostream>
#include <string>

double Divide(double divisior, double dividend) {
  if (dividend == 0) {
    throw std::runtime_error("Dividend cannot be zero.");
  }
  return divisior / dividend;
}

void InputNum(const std::string& str, double& num) {
  std::cout << str << std::endl;
  while (std::cin >> num, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input. Please try again." << std::endl;
      continue;
    }
    break;
  }
}

int main() {
  double divisior{.0};
  double dividend{.0};
  InputNum("Enter the divisior: ", divisior);
  InputNum("Enter the dividend: ", dividend);
  try {
    double result = Divide(divisior, dividend);
    std::cout << "Result of " << divisior << " / " << dividend << " = "
              << result << std::endl;
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
#endif

#if false
#include <fstream>
#include <iostream>

void OutputFileContent(const std::string& file_name) {
  std::ifstream ifs(file_name);
  std::string file_line_content;
  if (ifs.is_open()) {
    while (std::getline(ifs, file_line_content)) {
      std::cout << file_line_content << std::endl;
    }
    if (ifs.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    ifs.close();
  } else {
    if (ifs.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (ifs.fail()) {
      throw std::runtime_error("File not found.");
    }
  }
}

int main() {
  std::string file_name;
  while (std::cin >> file_name, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    try {
      OutputFileContent(file_name);
    } catch (const std::exception& e) {
      std::cerr << e.what() << std::endl;
    } catch (...) {
      std::cerr << "Unknown exception." << std::endl;
    }
  }
  return 0;
}
#endif

#if false
#include <fstream>
#include <iostream>

int main() {
  try {
    while (true) {
      int* ptr = new int[100000]{};
    }
  } catch (const std::bad_alloc& e) {
    std::cerr << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown exception." << std::endl;
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <stdexcept>
#include <vector>

int main() {
  std::vector<int> vec{1, 2, 3, 4, 5};
  try {
    vec.at(10);
  } catch (const std::out_of_range& e) {
    std::cerr << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown exception." << std::endl;
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <limits>

int main() {
  int i = 10;
  while (std::cin >> i, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cerr << "Invalid input. Please try again." << std::endl;
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
  std::string file_name;
  std::string file_line_content;
  while (std::cin >> file_name, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    std::ifstream ifs(file_name);
    if (ifs.is_open()) {
      while (std::getline(ifs, file_line_content)) {
        std::cout << file_line_content << std::endl;
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
#include <sstream>

int main() {
  std::string str{"12"};
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

#if false
#include <iostream>
#include <thread>

void Test(int value, const int& ref_value, const int* ptr_value) {
  for (unsigned j = 0; j < 1e6; ++j) {
    int k = *ptr_value;
  }
}

int main() {
  int value = 10;
  std::thread t{Test, value, std::ref(value), &value};
  t.detach();
  return 0;
}
#endif

#if false
#include <iostream>
#include <string>
#include <thread>

class Test {
 public:
  Test(int value) {
    std::cout << std::this_thread::get_id() << " Constructor called."
              << std::endl;
  }
};

void TestFunction(const Test& test) {
  std::cout << "Child thread: " << std::this_thread::get_id() << std::endl;
}

int main() {
  std::cout << "Main thread: " << std::this_thread::get_id() << std::endl;
  int value = 100;
  // 使用了隐式转换
  std::thread t{TestFunction, value};
  t.detach();
  return 0;
}
#endif

#if false
#include <iostream>
#include <thread>

int main() {
  std::cout << "Main thread: " << std::this_thread::get_id() << std::endl;
  return 0;
}
#endif

#if false
#include <atomic>
#include <iostream>
#include <thread>

std::atomic<unsigned> g_num{0};

void Test() {
  for (unsigned i = 0; i < 1e5; ++i) {
    ++g_num;
  }
}

int main() {
  std::thread t1{Test};
  std::thread t2{Test};
  t1.join();
  t2.join();
  std::cout << "g_num = " << g_num << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <mutex>
#include <thread>

unsigned g_num{0};
std::mutex g_mutex1{};
std::mutex g_mutex2{};

void Test() {
  for (unsigned i = 0; i < 1e5; ++i) {
    std::scoped_lock lock{g_mutex1, g_mutex2};
    ++g_num;
  }
}

int main() {
  std::thread t{Test};
  for (unsigned i = 0; i < 1e5; ++i) {
    std::scoped_lock lock{g_mutex1, g_mutex2};
    ++g_num;
  }
  t.join();
  std::cout << "g_num = " << g_num << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <string>
#include <thread>

void PrintStr(const std::string& str) {
  for (size_t i = 0; i < 1e6; ++i) {
    std::cout << i;
  }
  std::cout << str << std::endl;
}

int main() {
  std::thread t{PrintStr, "Hello, World!"};
  bool is_joinable = t.joinable();
  if (is_joinable) {
    t.join();
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <thread>

void Foo(int& x) {
  x += 1;
}

int main() {
  int num{1};
  std::thread t{Foo, std::ref(num)};
  t.join();
  std::cout << num << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <thread>

void ThreadFunction() {
  std::cout << "Child thread: " << std::this_thread::get_id() << std::endl;
}

int main() {
  std::thread t{ThreadFunction};
  std::cout << "Main thread: " << std::this_thread::get_id() << std::endl;
  t.join();
  return 0;
}
#endif

#if false
#include <cstddef>
#include <iostream>
#include <mutex>
#include <thread>

int g_count{0};
std::mutex g_mutex{};

void Test() {
  for (size_t i = 0; i < 136; ++i) {
    std::scoped_lock lock{g_mutex};
    ++g_count;
  }
}

int main() {
  std::thread t1{Test};
  std::thread t2{Test};
  t1.join();
  t2.join();
  std::cout << "g_count = " << g_count << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <mutex>

std::mutex g_mutex1{};
std::mutex g_mutex2{};

void Test() {
  std::scoped_lock lock{g_mutex1, g_mutex2};

}
#endif

#if false
#include <iostream>
#include <string>

double Divide(double divisior, double dividend) {
  if (dividend == 0) {
    throw std::runtime_error("Dividend cannot be zero.");
  }
  return divisior / dividend;
}

void InputNum(const std::string& str, double& num) {
  std::cout << str << std::endl;
  while (std::cin >> num, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input. Please try again." << std::endl;
      continue;
    }
    break;
  }
}

int main() {
  double divisior{.0};
  double dividend{.0};
  InputNum("Enter the divisior: ", divisior);
  InputNum("Enter the dividend: ", dividend);
  try {
    double result = Divide(divisior, dividend);
    std::cout << "Result of " << divisior << " / " << dividend << " = "
              << result << std::endl;
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
#endif

#if false
#include <fstream>
#include <iostream>

void OutputFileContent(const std::string& file_name) {
  std::ifstream ifs(file_name);
  std::string file_line_content;
  if (ifs.is_open()) {
    while (std::getline(ifs, file_line_content)) {
      std::cout << file_line_content << std::endl;
    }
    if (ifs.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    ifs.close();
  } else {
    if (ifs.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (ifs.fail()) {
      throw std::runtime_error("File not found.");
    }
  }
}

int main() {
  std::string file_name;
  while (std::cin >> file_name, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    try {
      OutputFileContent(file_name);
    } catch (const std::exception& e) {
      std::cerr << e.what() << std::endl;
    } catch (...) {
      std::cerr << "Unknown exception." << std::endl;
    }
  }
  return 0;
}
#endif

#if false
#include <fstream>
#include <iostream>

int main() {
  try {
    while (true) {
      int* ptr = new int[100000]{};
    }
  } catch (const std::bad_alloc& e) {
    std::cerr << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown exception." << std::endl;
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <stdexcept>
#include <vector>

int main() {
  std::vector<int> vec{1, 2, 3, 4, 5};
  try {
    vec.at(10);
  } catch (const std::out_of_range& e) {
    std::cerr << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown exception." << std::endl;
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <limits>

int main() {
  int i = 10;
  while (std::cin >> i, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cerr << "Invalid input. Please try again." << std::endl;
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
  std::string file_name;
  std::string file_line_content;
  while (std::cin >> file_name, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    std::ifstream ifs(file_name);
    if (ifs.is_open()) {
      while (std::getline(ifs, file_line_content)) {
        std::cout << file_line_content << std::endl;
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
#include <sstream>

int main() {
  std::string str{"12"};
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

#if false
#include <iostream>
#include <thread>

void Test(int value, const int& ref_value, const int* ptr_value) {
  for (unsigned j = 0; j < 1e6; ++j) {
    int k = *ptr_value;
  }
}

int main() {
  int value = 10;
  std::thread t{Test, value, std::ref(value), &value};
  t.detach();
  return 0;
}
#endif

#if false
#include <iostream>
#include <string>
#include <thread>

class Test {
 public:
  Test(int value) {
    std::cout << std::this_thread::get_id() << " Constructor called."
              << std::endl;
  }
};

void TestFunction(const Test& test) {
  std::cout << "Child thread: " << std::this_thread::get_id() << std::endl;
}

int main() {
  std::cout << "Main thread: " << std::this_thread::get_id() << std::endl;
  int value = 100;
  // 使用了隐式转换
  std::thread t{TestFunction, value};
  t.detach();
  return 0;
}
#endif

#if false
#include <iostream>
#include <thread>

int main() {
  std::cout << "Main thread: " << std::this_thread::get_id() << std::endl;
  return 0;
}
#endif

#if false
#include <atomic>
#include <iostream>
#include <thread>

std::atomic<unsigned> g_num{0};

void Test() {
  for (unsigned i = 0; i < 1e5; ++i) {
    ++g_num;
  }
}

int main() {
  std::thread t1{Test};
  std::thread t2{Test};
  t1.join();
  t2.join();
  std::cout << "g_num = " << g_num << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <mutex>
#include <thread>

unsigned g_num{0};
std::mutex g_mutex1{};
std::mutex g_mutex2{};

void Test() {
  for (unsigned i = 0; i < 1e5; ++i) {
    std::scoped_lock lock{g_mutex1, g_mutex2};
    ++g_num;
  }
}

int main() {
  std::thread t{Test};
  for (unsigned i = 0; i < 1e5; ++i) {
    std::scoped_lock lock{g_mutex1, g_mutex2};
    ++g_num;
  }
  t.join();
  std::cout << "g_num = " << g_num << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <string>
#include <thread>

void PrintStr(const std::string& str) {
  for (size_t i = 0; i < 1e6; ++i) {
    std::cout << i;
  }
  std::cout << str << std::endl;
}

int main() {
  std::thread t{PrintStr, "Hello, World!"};
  bool is_joinable = t.joinable();
  if (is_joinable) {
    t.join();
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <thread>

void Foo(int& x) {
  x += 1;
}

int main() {
  int num{1};
  std::thread t{Foo, std::ref(num)};
  t.join();
  std::cout << num << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <thread>

void ThreadFunction() {
  std::cout << "Child thread: " << std::this_thread::get_id() << std::endl;
}

int main() {
  std::thread t{ThreadFunction};
  std::cout << "Main thread: " << std::this_thread::get_id() << std::endl;
  t.join();
  return 0;
}
#endif

#if false
#include <cstddef>
#include <iostream>
#include <mutex>
#include <thread>

int g_count{0};
std::mutex g_mutex{};

void Test() {
  for (size_t i = 0; i < 136; ++i) {
    std::scoped_lock lock{g_mutex};
    ++g_count;
  }
}

int main() {
  std::thread t1{Test};
  std::thread t2{Test};
  t1.join();
  t2.join();
  std::cout << "g_count = " << g_count << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <mutex>

std::mutex g_mutex1{};
std::mutex g_mutex2{};

void Test() {
  std::scoped_lock lock{g_mutex1, g_mutex2};

}
#endif

#if false
#include <iostream>
#include <string>

double Divide(double divisior, double dividend) {
  if (dividend == 0) {
    throw std::runtime_error("Dividend cannot be zero.");
  }
  return divisior / dividend;
}

void InputNum(const std::string& str, double& num) {
  std::cout << str << std::endl;
  while (std::cin >> num, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input. Please try again." << std::endl;
      continue;
    }
    break;
  }
}

int main() {
  double divisior{.0};
  double dividend{.0};
  InputNum("Enter the divisior: ", divisior);
  InputNum("Enter the dividend: ", dividend);
  try {
    double result = Divide(divisior, dividend);
    std::cout << "Result of " << divisior << " / " << dividend << " = "
              << result << std::endl;
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
#endif

#if false
#include <fstream>
#include <iostream>

void OutputFileContent(const std::string& file_name) {
  std::ifstream ifs(file_name);
  std::string file_line_content;
  if (ifs.is_open()) {
    while (std::getline(ifs, file_line_content)) {
      std::cout << file_line_content << std::endl;
    }
    if (ifs.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    ifs.close();
  } else {
    if (ifs.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (ifs.fail()) {
      throw std::runtime_error("File not found.");
    }
  }
}

int main() {
  std::string file_name;
  while (std::cin >> file_name, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    try {
      OutputFileContent(file_name);
    } catch (const std::exception& e) {
      std::cerr << e.what() << std::endl;
    } catch (...) {
      std::cerr << "Unknown exception." << std::endl;
    }
  }
  return 0;
}
#endif

#if false
#include <fstream>
#include <iostream>

int main() {
  try {
    while (true) {
      int* ptr = new int[100000]{};
    }
  } catch (const std::bad_alloc& e) {
    std::cerr << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown exception." << std::endl;
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <stdexcept>
#include <vector>

int main() {
  std::vector<int> vec{1, 2, 3, 4, 5};
  try {
    vec.at(10);
  } catch (const std::out_of_range& e) {
    std::cerr << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown exception." << std::endl;
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <limits>

int main() {
  int i = 10;
  while (std::cin >> i, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cerr << "Invalid input. Please try again." << std::endl;
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
  std::string file_name;
  std::string file_line_content;
  while (std::cin >> file_name, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    std::ifstream ifs(file_name);
    if (ifs.is_open()) {
      while (std::getline(ifs, file_line_content)) {
        std::cout << file_line_content << std::endl;
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
#include <sstream>

int main() {
  std::string str{"12"};
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

#if false
#include <iostream>
#include <thread>

void Test(int value, const int& ref_value, const int* ptr_value) {
  for (unsigned j = 0; j < 1e6; ++j) {
    int k = *ptr_value;
  }
}

int main() {
  int value = 10;
  std::thread t{Test, value, std::ref(value), &value};
  t.detach();
  return 0;
}
#endif

#if false
#include <iostream>
#include <string>
#include <thread>

class Test {
 public:
  Test(int value) {
    std::cout << std::this_thread::get_id() << " Constructor called."
              << std::endl;
  }
};

void TestFunction(const Test& test) {
  std::cout << "Child thread: " << std::this_thread::get_id() << std::endl;
}

int main() {
  std::cout << "Main thread: " << std::this_thread::get_id() << std::endl;
  int value = 100;
  // 使用了隐式转换
  std::thread t{TestFunction, value};
  t.detach();
  return 0;
}
#endif

#if false
#include <iostream>
#include <thread>

int main() {
  std::cout << "Main thread: " << std::this_thread::get_id() << std::endl;
  return 0;
}
#endif

#if false
#include <atomic>
#include <iostream>
#include <thread>

std::atomic<unsigned> g_num{0};

void Test() {
  for (unsigned i = 0; i < 1e5; ++i) {
    ++g_num;
  }
}

int main() {
  std::thread t1{Test};
  std::thread t2{Test};
  t1.join();
  t2.join();
  std::cout << "g_num = " << g_num << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <mutex>
#include <thread>

unsigned g_num{0};
std::mutex g_mutex1{};
std::mutex g_mutex2{};

void Test() {
  for (unsigned i = 0; i < 1e5; ++i) {
    std::scoped_lock lock{g_mutex1, g_mutex2};
    ++g_num;
  }
}

int main() {
  std::thread t{Test};
  for (unsigned i = 0; i < 1e5; ++i) {
    std::scoped_lock lock{g_mutex1, g_mutex2};
    ++g_num;
  }
  t.join();
  std::cout << "g_num = " << g_num << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <string>
#include <thread>

void PrintStr(const std::string& str) {
  for (size_t i = 0; i < 1e6; ++i) {
    std::cout << i;
  }
  std::cout << str << std::endl;
}

int main() {
  std::thread t{PrintStr, "Hello, World!"};
  bool is_joinable = t.joinable();
  if (is_joinable) {
    t.join();
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <thread>

void Foo(int& x) {
  x += 1;
}

int main() {
  int num{1};
  std::thread t{Foo, std::ref(num)};
  t.join();
  std::cout << num << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <thread>

void ThreadFunction() {
  std::cout << "Child thread: " << std::this_thread::get_id() << std::endl;
}

int main() {
  std::thread t{ThreadFunction};
  std::cout << "Main thread: " << std::this_thread::get_id() << std::endl;
  t.join();
  return 0;
}
#endif

#if false
#include <cstddef>
#include <iostream>
#include <mutex>
#include <thread>

int g_count{0};
std::mutex g_mutex{};

void Test() {
  for (size_t i = 0; i < 136; ++i) {
    std::scoped_lock lock{g_mutex};
    ++g_count;
  }
}

int main() {
  std::thread t1{Test};
  std::thread t2{Test};
  t1.join();
  t2.join();
  std::cout << "g_count = " << g_count << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <mutex>

std::mutex g_mutex1{};
std::mutex g_mutex2{};

void Test() {
  std::scoped_lock lock{g_mutex1, g_mutex2};

}
#endif

#if false
#include <iostream>
#include <string>

double Divide(double divisior, double dividend) {
  if (dividend == 0) {
    throw std::runtime_error("Dividend cannot be zero.");
  }
  return divisior / dividend;
}

void InputNum(const std::string& str, double& num) {
  std::cout << str << std::endl;
  while (std::cin >> num, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input. Please try again." << std::endl;
      continue;
    }
    break;
  }
}

int main() {
  double divisior{.0};
  double dividend{.0};
  InputNum("Enter the divisior: ", divisior);
  InputNum("Enter the dividend: ", dividend);
  try {
    double result = Divide(divisior, dividend);
    std::cout << "Result of " << divisior << " / " << dividend << " = "
              << result << std::endl;
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
#endif

#if false
#include <fstream>
#include <iostream>

void OutputFileContent(const std::string& file_name) {
  std::ifstream ifs(file_name);
  std::string file_line_content;
  if (ifs.is_open()) {
    while (std::getline(ifs, file_line_content)) {
      std::cout << file_line_content << std::endl;
    }
    if (ifs.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    ifs.close();
  } else {
    if (ifs.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (ifs.fail()) {
      throw std::runtime_error("File not found.");
    }
  }
}

int main() {
  std::string file_name;
  while (std::cin >> file_name, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    try {
      OutputFileContent(file_name);
    } catch (const std::exception& e) {
      std::cerr << e.what() << std::endl;
    } catch (...) {
      std::cerr << "Unknown exception." << std::endl;
    }
  }
  return 0;
}
#endif

#if false
#include <fstream>
#include <iostream>

int main() {
  try {
    while (true) {
      int* ptr = new int[100000]{};
    }
  } catch (const std::bad_alloc& e) {
    std::cerr << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown exception." << std::endl;
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <stdexcept>
#include <vector>

int main() {
  std::vector<int> vec{1, 2, 3, 4, 5};
  try {
    vec.at(10);
  } catch (const std::out_of_range& e) {
    std::cerr << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown exception." << std::endl;
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <limits>

int main() {
  int i = 10;
  while (std::cin >> i, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cerr << "Invalid input. Please try again." << std::endl;
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
  std::string file_name;
  std::string file_line_content;
  while (std::cin >> file_name, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    std::ifstream ifs(file_name);
    if (ifs.is_open()) {
      while (std::getline(ifs, file_line_content)) {
        std::cout << file_line_content << std::endl;
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
#include <sstream>

int main() {
  std::string str{"12"};
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

#if false
#include <iostream>
#include <thread>

void Test(int value, const int& ref_value, const int* ptr_value) {
  for (unsigned j = 0; j < 1e6; ++j) {
    int k = *ptr_value;
  }
}

int main() {
  int value = 10;
  std::thread t{Test, value, std::ref(value), &value};
  t.detach();
  return 0;
}
#endif

#if false
#include <iostream>
#include <string>
#include <thread>

class Test {
 public:
  Test(int value) {
    std::cout << std::this_thread::get_id() << " Constructor called."
              << std::endl;
  }
};

void TestFunction(const Test& test) {
  std::cout << "Child thread: " << std::this_thread::get_id() << std::endl;
}

int main() {
  std::cout << "Main thread: " << std::this_thread::get_id() << std::endl;
  int value = 100;
  // 使用了隐式转换
  std::thread t{TestFunction, value};
  t.detach();
  return 0;
}
#endif

#if false
#include <iostream>
#include <thread>

int main() {
  std::cout << "Main thread: " << std::this_thread::get_id() << std::endl;
  return 0;
}
#endif

#if false
#include <atomic>
#include <iostream>
#include <thread>

std::atomic<unsigned> g_num{0};

void Test() {
  for (unsigned i = 0; i < 1e5; ++i) {
    ++g_num;
  }
}

int main() {
  std::thread t1{Test};
  std::thread t2{Test};
  t1.join();
  t2.join();
  std::cout << "g_num = " << g_num << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <mutex>
#include <thread>

unsigned g_num{0};
std::mutex g_mutex1{};
std::mutex g_mutex2{};

void Test() {
  for (unsigned i = 0; i < 1e5; ++i) {
    std::scoped_lock lock{g_mutex1, g_mutex2};
    ++g_num;
  }
}

int main() {
  std::thread t{Test};
  for (unsigned i = 0; i < 1e5; ++i) {
    std::scoped_lock lock{g_mutex1, g_mutex2};
    ++g_num;
  }
  t.join();
  std::cout << "g_num = " << g_num << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <string>
#include <thread>

void PrintStr(const std::string& str) {
  for (size_t i = 0; i < 1e6; ++i) {
    std::cout << i;
  }
  std::cout << str << std::endl;
}

int main() {
  std::thread t{PrintStr, "Hello, World!"};
  bool is_joinable = t.joinable();
  if (is_joinable) {
    t.join();
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <thread>

void Foo(int& x) {
  x += 1;
}

int main() {
  int num{1};
  std::thread t{Foo, std::ref(num)};
  t.join();
  std::cout << num << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <thread>

void ThreadFunction() {
  std::cout << "Child thread: " << std::this_thread::get_id() << std::endl;
}

int main() {
  std::thread t{ThreadFunction};
  std::cout << "Main thread: " << std::this_thread::get_id() << std::endl;
  t.join();
  return 0;
}
#endif

#if false
#include <cstddef>
#include <iostream>
#include <mutex>
#include <thread>

int g_count{0};
std::mutex g_mutex{};

void Test() {
  for (size_t i = 0; i < 136; ++i) {
    std::scoped_lock lock{g_mutex};
    ++g_count;
  }
}

int main() {
  std::thread t1{Test};
  std::thread t2{Test};
  t1.join();
  t2.join();
  std::cout << "g_count = " << g_count << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <mutex>

std::mutex g_mutex1{};
std::mutex g_mutex2{};

void Test() {
  std::scoped_lock lock{g_mutex1, g_mutex2};

}
#endif

#if false
#include <iostream>
#include <string>

double Divide(double divisior, double dividend) {
  if (dividend == 0) {
    throw std::runtime_error("Dividend cannot be zero.");
  }
  return divisior / dividend;
}

void InputNum(const std::string& str, double& num) {
  std::cout << str << std::endl;
  while (std::cin >> num, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input. Please try again." << std::endl;
      continue;
    }
    break;
  }
}

int main() {
  double divisior{.0};
  double dividend{.0};
  InputNum("Enter the divisior: ", divisior);
  InputNum("Enter the dividend: ", dividend);
  try {
    double result = Divide(divisior, dividend);
    std::cout << "Result of " << divisior << " / " << dividend << " = "
              << result << std::endl;
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
#endif

#if false
#include <fstream>
#include <iostream>

void OutputFileContent(const std::string& file_name) {
  std::ifstream ifs(file_name);
  std::string file_line_content;
  if (ifs.is_open()) {
    while (std::getline(ifs, file_line_content)) {
      std::cout << file_line_content << std::endl;
    }
    if (ifs.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    ifs.close();
  } else {
    if (ifs.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (ifs.fail()) {
      throw std::runtime_error("File not found.");
    }
  }
}

int main() {
  std::string file_name;
  while (std::cin >> file_name, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    try {
      OutputFileContent(file_name);
    } catch (const std::exception& e) {
      std::cerr << e.what() << std::endl;
    } catch (...) {
      std::cerr << "Unknown exception." << std::endl;
    }
  }
  return 0;
}
#endif

#if false
#include <fstream>
#include <iostream>

int main() {
  try {
    while (true) {
      int* ptr = new int[100000]{};
    }
  } catch (const std::bad_alloc& e) {
    std::cerr << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown exception." << std::endl;
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <stdexcept>
#include <vector>

int main() {
  std::vector<int> vec{1, 2, 3, 4, 5};
  try {
    vec.at(10);
  } catch (const std::out_of_range& e) {
    std::cerr << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown exception." << std::endl;
  }
  return 0;
}
#endif

#if false
#include <iostream>
#include <limits>

int main() {
  int i = 10;
  while (std::cin >> i, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cerr << "Invalid input. Please try again." << std::endl;
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
  std::string file_name;
  std::string file_line_content;
  while (std::cin >> file_name, !std::cin.eof()) {
    if (std::cin.bad()) {
      throw std::runtime_error("IO stream corrupted.");
    }
    std::ifstream ifs(file_name);
    if (ifs.is_open()) {
      while (std::getline(ifs, file_line_content)) {
        std::cout << file_line_content << std::endl;
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
#include <print>
#include <string>

int main() {
  // 基本类型打印
  std::print("Hello, {}!\n", "World");

  // 多个参数打印
  int age = 25;
  std::string name = "Alice";
  std::print("{} is {} years old\n", name, age);

  // 浮点数打印
  double pi = 3.14159;
  std::print("Pi is approximately {:.2f}\n", pi);

  // 使用位置参数
  std::print("{1} comes before {0}\n", "world", "hello");

  return 0;
}
#endif

#if false
#include <cstring>

class Test {
 public:
  Test() = default;

  Test(const Test& test) {
    if (test.str_) {
      str_ = new char[std::strlen(test.str_) + 1];
      std::strcpy(str_, test.str_);
    } else {
      str_ = nullptr;
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
      if (test.str_) {
        str_ = new char[std::strlen(test.str_) + 1];
        std::strcpy(str_, test.str_);
      }
    }
    return *this;
  }

  Test& operator=(Test&& test) {
    if (this != &test) {
      delete[] str_;
      str_ = nullptr;
      if (test.str_) {
        str_ = test.str_;
        test.str_ = nullptr;
      }
    }
    return *this;
  }

 private:
  char* str_;
};
#endif

#if false
#include <iostream>
#include <unordered_map>
#include <unordered_set>

int main() {
  std::unordered_map<int, std::string> umap;
  umap.emplace(1, "one");
  umap.emplace(2, "two");
  umap.emplace(3, "three");
  for (const auto& pair : umap) {
    std::cout << pair.first << " -> " << pair.second << std::endl;
  }
  std::unordered_multimap<int, std::string>
}
#endif

#if false
#include <iostream>
#include <vector>

int main() {
  std::vector<int> v1, v2, v3;
  v1.push_back(10);
  v1.push_back(20);
  v1.push_back(30);
  v1.push_back(40);
  v1.push_back(50);

  std::cout << "v1 = ";
  for (const auto& v : v1) {
    std::cout << v << ' ';
  }
  std::cout << std::endl;

  v2.assign(v1.begin(), v1.end());
  std::cout << "v2 = ";
  for (const auto& v : v2) {
    std::cout << v << ' ';
  }
  std::cout << std::endl;

  v3.assign(7, 4);
  std::cout << "v3 = ";
  for (const auto& v : v3) {
    std::cout << v << ' ';
  }
  std::cout << std::endl;

  v3.assign({5, 6, 7});
  std::cout << "v3 = ";
  for (const auto& v : v3) {
    std::cout << v << ' ';
  }
  std::cout << std::endl;

  return 0;
}
#endif

#if false
#include <cstdlib>
#include <iostream>
#include <vector>

std::vector<int*> g_vec;

int Test() {
  int* ptr = new int(rand());
  g_vec.push_back(ptr);
  static unsigned func_call_count{0};
  return ++func_call_count;
}

int main() {
  Test();
  Test();
  Test();
  unsigned test_count = Test();
  std::print("{}\n", test_count);
  return 0;
}
#endif

#if false
#include <iostream>
#include <string>

int main() {
  auto str_ptr = new std::string("Hello, World!");
  std::cout << *str_ptr << std::endl;
  auto arr = new int[100]{};
  std::cout << arr[20] << std::endl;
  delete[] arr;
  delete str_ptr;
  return 0;
}
#endif

#if false
#include <boost/type_index.hpp>
#include <iostream>

int main() {
  auto num = 100;
  const int& num_ref = num;
  auto num2 = num_ref;
  std::cout << boost::typeindex::type_id_with_cvr<decltype(num2)>()
            << std::endl;
  return 0;
}
#endif

#if false
#include <functional>
#include <iostream>

void Test(std::function<void(int)> func, int num) {
  func(num);
}

int main() {
  int num{10};
  Test([](int num) -> void { std::cout << "num = " << num << std::endl; }, 100);
  return 0;
}
#endif

#if false
#include <boost/type_index.hpp>
#include <iostream>

template <typename Container>
auto GetValue(Container& container) -> decltype(container.front()) {
  return container.front();
}

template <typename T, typename U>
auto Add(T t, U u) -> decltype(t + u) {
  return t + u;
}

int main() {
  auto lambda = [](int x) {
    return x * 2;
  };
  decltype(lambda) lambda2 = lambda;
  return 0;
}
#endif

#if false
#include <iostream>

class Test {
 public:
  Test() : output_call_count_{0} {}

  void Output() const {
    std::cout << "Output called." << std::endl;
    ++output_call_count_;
  }

  unsigned output_call_count() const { return output_call_count_; }

 private:
  mutable unsigned output_call_count_;
};

int main() {
  Test test;
  test.Output();
  test.Output();
  test.Output();
  std::cout << "Output call count: " << test.output_call_count() << std::endl;
  return 0;
}
#endif

#if false
#include <iostream>
#include <string>

class Test {
 public:
  friend void Output(const Test&);
  Test(std::string name, unsigned age) : name_{name}, age_{age} {}
  Test() = default;
  Test(const Test&) = default;
  Test& operator=(const Test&) = default;
  ~Test() = default;

 private:
  std::string name_;
  unsigned age_;
};

void Output(const Test& test) {
  std::cout << test.name_ << ", " << test.age_ << std::endl;
}

int main() {
  Test test{"Alice", 25};
  Output(test);
  return 0;
}
#endif

#if false
#include <iostream>
#include <string>

class Spear {
 public:
  Spear(const std::string& name, const std::string& icon)
      : name_{name}, icon_{icon} {
    std::cout << "Spear" << std::endl;
  }
  virtual ~Spear() = default;
  virtual void OpenFire() const { std::cout << "Open fire." << std::endl; }

 private:
  std::string name_;
  std::string icon_;
};

class FireSpear : public Spear {
 public:
  FireSpear(const std::string& name, const std::string& icon, int fire)
      : Spear{name, icon}, fire_{fire} {
    std::cout << "FireSpear" << std::endl;
  }
  virtual ~FireSpear() = default;
  virtual void OpenFire() const override {
    std::cout << "Open fire with fire power: " << fire_ << std::endl;
  }

 private:
  int fire_;
};

class IceSpear : public Spear {
 public:
  IceSpear(const std::string& name, const std::string& icon, int ice)
      : Spear{name, icon}, ice_{ice} {
    std::cout << "IceSpear" << std::endl;
  }
  virtual ~IceSpear() = default;
  virtual void OpenFire() const override {
    std::cout << "Open fire with ice power: " << ice_ << std::endl;
  }

 private:
  int ice_;
};

void OpenFire(const Spear& spear) {
  spear.OpenFire();
}

int main() {
  Spear* spear_ptr = new FireSpear{"Fire Spear", "Fire", 100};
  std::string type_name = typeid(*spear_ptr).name();
  if (type_name == "class FireSpear" || "9FireSpear") {
    FireSpear* fire_spear_ptr = dynamic_cast<FireSpear*>(spear_ptr);
    if (fire_spear_ptr) {
      fire_spear_ptr->OpenFire();
    }
  }
  return 0;
}
#endif

#if false
#include <iostream>

class Base {
 public:
  virtual ~Base() = default;
};

class Derived : public Base {};

int main() {
  Base* basePtr = new Derived();
  Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);

  if (derivedPtr) {
    std::cout << "Conversion successful!" << std::endl;
  } else {
    std::cout << "Conversion failed!" << std::endl;
  }

  delete basePtr;
  return 0;
}
#endif

#if false
// 基本数据类型转换
int a = 10;
double b = static_cast<double>(a);

// 类层次结构中的向上转换
class Base {};
class Derived : public Base {};

int main() {
  Derived derivedObj;
  Base* basePtr = static_cast<Base*>(&derivedObj);
  return 0;
}
#endif 

