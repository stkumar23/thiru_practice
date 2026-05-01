// Modern C++ - C++23 - if consteval
// 
// if consteval is a compile-time branch introduced in C++23
//
// Basic syntax:
// if consteval {
//     Runs during constant evaluation (compile-time)
// } else {
//     Runs only at runtime
// }
//
// It is a language keyword, no headers needed.
// No parenthesis needed if (consteval), no condition expression (if consteval (x > 1))
// Negation allowed if !consteval
//
// Compile with -std=c++23
// 
// Author: Thiru


#include <print> // for std::println

constexpr unsigned int square(unsigned int x) {
   if consteval {
      return x*x;
   } else {
      std::println("run time");
      return x*x;
   }
}

int main() {
   // This invokes the compile time branch
   constexpr unsigned int compiletime = square(4);
   std::println("compiletime {}", compiletime);

   // This invokes the runtime branch
   unsigned int runtime = square(4);
   std::println("runtime {}", runtime);

   return 0;
}
