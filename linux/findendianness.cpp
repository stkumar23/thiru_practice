// Program to find the endianness of a system
// Checks whether the system follows big-endian or little-endian
// Endianness defines the bytes sequence of memory storage.
// Big-endian: MSB at smallest memory location
// Little-endian: LSB at smallest memory location

// Big-endian:
// Value:    00 00 00 01
// Memory:   A1 A2 A3 A4

// Little-endian:
// Value:    00 00 00 01
// Memory:   A4 A3 A2 A1

#include <iostream>
#include <cstdint>

// Function to check whether the system follows big-endian or not
bool isBigEndian() {
  uint16_t word = 1; //0x0001
  uint8_t *bytes = (uint8_t*) &word;
  return bytes[0] = 0;
}

// main
int main()
{
  std::cout<<(isBigEndian() ? "Big-endian" : "Little-endian")<<std::endl;

  return 0;
}
