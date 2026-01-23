// Binary Boarding
// Find the highest seat ID on the boarding pass
// A seat might be specified like FBFBBFFRLR, where 
// F means "front", B means "back", L means "left", 
// and R means "right". 128 rows and 8 columns
// The first 7 characters will either be F or B
// F means front rows (0 to 63), B is for back rows (64 to 127)
// Last 3 characters, will either be L or R
// L is lower half (0 to 3) of 8 columns and R is for upper half (4 to 7)

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <cmath>

// Find the seat ID using binary space partitioning
// Replace F with 0 and B with 1
// similarly, replace L with 0 and R with 1
// Convert the string into binary format and compute seat id
unsigned int getSeatId(const std::string& boardingpassstr) {
    unsigned int maxRowIdx{7};
    unsigned int maxCol{8};
    int binaryBase{2};

    std::string rowStr = boardingpassstr.substr(0, maxRowIdx);
    std::replace(rowStr.begin(), rowStr.end(), 'F', '0');
    std::replace(rowStr.begin(), rowStr.end(), 'B', '1');
    unsigned int rowId = std::stoi(rowStr, nullptr, binaryBase);

    std::string colStr = boardingpassstr.substr(maxRowIdx);
    std::replace(colStr.begin(), colStr.end(), 'L', '0');
    std::replace(colStr.begin(), colStr.end(), 'R', '1');
    unsigned int colId = std::stoi(colStr, nullptr, binaryBase);

    return rowId * maxCol + colId;
}

int main() {
    std::fstream file("day5input.txt");
    unsigned int seatId{0};

    if (file.is_open()) {
        std::string line;
        while(std::getline(file, line) && !line.empty()) {

            unsigned int tmpId{0};
            tmpId = getSeatId(line);

            if (tmpId > seatId) {
                // store max seat id
                seatId = tmpId;
            }
        }
        file.close();
        std::cout<<"Highest seat ID is "<<seatId<<std::endl;
    } else {
        std::cout<<"Could not read the file"<<seatId<<std::endl;
    }

    return 0;
}