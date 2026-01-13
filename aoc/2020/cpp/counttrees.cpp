// Map contains open squares (.) and trees (#).
// Start on the open square (.) in the top-left corner 
// and reach to the bottom-most row in the map,
// by travesring a slope of right 3 and down 1
// Count the number of trees encounted along the route

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int readInputData(const std::string& fileName, std::vector<std::string>& map) {
    std::ifstream inputFile(fileName);
    std::string line;

    // read input data and store it in 2D vector
    if (inputFile.is_open()) {
        while(std::getline(inputFile, line) && line.size()) {
            map.push_back(line);
        }
        inputFile.close();
    } else {
        std::cout<<"Could not open the file"<<std::endl;
        return -1;
    }
    return 0;
}

int main() {
    std::string fName("day3input.txt");
    std::vector<std::string> map;

    if(readInputData(fName, map) == 0) {
        size_t rowSize = map.size();
        size_t colSize = 0; 
        if (rowSize) {
            colSize = map[0].size();
        }

        if (colSize == 0) {
            std::cout<<"Invalid input "<<std::endl;
            return -1;
        }
 
        unsigned int rowIndex = 0;
        unsigned int colIndex = 0;
        unsigned int treeCount = 0;
        unsigned int rightStep = 3;

        while (rowIndex < rowSize-1) {
            // once col index reaches the col size, move the index to left
            colIndex = (colIndex + rightStep) % colSize;
            rowIndex++; // increment the row index (down step is 1)
             if(map[rowIndex][colIndex] == '#') {
                treeCount++;
            }
        }

        std::cout<<"Tree count "<<treeCount<<"\n";
    }

    return 0;
}