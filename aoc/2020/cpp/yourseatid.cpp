// Binary Boarding
// Find the highest seat ID on the boarding pass
// A seat might be specified like FBFBBFFRLR, where 
// F means "front", B means "back", L means "left", 
// and R means "right". 128 rows and 8 columns
// The first 7 characters will either be F or B
// F means front rows (0 to 63), B is for back rows (64 to 127)
// Last 3 characters, will either be L or R
// L is lower half (0 to 3) of 8 columns and R is for upper half (4 to 7)
// From this list find your seat id
// The seats with IDs +1 and -1 from yours will be in your list.

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <unordered_set>

// Find the half point based on 'F', 'B', 'L' or 'R' and
// based on that character, adjust low and high values. 
// Return low value
unsigned int getHalf (const std::string& input, unsigned int high, 
                        const char& lower, const char& higher) {
    std::string::const_iterator iter = input.begin();
    unsigned int low = 0;
    while(iter != input.end()){
        char x = *iter;
        double h = (high - low)/2.0;
        
        if(x == lower){
            high = high - ceil(h);
        }else if(x == higher){
            low = low + ceil(h);
        }
        iter++;
    }
    return low;
}

unsigned int getSeatId(const std::string& input) {
    unsigned int maxRow{128};
    unsigned int maxCol{8};

    // 0 - 6 contains row details
    unsigned int row = getHalf(input.substr(0,7), maxRow - 1, 'F', 'B');
    // 7 - 9 contains column details
    unsigned int column = getHalf(input.substr(7), maxCol - 1, 'L', 'R');
    return row * maxCol+ column;
}

int main() {
    std::fstream file("day5input.txt");
    unsigned int maxSeatId{0};
    std::unordered_set<unsigned int> seats;

    if (file.is_open()) {
        std::string line;
        while(std::getline(file, line) && !line.empty()) {

            unsigned int tmpId{0};
            tmpId = getSeatId(line);
            seats.emplace(tmpId);

            if (tmpId > maxSeatId) {
                // store highest seat id
                maxSeatId = tmpId;
            }
        }

        // find your seat id
        unsigned int yourSeatId{0};
        for (unsigned int i=0; i<maxSeatId; i++) {
            if ((seats.find(i-1) != seats.end()) &&
                (seats.find(i) == seats.end()) &&
                (seats.find(i+1) != seats.end())) {
                yourSeatId = i;
                break;
            }
        }
        file.close();
        std::cout<<"Your seat ID is "<<yourSeatId<<std::endl;
    } else {
        std::cout<<"Could not read the file"<<std::endl;
    }

    return 0;
}