// Find the three entries that sum to 2020; What do you get if you multiply them together

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

long findSumAndMultiples(std::vector<unsigned int>& inputs, const unsigned int& sum) {
    unsigned int target{0};
    int size = inputs.size();

    // sort the given inputs
    std::sort(inputs.begin(), inputs.end());

    for (size_t i=0; i<size; i++) {
        target = sum - inputs[i];
        // Using the two pointer approach, find the other two numbers
        int left = i+1;
        int right = size - 1;
        while (left < right) {
            int cur_sum = inputs[left] + inputs[right];
            if (cur_sum == target) {
                return long (inputs[i] * inputs[left] * inputs[right]);
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
    }
    return 0;
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
