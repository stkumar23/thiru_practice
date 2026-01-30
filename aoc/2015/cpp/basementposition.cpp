// An opening parenthesis, (, means he should go up one floor, 
// and a closing parenthesis, ), means he should go down one floor.
// 
// The apartment building is very tall, and the basement is very deep;
//
// What is the position of the character that causes Santa to first enter the basement? (ie. floor -1)

#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream file("day1input.txt");
    std::string line;
    int floor {0};
    unsigned int position {0};

    if (file.is_open()) {
        std::getline(file, line);
        if (line.size()) {
            for (const char& ch: line) {
                // increment the counter
                if (ch == '(') {
                    floor++;
                } else { // decrement the counter
                    floor--;
                }
                position++; // parenthesis position
                if (floor == -1) {
                    break;
                }
            }

            std::cout<<"Santa reaches the first basement floor at position "<<position<<std::endl;
        } else {
            std::cout<<"File does not contain any data"<<std::endl;
        }
        file.close();
    } else {
        std::cout<<"Could not open the file"<<std::endl;
    }

    return 0;
}