// Find the number of valid passports from the given data
// Each passport data is separated by a blank line and
// each data is given as key:value format. Valid passport
// should have eight fields, the country code (cid) is optional

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

// Find the number of ':' in the passport data
// This is to read the number of fields
// The data value is not validated, hence reading ':' count
bool validPassport(const std::string& data) {
    int keyValueCount{8};
    char keyValueSep{':'};
    std::string cidKey{"cid"};

    int count = std::count(data.begin(), data.end(), keyValueSep);
    if (count == keyValueCount) {   // eight fields are present. valid
        return true;
    } else if (count == (keyValueCount - 1)) { // cid is optional. valid
        if (data.find(cidKey) == std::string::npos) {
            return true;
        }
    }

    return false;
}

int main() {
    std::fstream file("day4input.txt");
    std::string line;
    std::string passportData;
    unsigned int count{0};

    if (file.is_open()) {
        while(std::getline(file, line)) {
            if (line.empty() && passportData.size()) {
                if (validPassport(passportData)) {
                    count++;
                }
                passportData.clear();
            } else {
                passportData.append(" " + line);
            }
        }

        // last passport data
        if (passportData.size() && validPassport(passportData)) {
            count++;
        }

        std::cout<<"Valid passports are "<<count<<std::endl;
        file.close();
    } else {
        std::cout<<"Could not access the input file"<<std::endl;
    }

    return 0;
}