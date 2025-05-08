// LeetCode - 1108 - Defanging an IP Address
// Given a valid (IPv4) IP address, return a defanged version of that IP address.
// A defanged IP address replaces every period "." with "[.]".
//
// ex: address = "1.1.1.1" => "1[.]1[.]1[.]1"
// ex: address = "255.100.50.0" => "255[.]100[.]50[.]0"
//
// Author: Thiru
//
// Time complexity: O(n)
// Space complexity: O(1)

#include <iostream>
#include <string>

// Function to get the defanged IP address
// Read the given string from left to right
// Insert '[' and ']' at right place when a '.' is found
// Increment left and right pointers to 2 (because of two new chars '[' and ']')
void getDefangedAddress (std::string& ipstr) {
    int left = 0;
    int right = ipstr.size();
    if (right <= 1) {
        return;
    }

    while(left <= right) {
        if (ipstr[left] != '.') {
            left++;
        } else {
            ipstr.insert(left, 1, '[');
            ipstr.insert(left+2, 1, ']');
            left += 2;
            right += 2;
        }
    }
}

int main() {
    std::string ipstr("255.100.50.0");
    getDefangedAddress(ipstr);
    std::cout<<"Defanged IP Address: " << ipstr << std::endl;

    return 0;
}