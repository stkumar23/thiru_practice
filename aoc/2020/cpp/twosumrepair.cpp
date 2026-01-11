// Find the two entries that sum to 2020; What do you get if you multiply them together

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_set>

long findSumAndMultiples(const std::vector<unsigned int>& inputs, const unsigned int& sum) {
    std::unordered_set<unsigned int> set;
    unsigned int target{0};
    long result{-1};
    for (const unsigned int& element : inputs) {
        target = sum - element;
        if (set.find(target) != set.end()) {
            result = element * target;
            break;
        }
        set.emplace(element);
    }
    return result;
}

int main() {

    std::fstream file("day1input.txt");
    std::string line;
    std::vector<unsigned int> input;
    unsigned int sum = 2020;

    if (file.is_open()) {
        while (std::getline(file, line)) {
            unsigned int element = static_cast<unsigned int>(std::stoi(line));
            input.push_back(element);
        }
        file.close();
        std::cout<<"The sum multiple is "<<findSumAndMultiples(input, sum)<<std::endl;
    } else {
        std::cout<<"Could not open the file"<<std::endl;
    }

    return 0;
}
