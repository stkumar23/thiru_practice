// How many total feet of ribbon should they order?
// list of the dimensions (length l, width w, and height h) of each present
// The ribbon required to wrap a present is the shortest distance around 
// its sides, or the smallest perimeter of any one face. Each present also 
// requires a bow made out of ribbon as well; the feet of ribbon required 
// for the perfect bow is equal to the cubic feet of volume of the present.
//
// A present with dimensions 2x3x4 requires 2+2+3+3 = 10 feet of ribbon to wrap 
// the present plus 2*3*4 = 24 feet of ribbon for the bow, for a total of 34 feet.

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

struct GiftBox{
    unsigned int length;
    unsigned int width;
    unsigned int height;
};

int ribbonSizeForBox(const GiftBox& gb) {
    unsigned int ribbonLength {0};
    unsigned int bowLength {0};

    ribbonLength = std::min({(gb.length+gb.width), (gb.width+gb.height), (gb.height+gb.length)});
    bowLength = gb.length * gb.width * gb.height;

    return (2 * ribbonLength) + bowLength;
}

int main() {
    std::vector<GiftBox> gbList;
    std::ifstream file("../day2input.txt");
    std::string line;
    unsigned int total{0};

    if (file.is_open()) {
        while (std::getline(file, line)) {
            if (line.size()) {
                GiftBox box;
                size_t xPos1 = line.find('x');
                box.length = std::stoi(line.substr(0,xPos1));
                size_t xPos2 = line.find('x', xPos1+1);
                box.width = std::stoi(line.substr(xPos1+1,xPos2));
                box.height = std::stoi(line.substr(xPos2+1));
                gbList.push_back(box);
            }
        }
        file.close();

        for (const GiftBox& gb: gbList) {
            total += ribbonSizeForBox(gb);
        }

        std::cout<<"Total square feet of wrapping paper required "<<total<<std::endl;
    } else {
        std::cout<<"Could not open the file"<<std::endl;
    }
    return 0;
}
