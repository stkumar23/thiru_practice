// Modern C++ - C++17 - std::optional
// The class template std::optional manages an optional contained value, 
// i.e. a value that may or may not be present. Any instance of optional 
// at any given point in time either contains a value or does not contain a value.
//
// Defined in the header <optional>
//
// Compile with -std=c++17
//
// Author: Thiru

#include <iostream>
#include <optional>


// Function to demo the use of std::optional
std::optional<int> divide(int numerator, int denominator) {
    if (denominator == 0) {
        return std::nullopt; // return nullopt
    }

    return numerator/denominator;
}

int main() {

    int n {10};
    int d {2};

    auto res = divide(n, d);
    if (res.has_value()) {
        std::cout << "The result "<< *res << std::endl;
    } else {
        std::cout << "The result is failed";
    }

    res = divide(n, 0);
    if (res.has_value()) {
        std::cout << "The result "<< res.value() << std::endl;
    } else {
        std::cout << "The result is failed" << std::endl;
    }

    std::optional<std::string> firstname{"Thiru"};
    std::optional<std::string> lastname;

    // Use "unknown" in case lastname is not defined
    std::string fullname = *firstname + " " + lastname.value_or("unknown");

    std::cout << "Full name is " << fullname << std::endl;

    return 0;
}
