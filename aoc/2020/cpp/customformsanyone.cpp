// Find the total number of questions to which anyone answered yes
// Identify the questions for which anyone in your group answers "yes".

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

unsigned int getGroupCount(const std::vector<std::string>& data) {
    unsigned int count{0};

    // initialize a bool of vector, size 26 initialized to false
    // update each index in case a question is anwered yes
    // char c -'a' helps to get index (0 to 25) for (a to z)
    std::vector<bool> answer(26, false);

    for (const std::string& s: data) {
        for (const char& c: s) {
            if(!answer[c-'a']) {
                answer[c-'a'] = true;
            }
        }
    }

    // count the yes answered questions
    for (size_t i=0; i<answer.size(); i++) {
        if(answer[i]) {
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