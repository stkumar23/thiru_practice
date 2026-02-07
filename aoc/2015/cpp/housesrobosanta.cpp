// Santa is delivering presents to an infinite two-dimensional grid of houses.
// Santa creates a robot version of himself, Robo-Santa, to deliver presents with him.
// Santa and Robo-Santa start at the same location (delivering two presents to the same 
// starting house), then take turns moving based on instructions from the input
// 
// How many houses receive at least one present?
// ^v delivers presents to 3 houses, because Santa goes north, and then Robo-Santa goes south.
// ^>v< now delivers presents to 3 houses, and Santa and Robo-Santa end up back where they started.

#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <utility>

unsigned int getHousesCount(const std::string& input) {
    std::set<std::pair<int,int>> houses;
    // x and y positions are each house coordinates
    int santaXPos{0};
    int santaYPos{0};

    int roboXPos{0};
    int roboYPos{0};

    houses.insert(std::make_pair(santaXPos, santaYPos));

    for (int i=0; i<input.size(); i++) {
        const char& ch = input[i];
        if (i%2 == 0) { // santa moves
            if (ch == '^') {
                santaYPos++;
            } else if (ch == 'v') {
                santaYPos--;
            } else if (ch == '>') {
                santaXPos++;
            } else if (ch == '<') {
                santaXPos--;
            }
            houses.insert(std::make_pair(santaXPos, santaYPos));
        } else {    // robo-santa moves
            if (ch == '^') {
                roboYPos++;
            } else if (ch == 'v') {
                roboYPos--;
            } else if (ch == '>') {
                roboXPos++;
            } else if (ch == '<') {
                roboXPos--;
            }
            houses.insert(std::make_pair(roboXPos, roboYPos));
        }
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