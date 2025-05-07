#include <iostream>
#include <string>
#include <vector>

void PrintGreeting(const std::string& name) {
    std::cout << "Hello, " << name << "!" << std::endl;
}

int AddNumbers(int a, int b) {
    return a + b;
}

int main() {
    std::cout << "Hello World!" << std::endl;

    std::string user_name = "Alice";
    PrintGreeting(user_name);

    int num_1 = 5;
    int num_2 = 7;
    int sum_result = AddNumbers(num_1, num_2);
    std::cout << "The sum of " << num_1 << " and " << num_2 << " is: " << sum_result << std::endl;

    std::vector<int> numbers_vector = { 1, 2, 3, 4, 5 };
    std::cout << "Numbers in the vector: ";
    for (int number_item : numbers_vector) {
        std::cout << number_item << " ";
    }
    std::cout << std::endl;

    return 0;
}
