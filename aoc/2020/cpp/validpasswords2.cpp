// Find the number of valid passwords
// Each line gives the password policy and then the password. 
// Each policy actually describes two positions in the password, 
// where 1 means the first character, 2 means the second character, and so on.
// Exactly one of these positions must contain the given letter. 
// Other occurrences of the letter are irrelevant for the purposes of policy enforcement.
// For ex: 1-3 a: abcde is valid: position 1 contains a and position 3 does not. 
// 1-3 b: cdefg is invalid: neither position 1 nor position 3 contains b.
// 2-9 c: ccccccccc is invalid: both position 2 and position 9 contain c.

#include <iostream>
#include <fstream>
#include <string>

int main() {

    std::string line;
    std::ifstream file("day2input.txt");
    unsigned int validPwdCount{0};

    if (file.is_open()) {
        while (std::getline(file, line)) {
            unsigned int firstPos {0};
            unsigned int lastPos {0};
            char policyChar;
            std::string pwd;
            std::string tmp;

            // read min occurrance
            size_t hypPos = line.find_first_of("-");
            if (hypPos != std::string::npos) {
                tmp = line.substr(0, hypPos);
                firstPos = std::stoi(tmp);
            }

            // read max occurrance
            size_t spacePos = line.find_first_of(" ", hypPos);
            if (spacePos != std::string::npos) {
                tmp = line.substr(hypPos+1, spacePos-hypPos);
                lastPos = std::stoi(tmp);
            }

            // read policy char and password
            size_t colPos = line.find_first_of(":");
            policyChar = line[colPos-1];
            if( colPos != std::string::npos) {
                pwd = line.substr(colPos+2); // added 1 extra to trim space
            }

            // assuming none of the entries are missing
            if ((firstPos == 0) || (lastPos == 0) || (colPos == std::string::npos)) {
                continue; // skip valid pwd check
            }

            // for zeroth index
            firstPos -= 1;
            lastPos -= 1;

            bool firstPosPresent = (pwd[firstPos] == policyChar);
            bool lastPosPresent = (pwd[lastPos] == policyChar);

            // Char should appear in either one of the position, not both
            if (firstPosPresent ^ lastPosPresent) {
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