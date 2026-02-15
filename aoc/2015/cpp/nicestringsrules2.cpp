// A nice string is one with all of the following properties: (second rule)
// It contains a pair of any two letters that appears at least twice in the string 
// without overlapping, like xyxy (xy) or aabcdefgaa (aa), 
// but not like aaa (aa, but it overlaps).
// It contains at least one letter which repeats with exactly one letter between 
// them, like xyx, abcdefeghi (efe), or even aaa.

// How many strings are nice?

#include <iostream>
#include <fstream>
#include <string>

bool hasTwoPairsOfTwoLetters(const std::string& text) {
    if (text.size() >= 2) {
        auto lastPos = text.size() - 2;
        for(auto i = 1; i < lastPos; ++i) {
            if (text.substr(i + 1).find(text.substr(i - 1, 2)) != std::string::npos) {
                return true;
            }
        }
    }

    return false;
}

bool hasRepeatedLetterWithOnebetween(const std::string& text) {
    if (text.size() >= 3) {
        for (size_t i=2; i<text.size(); i++) {
            if (text[i] == text[i-2]) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    std::fstream file("../day5input.txt");
    std::string line;
    unsigned int count{0};

    if (file.is_open()) {
        while(std::getline(file, line) && !line.empty()) {
            if (hasTwoPairsOfTwoLetters(line) && hasRepeatedLetterWithOnebetween(line)) {
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