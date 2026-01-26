// Find the total number of questions to which everyone answered yes
// Identify the questions for which everyone in your group answers "yes".

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

unsigned int getGroupCount(const std::vector<std::string>& data) {
    unsigned int count{0};

    // initialize a array, size 26 initialized to 0
    // increment each index count in case a question is anwered yes
    // char c -'a' helps to get index (0 to 25) for (a to z)
    int answer[26] = {0};

    for (const std::string& s: data) {
        for (const char& c: s) {
            answer[c-'a'] += 1; // count the occurances
        }
    }

    // count the yes answered questions
    for (size_t i=0; i<26; i++) {
        // the answer count should be equivalent to total number of 
        // persons in the group ie. everyone
        if(answer[i] == data.size()) {
            count++;
        }
    }

    return count;
}

int main() {
    std::fstream file("day6input.txt");
    std::string line;
    std::vector<std::string> input;
    unsigned int count{0};

    if (file.is_open()) {
        while(std::getline(file, line)) {
            // read each group data
            // on reading blank line, get the yes questions count for that group
            if (line.empty()) {
                count += getGroupCount(input);
                input.clear();
            } else {
                input.push_back(line);
            }
        }

        // read last group input
        if (input.size()) {
            count += getGroupCount(input);
        }

        file.close();

        std::cout<<"Total number of 'yes' questions "<<count<<std::endl;

    } else {
        std::cout<<"Could not open the file"<<std::endl;
    }

    return 0;
}