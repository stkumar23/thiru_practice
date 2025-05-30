// LeetCode - 43 - MultiplyStrings
// Given two non-negative integers num1 and num2 represented as strings,
// return the product of num1 and num2, also represented as a string.
// Note: You must not use any built-in BigInteger library or convert the
// inputs to integer directly.
//
// ex: num1 = "2", num2 = "3" => "6"
// ex: num1 = "123", num2 = "456" => "56088"
//
// Author: Thiru
//
// Time complexity: O(n*n)
// Space complexity: O(n+n)

#include <iostream>
#include <string>


// Function to multiply given strings
// Reserve the string size. In case any one of the string is 0, return 0.
// Begin from right to left, read digits from each strings, multiply
// Sum it with the previous index value (carry). Place the sum reminder
// in the index.
// Return the result without any leading 0s.

std::string multiply(const std::string& num1, const std::string& num2) {
    if (num1 == "0" || num2 == "0")
        return "0";

    std::string res(num1.size()+num2.size(), '0');

    for (int i=num1.size()-1; i>=0; i--) {
        for (int j=num2.size()-1; j>=0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = mul + (res[i+j+1] - '0');
            res[i+j] += sum/10;
            res[i+j+1] = '0' + sum%10;
        }
    }

    const int i = res.find_first_not_of('0');
    return i == std::string::npos ? "0" : res.substr(i);
}

int main() {
    // std::string n1("2");
    // std::string n2("3");

    std::string n1("123");
    std::string n2("456");

    std::cout<< "Output: " << multiply(n1, n2) << std::endl;

    return 0;
}
