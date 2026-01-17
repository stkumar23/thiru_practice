// Map contains open squares (.) and trees (#).
// Start on the open square (.) in the top-left corner 
// and reach to the bottom-most row in the map,
// by travesring various slope, count number of trees 
// encounted along each route and multiply the counts.
// various slope patterns:
//      Right 1, down 1.
//      Right 3, down 1.
//      Right 5, down 1.
//      Right 7, down 1.
//      Right 1, down 2.

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

long long countTreesAlongtheRoute(const std::vector<std::string>& map,
                                    unsigned int rightStep,
                                    unsigned int downStep) {
    unsigned int rowIndex = 0;
    unsigned int colIndex = 0;
    long long treeCount = 0;

    size_t rowSize = map.size();
    size_t colSize = map[0].size();

    if (colSize == 0) {
        std::cout<<"Invalid input "<<std::endl;
        return -1;
    }

    while (rowIndex < rowSize-1) {
        // once col index reaches the col size, move the index to left
        colIndex = (colIndex + rightStep) % colSize;
        rowIndex += downStep; // increment the row index
            if(map[rowIndex][colIndex] == '#') {
            treeCount++;
        }
    }
    return treeCount;
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
 
        long long treeCount = 1;

        treeCount *= countTreesAlongtheRoute(map, 1, 1);
        treeCount *= countTreesAlongtheRoute(map, 3, 1);
        treeCount *= countTreesAlongtheRoute(map, 5, 1);
        treeCount *= countTreesAlongtheRoute(map, 7, 1);
        treeCount *= countTreesAlongtheRoute(map, 1, 2);

        std::cout<<"Tree count "<<treeCount<<"\n";
    }

    return 0;
}