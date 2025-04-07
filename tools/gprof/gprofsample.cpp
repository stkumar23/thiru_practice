// Sample program to demo gprof tool usage
// 1. compile the program with -pg option
//    g++ -o gprofsample gprofsample.cpp -pg
// 2. execute the program. gmon.out file will be generated. This is gprof
//    data file.
// 3. Run the command: gprof ./gprofsample [gmon.out] > gprofanalysis.txt
//
// The output file gprofanalysis.txt contains the performance analysis of this
// sample program. This file contains two sections.
// Flat profile: shows the total amount of time your program spent executing
//                each function.
// Call graph: shows how much time was spent in each function and its children.

#include <iostream>
using namespace std;

class GprofSample {
public:
  int func1();
  int func2();
  int func3();
};

int GprofSample::func1() {
  int i=0;
  int g=0;
  while(i++ < 10000) {
    g+=i;
    func3();
  }
  return g;
}

int GprofSample::func2(void) {
  int i=0;
  int g=0;
  while(i++ < 40000) {
    g+=i;
  }
  return g;
}

int GprofSample::func3() {
  int i=0;
  int g=0;
  while(i++ < 1000) {
    g++;
  }
  return g;
}

int main(int argc, char** argv) {
  int iterations = 1000;
  std::cout<<"Number of iterations = "<<iterations<<std::endl;
  GprofSample gs;
  while(iterations--) {
    gs.func1();
    gs.func2();
  }
}
