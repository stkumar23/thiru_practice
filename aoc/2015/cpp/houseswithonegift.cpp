// Santa is delivering presents to an infinite two-dimensional grid of houses.
// He begins by delivering a present to the house at his starting location,
// Moves are always exactly one house to the north (^), south (v), east (>), 
// or west (<). After each move, he delivers another present to the house at his new location.
// 
// How many houses receive at least one present?
// > delivers presents to 2 houses: one at the starting location, and one to the east.
// ^>v< delivers presents to 4 houses in a square, including twice to the house at his starting/ending location.

#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <utility>

unsigned int getHousesCount(const std::string& input) {
    std::set<std::pair<int,int>> houses;
    // x and y positions are each house coordinates
    int xPos{0};
    int yPos{0};

    houses.insert(std::make_pair(xPos, yPos));

    for (const char& ch: input) {
        if (ch == '^') {
            yPos++;
        } else if (ch == 'v') {
            yPos--;
        } else if (ch == '>') {
            xPos++;
        } else if (ch == '<') {
            xPos--;
        }
        houses.insert(std::make_pair(xPos, yPos));
    }
    return houses.size();
}

int main() {
    std::ifstream file("../day3input.txt");
    std::string line;
    unsigned int totalHouses{0};

    if (file.is_open()) {
        std::getline(file, line);
        file.close();
        totalHouses = getHousesCount(line);
        std::cout<<"Number of houses received atleast one present "<<totalHouses<<std::endl;
    } else {
        std::cout<<"Could not open the file"<<std::endl;
    }

    return 0;
}