// Find the number of valid passwords
// Each line gives the password policy and then the password. 
// The password policy indicates the lowest and highest number 
// of times a given letter must appear for the password to be valid. 
// For ex: 1-3 a: abcde, 1-3 a means that the password must 
// contain a at least 1 time and at most 3 times.

#include <iostream>
#include <fstream>
#include <string>

bool isValidPassword(const unsigned int& low,
                    const unsigned int& high,
                    const char& ch,
                    const std::string& pwd) {
    int count {0};
    for (const char& c: pwd) {
        if (c == ch) {
            count++;
        }
    }

    if ((count >= low) && (count <= high)) {
        return true;
    }

    return false;
}

int main() {

    std::string line;
    std::ifstream file("day2input.txt");
    unsigned int validPwdCount{0};

    if (file.is_open()) {
        while (std::getline(file, line)) {
            unsigned int minOccur {0};
            unsigned int maxOccur {0};
            char policyChar;
            std::string pwd;
            std::string tmp;

            // read min occurrance
            size_t hypPos = line.find_first_of("-");
            if (hypPos != std::string::npos) {
                tmp = line.substr(0, hypPos);
                minOccur = std::stoi(tmp);
            }

            // read max occurrance
            size_t spacePos = line.find_first_of(" ", hypPos);
            if (spacePos != std::string::npos) {
                tmp = line.substr(hypPos+1, spacePos-hypPos);
                maxOccur = std::stoi(tmp);
            }

            // read policy char and password
            size_t colPos = line.find_first_of(":");
            policyChar = line[colPos-1];
            if( colPos != std::string::npos) {
                pwd = line.substr(colPos+2); // added 1 extra to trim space
            }

            // assuming none of the entries are missing
            if ((minOccur == 0) || (maxOccur == 0) || (colPos == std::string::npos)) {
                continue; // skip valid pwd check
            }

            if (isValidPassword(minOccur, maxOccur, policyChar, pwd)) {
                validPwdCount++;
            }
        }
        std::cout<<"Valid passwords are "<<validPwdCount<<std::endl;
        // Close the file after reading the input
        file.close();
    } else {
        std::cout<<"Could not open the file"<<std::endl;
    }

    return 0;
}