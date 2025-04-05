// Sample gtest program
// Install googletest before running this program
// Run the below command to create a.out
// g++ -std=c++11 checknumdigittest.cpp checknumdigits.cpp -lgtest -lpthread
// Now run the a.out to start the test

#include <gtest/gtest.h>
#include "checknumdigits.h"

class CheckDigitTest : public testing::Test {
public:
  CheckDigitTest() {
  }

  ~CheckDigitTest() override = default;
};

// Test case - single digit
TEST(CheckDigitTest, SingleDigit) {
  int num = 8;
  CheckDigit obj;
  // expected true
  ASSERT_TRUE(obj.isSingleDigit(num)) << "Given number "<< num
                                  <<" is a single digit number";
}

// Test case - dobule digit
TEST(CheckDigitTest, NotASingleDigit) {
  int num = 16;
  CheckDigit obj;
  // expected false
  ASSERT_FALSE(obj.isSingleDigit(num)) << "Given number "<< num
                                    <<" is not a single digit number";
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
