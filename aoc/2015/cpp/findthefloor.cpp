// An opening parenthesis, (, means he should go up one floor, 
// and a closing parenthesis, ), means he should go down one floor.
// 
// The apartment building is very tall, and the basement is very deep;
//
// To what floor do the instructions take Santa?

#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream file("day1input.txt");
    std::string line;
    int floor {0};

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
            }

            std::cout<<"Santa reaches the floor "<<floor<<std::endl;
        } else {
            std::cout<<"File does not contain any data"<<std::endl;
        }
        file.close();
    } else {
        std::cout<<"Could not open the file"<<std::endl;
    }

    return 0;
}