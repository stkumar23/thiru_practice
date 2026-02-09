// A nice string is one with all of the following properties:
// It contains at least three vowels (aeiou only), like aei, xazegov, or aeiouaeiouaeiou.
// It contains at least one letter that appears twice in a row, like xx, abcdde (dd), or aabbccdd (aa, bb, cc, or dd).
// It does not contain the strings ab, cd, pq, or xy, even if they are part of one of the other requirements.

// How many strings are nice?

#include <iostream>
#include <fstream>
#include <string>

bool hasThreeVowels(const std::string& text) {
    unsigned int count{0};
    for (const char& ch: text) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            count++;
        }
        if (count == 3) { // break if it contains three vowels
            return true;
        }
    }

    return false;
}

bool hasSameConsecutiveLetter(const std::string& text) {
    for (size_t i=1; i<text.size(); i++) {  // start i with 1
        if (text[i-1] == text[i]) {
            return true;
        }
    }

    return false;
}

bool hasNoInvalidStrings(const std::string& text) {

    if (text.find("ab") != std::string::npos) {
        return false;
    }
    if (text.find("cd") != std::string::npos) {
        return false;
    }
    if (text.find("pq") != std::string::npos) {
        return false;
    }
    if (text.find("xy") != std::string::npos) {
        return false;
    }

    return true;
}

int main() {
    std::fstream file("../day5input.txt");
    std::string line;
    unsigned int count{0};

    if (file.is_open()) {
        while(std::getline(file, line) && !line.empty()) {
            if (hasThreeVowels(line) && hasNoInvalidStrings(line) && hasSameConsecutiveLetter(line)) {
                count++;
            }
        }
        file.close();
        std::cout<<"Nice strings count "<<count<<std::endl;
    } else {
        std::cout<<"Could not open the input file"<<std::endl;
    }

    return 0;
}