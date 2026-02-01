// How many total square feet of wrapping paper should Elves order?
// list of the dimensions (length l, width w, and height h) of each present
// every present is a box (a perfect right rectangular prism), which makes 
// calculating the required wrapping paper for each gift a little easier: 
// find the surface area of the box, which is 2*l*w + 2*w*h + 2*h*l. 
// The elves also need a little extra paper for each present: the area of the smallest side.
//
// A present with dimensions 2x3x4 requires 2*6 + 2*12 + 2*8 = 52 square feet 
// of wrapping paper plus 6 square feet of slack, for a total of 58 square feet.

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

struct GiftBox{
    unsigned int length;
    unsigned int width;
    unsigned int height;
};

int wrapperSizeForBox(const GiftBox& gb) {
    unsigned int boxArea {0};
    unsigned int smallSideArea {0};
    unsigned int lw = gb.length * gb.width;
    unsigned int wh = gb.width * gb.height;
    unsigned int hl = gb.height * gb.length;

    boxArea = (2 * lw) + (2 * wh) + (2 * hl);
    if (lw < wh) {
        smallSideArea = lw;
    } else {
        smallSideArea = wh;
    }
    if (smallSideArea > hl) {
        smallSideArea = hl;
    }

    return boxArea + smallSideArea;
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
            total += wrapperSizeForBox(gb);
        }

        std::cout<<"Total square feet of wrapping paper required "<<total<<std::endl;
    } else {
        std::cout<<"Could not open the file"<<std::endl;
    }
    return 0;
}
