// Find the number of valid passports from the given data
// Each passport data is separated by a blank line and
// each data is given as key:value format. Valid passport
// should have eight fields, the country code (cid) is optional
// The rules are other fields are
// byr (Birth Year) - four digits; at least 1920 and at most 2002.
// iyr (Issue Year) - four digits; at least 2010 and at most 2020.
// eyr (Expiration Year) - four digits; at least 2020 and at most 2030.
// hgt (Height) - a number followed by either cm or in:
//      If cm, the number must be at least 150 and at most 193.
//      If in, the number must be at least 59 and at most 76.
// hcl (Hair Color) - a # followed by exactly six characters 0-9 or a-f.
// ecl (Eye Color) - exactly one of: amb blu brn gry grn hzl oth.
// pid (Passport ID) - a nine-digit number, including leading zeroes.
// cid (Country ID) - ignored, missing or not.

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cctype>
#include <algorithm>

// First check valid fields are available
bool validFields(const std::string& data) {
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

bool validPassport(const std::string& data) {
    if(!validFields(data)) {
        return false;
    }

    std::istringstream stream{data};
    std::string keyValueData;

    while (stream >> keyValueData) {
        size_t colPos = keyValueData.find(":");
        if (colPos != std::string::npos) {
            std::string key = keyValueData.substr(0, colPos);
            std::string value = keyValueData.substr(colPos+1);
            if (value.empty()) {
                return false;
            }
            if (key == "byr") { // validate birth year
                int year = std::stoi(value);
                if (year<1920 || year>2002) {
                    return false;
                }
            } else if (key == "iyr") { // validate issue year
                int year = std::stoi(value);
                if (year<2010 || year>2020) {
                    return false;
                }
            } else if (key == "eyr") { // validate expiration year
                int year = std::stoi(value);
                if (year<2020 || year>2030) {
                    return false;
                }
            } else if (key == "ecl") {  // validate eye color
                if (value != "amb" && value != "blu" &&
                    value != "brn" && value != "gry" &&
                    value != "grn" && value != "hzl" && 
                    value != "oth") {
                    return false;
                }
            } else if (key == "hcl") {  // validate hair color
                if (value[0] != '#') {  // first char must be '#'
                    return false;
                }
                if (value.size() > 7) { // length should be less than 7 (incl #)
                    return false;
                }
                bool valid = std::all_of(value.begin()+1, value.end(), [] (unsigned char c) {
                                return std::isalnum(c);
                            });
                if (!valid) {
                    return false;
                }
            } else if (key == "pid") {  // validate passport id
                if (value.size() < 9 || value.size() > 9) {
                    return false;
                }
                bool valid = std::all_of(value.begin(), value.end(), [](unsigned char c) {
                                return std::isdigit(c);
                                });
                if (!valid) {
                    return false;
                }
            } else if (key == "hgt") {  // validate height
                std::istringstream kv(value);
                int hgt{0};
                std::string unit;
                kv >> hgt >> unit;
                if (unit.empty()) {
                    return false;
                }
                if ((unit == "cm") && (hgt < 150 || hgt > 193)) {
                    return false;
                } else if ((unit == "in") && (hgt < 59 || hgt > 76)) {
                    return false;
                }
            }
        }
    }

    return true;
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