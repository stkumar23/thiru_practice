// LeetCode - 657 - Robot Return to Origin
// There is a robot starting at the position (0, 0), the origin, on a 2D plane. 
// Given a sequence of its moves, judge if this robot ends up at (0, 0) after 
// it completes its moves. You are given a string moves that represents the 
// move sequence of the robot where moves[i] represents its ith move. Valid 
// moves are 'R' (right), 'L' (left), 'U' (up), and 'D' (down).
//
// Return true if the robot returns to the origin after it finishes all of 
// its moves, or false otherwise.
//
// ex: moves = "UD" => true
// ex: moves = "LL" => false
//
// Author: Thiru
//
// Time complexity: O(n)
// Space complexity: O(1)

#include <iostream>
#include <string>
#include <iomanip>

// Function to find robot return position to origin
// Increment x and y when the robot moves up or left
// Decrement x and y when the robot moves down or right
// Compare x and y to find the return to origin position
bool judgeCircle(const std::string& moves) {
    int x = 0;
    int y = 0;

    for (const char& ch: moves) {
        if (ch == 'U') {
            x++;
        } else if (ch == 'D') {
            x--;
        } else if (ch == 'L') {
            y++;
        } else if (ch == 'R') {
            y--;
        }
    }

    return x == y;
}

int main() {
    std::string moves{"UD"};
    //std::string moves{"LL"};
    std::cout<< "Robot returned to origin " << std::boolalpha << judgeCircle(moves) << std::endl;
    return 0;
}
