/* #include <iostream>
#include <string>

using namespace std;

int main() {
  string str1("Hello World!");
  cout << str1 << endl;
  string str2(5, 'A');
  cout << str2 << endl;
  string str3 = str2;
  cout << str3 << endl;
  string str4("Hello World!");
  cout << str4 << endl;
  str4.assign("Hello World!", 5);
  cout << str4 << endl;
  str4.assign(str1, 6, 5);
  cout << str4 << endl;
  str4.assign("Hello World!", 6, 5);
  cout << str4 << endl;
  str4.assign(5, 'A');
  cout << str4 << endl;
  cout << str4[0] << endl;
  cout << str4.at(4) << endl;
  str4.at(2) = 'W';
  cout << str4 << endl;
  return 0;
} */
/* #include <iostream>
#include <string>

using namespace std;

int main() {
  string str1 = "Hello";
  str1 += " World";
  cout << str1 << endl;
  str1 += '!';
  cout << str1 << endl;
  str1.append("WWWWW", 0, 5);
  str1.append(str1, 0, 5);
  cout << str1 << endl;
  return 0;
} */
/* #include <iostream>
#include <string>

using namespace std;

int main() {
  string str1 = "Hellor World!";
  cout << str1.find("Wor") << endl;
  cout << str1.find("ord", 6, 2) << endl;
  cout << str1.find(string("Wor")) << endl;
  cout << str1.find('o', 6) << endl;
  cout << str1.rfind('o', 5) << endl;
  str1.replace(2, 5, "WWW");
  cout << str1 << endl;
  str1.replace(0, 2, "qa");
  cout << str1 << endl;
  return 0;
} */
/* #include <iostream>
#include <string>

using namespace std;

int main() {
  string str1("Hello World!");
  cout << str1.compare(0, 2, "we", 2) << endl;
  cout << str1.substr(0, 2) << endl;
  string str2("haha:xixi:lala:dodo");
  int pos = 0;
  while (true) {
    int ret = str2.find(':', pos);
    if (ret < 0) {
      cout << str1.length() << endl;
      break;
    }
    string sub = str2.substr(pos, ret - pos);
    cout << sub << endl;
    pos = ret + 1;
  }
  return 0;
} */
/* #include <iostream>
#include <string>

using namespace std;

int main() {
  string str1("Hello World!");
  str1.insert(5, 5, 'c');
  str1.insert(4, "Hello", 2, 1);
  cout << str1 << endl;
  str1.erase(0, 1);
  cout << str1 << endl;
  cout << str1.c_str() << endl;
  return 0;
} */
/* #include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> v1;
  v1.push_back(10);
  v1.push_back(30);
  v1.push_back(20);
  v1.push_back(50);
  v1.push_back(40);

  for (auto elem : v1) {
    cout << elem << ' ';
  }
  cout << '\n';
  return 0;
} */
/* #include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> v1;
  int count = 0;
  vector<int>::iterator it;

  for (int i = 0; i < 1000; ++i) {
    v1.push_back(1);
    if (it != v1.begin()) {
      it = v1.begin();
      ++count;
      cout << "第 " << count << " 次开辟空间，容量为 " << v1.capacity() << endl;
    }
  }
  return 0;
} */
/* #include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> v1(20, 5);
  for (auto elem : v1) {
    cout << elem << ' ';
  }
  cout << '\n';
  v1.assign(v1.begin() + 2, v1.begin() + 10);
  for (auto elem : v1) {
    cout << elem << ' ';
  }
  cout << '\n';
  v1.assign(5, 10);
  for (auto elem : v1) {
    cout << elem << ' ';
  }
  cout << '\n';
  vector<int> v2(4, 20);
  v1.swap(v2);
  for (auto elem : v1) {
    cout << elem << ' ';
  }
  cout << '\n';
  cout << v1.empty() << endl;
  cout << v1.size() << endl;
  v1.resize(2);
  for (auto elem : v1) {
    cout << elem << ' ';
  }
  cout << '\n';
  v1.resize(10, 10);
  for (auto elem : v1) {
    cout << elem << ' ';
  }
  cout << '\n';
  cout << v1.capacity() << endl;
  cout << v1.at(0) << ' ' << v1.front() << ' ' << v1.back() << endl;
  v1.pop_back();
  for (auto elem : v1) {
    cout << elem << ' ';
  }
  cout << '\n';
  v1.insert(v1.begin() + 1, 4, 10);
  for (auto elem : v1) {
    cout << elem << ' ';
  }
  cout << '\n';
  v1.clear();
  cout << v1.empty() << endl;
  return 0;
} */
/* #include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> v1;
  v1.reserve(1000);
  v1.push_back(10);
  v1.push_back(20);
  v1.push_back(30);
  v1.push_back(40);
  cout << "容量：" << v1.capacity() << "，大小：" << v1.size() << endl;
  vector<int>(v1).swap(v1);
  cout << "容量：" << v1.capacity() << "，大小：" << v1.size() << endl;
  return 0;
} */
/* #include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> v1(5, 10);
  vector<int> v2(5, 100);
  vector<int> v3(5, 1000);
  vector<vector<int>> v;
  v.push_back(v1);
  v.push_back(v2);
  v.push_back(v3);
  for (auto it = v.begin(); it != v.end(); ++it) {
    for (auto mit = (*it).begin(); mit != (*it).end(); ++mit) {
      cout << *mit << ' ';
    }
    cout << '\n';
  }
  return 0;
} */
/* #include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector v1 = {10, 30, 20, 40, 5};
  for (auto elem : v1) {
    cout << elem << ' ';
  }
  cout << '\n';
  sort(v1.begin(), v1.end(), greater<int>());
  for (auto elem : v1) {
    cout << elem << ' ';
  }
  cout << '\n';
  return 0;
} */
/* #include <iostream>

int main() {
  std::cout << "Hello, world!" << '\n';
  return 0;
} */
/* #include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> v1(5,10);
  v1.reserve(100);
  cout << v1.capacity() << endl;
  vector<int>(v1).swap(v1);
  cout << v1.capacity() << endl;
  return 0;
} */
/* #include <deque>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector v1(5, 10);
  deque d1(3, 5);
  for (auto elem : d1) {
    cout << elem << ' ';
  }
  cout << '\n';
  d1.assign(v1.begin(), v1.end());
  for (auto elem : d1) {
    cout << elem << ' ';
  }
  cout << '\n';
  cout << d1.size() << '\n';
  d1.resize(10, 99);
  for (auto elem : d1) {
    cout << elem << ' ';
  }
  cout << '\n';
  d1.push_back(20);
  d1.push_front(5);
  for (auto elem : d1) {
    cout << elem << ' ';
  }
  cout << '\n';
  d1.insert(d1.begin() + 3, 56);
  d1.insert(d1.begin() + 2, 5, 10);
  for (auto elem : d1) {
    cout << elem << ' ';
  }
  cout << '\n';
  d1.clear();
  cout << d1.empty() << '\n';
  return 0;
} */
/* #include <iostream>
#include <random>
#include <stack>

using namespace std;

int main() {
  random_device rd;
  mt19937 gen(rd());
  uniform_real_distribution<> dis(1, 100);
  stack<int> s1;
  for (int i = 0; i < 10; ++i) {
    s1.push(dis(gen));
    cout << s1.top() << ' ';
  }
  cout << '\n';
  cout << s1.size() << '\n';
  while (!s1.empty()) {
    cout << s1.top() << ' ';
    s1.pop();
  }
  cout << '\n';
  return 0;
} */
/* #include <iostream>
#include <queue>
#include <random>

using namespace std;

int main() {
  random_device rd;
  mt19937 gen(rd());
  queue<int> q1;
  uniform_real_distribution<> dis(1, 100);

  for (int i = 0; i < 10; ++i) {
    q1.push(dis(gen));
    cout << q1.back() << ' ';
  }
  cout << '\n';

  for (int i  =0; i < 10; ++i) {
    cout << q1.front() << ' ';
    q1.pop();
  }
  cout << '\n';
  return 0;
} */
/* #include <functional>
#include <iostream>
#include <list>
#include <random>

using namespace std;

int main() {
  random_device rd;
  mt19937 gen(rd());
  uniform_real_distribution<> dis(1, 100);
  list<int> l1;
  for (int i = 0; i < 10; ++i) {
    l1.push_back(dis(gen));
    cout << l1.back() << ' ';
  }
  cout << '\n';
  l1.reverse();
  for (auto elem : l1) {
    cout << elem << ' ';
  }
  cout << '\n';
  l1.sort(greater<int>());
  for (auto elem : l1) {
    cout << elem << ' ';
  }
  cout << '\n';
  l1.sort();
  for (auto elem : l1) {
    cout << elem << ' ';
  }
  cout << '\n';
  cout << l1.size() << '\n';
  return 0;
} */
/* #include <set>
#include <iostream>
#include <random>

using namespace std;

int main() {
  random_device rd;
  mt19937 gen(rd());
  uniform_real_distribution<> dis(1, 100);
  multiset<int> st;
  for (int i = 0; i < 10; ++i) {
    int num = dis(gen);
    cout << num << ' ';
    st.insert(num);
  }
  cout << '\n';
  for (int elem : st) {
    cout << elem << ' ';
  }
  cout << '\n';
  cout << st.count(55) << '\n';
  cout << *st.upper_bound(44) << '\n';
  cout << *st.lower_bound(44) << '\n';
  cout << st.size() << '\n';
  return 0;
} */
/* #include <iostream>
#include <set>

int main() {
  std::multiset<int> s = {1, 2, 4, 4, 4, 5, 7};

  int target = 4;
  auto range = s.equal_range(target);

  for (auto it = range.first; it != range.second; ++it) {
    std::cout << *it << " ";  // 输出 4
  }
  std::cout << '\n';

  return 0;
} */
/* #include <iostream>
#include <string>
#include <utility>

using namespace std;

int main() {
  pair<int, string> pair1(20, string("name"));
  cout << pair1.first << ", " << pair1.second << '\n';
  pair<int, string> pair2 = make_pair(20, "name");
  cout << pair2.first << ", " << pair2.second << '\n';
  return 0;
} */
/* #include <iostream>
#include <map>
#include <utility>

using namespace std;

int main() {
  map<int, string> m1;
  m1.insert(map<int, string>::value_type(1, "小王"));
  m1.insert(make_pair(2, "小陈"));
  m1.insert(pair<int, string>(3, "小李"));
  m1.emplace(4, "小张");
  m1[5] = "小谢";
  for (auto pair : m1) {
    cout << pair.first << "，" << pair.second << '\n';
  }
  return 0;
} */
/* #include <list>
#include <map>
#include <vector>
#include <string>
#include <iostream>

int main() {
  std::map<int, std::string> map1;
  map1.emplace(1, "Shut up, Meg!");
  std::cout << map1.at(1) << '\n';
  std::vector<int> v1(5, 10);
  for (int elem : v1) {
    std::cout << elem <<  ' ';
  }
  std::list<int> l1;
  l1.push_front(2);
  return 0;
} */
/* #include <iostream>
#include <limits>
#include <string>

enum class Operation { Add, Subtract, Multiply, Divide };

double getNumber(const std::string& prompt) {
  double number;
  while (true) {
    std::cout << prompt;
    if (std::cin >> number) {
      break;
    } else {
      std::cout << "Please enter a valid number.\n";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  }
  return number;
}

Operation getOperation() {
  int choice;
  while (true) {
    std::cout << "Choose an operation:\n";
    std::cout << "1. Add\n";
    std::cout << "2. Subtract\n";
    std::cout << "3. Multiply\n";
    std::cout << "4. Divide\n";

    if (std::cin >> choice) {
      switch (choice) {
        case 1:
          return Operation::Add;
        case 2:
          return Operation::Subtract;
        case 3:
          return Operation::Multiply;
        case 4:
          return Operation::Divide;
        default:
          std::cout << "Invalid choice. Please select 1, 2, 3, or 4.\n";
      }
    } else {
      std::cout << "Please enter a valid number.\n";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  }
}

int main() {
  double num1 = getNumber("Enter the first number: ");
  double num2 = getNumber("Enter the second number: ");

  Operation operation = getOperation();

  switch (operation) {
    case Operation::Add:
      std::cout << "Result: " << num1 + num2 << "\n";
      break;
    case Operation::Subtract:
      std::cout << "Result: " << num1 - num2 << "\n";
      break;
    case Operation::Multiply:
      std::cout << "Result: " << num1 * num2 << "\n";
      break;
    case Operation::Divide:
      if (num2 == 0) {
        std::cout << "Error: Division by zero is not allowed.\n";
      } else {
        std::cout << "Result: " << num1 / num2 << "\n";
      }
      break;
  }

  return 0;
}
 */
