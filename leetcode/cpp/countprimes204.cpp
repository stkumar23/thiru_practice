// LeetCode - 204 - Count Primes
// Given an integer n, return the number of prime numbers that are
// strictly less than n.
//
// ex: n = 10 => 4 (2,3,5,7)
// ex: n = 1 => 0
// ex: n = 0 => 0
//
// Author: Thiru
//
// Time complexity: O(nlog(logn))
// Space complexity: O(n)

#include <iostream>
#include <cmath>

// Function to count the number of primes less than n
// Using Sieve of Eratosthenes algorithm to count the primes
// Initialize array of n boolean set to true
// Iterate through the loop, starting from i (2) and in multiples of i (2...),
// which is less than n, set the bool array index to false.
// This is because all these indices are divisible by that i, which is not prime.
// Finally, count the prime entries (which is set to true in boolean array).

int countPrimes(int n) {
  int primeCount = 0;

  if (n <= 2) {
    return primeCount;
  }

  bool isPrime[n];
  for (int i = 2; i <n; i++) {
    isPrime[i] = true;
  }

  for (int i = 2; i <= sqrt(n); i++) {
    if (isPrime[i]) {
      for (int j = i+i; j < n; j += i) {
        isPrime[j] = false;
      }
    }
  }

  for (int i = 2; i <n; i++) {
    if (isPrime[i]) {
      primeCount++;
    }
  }

  return primeCount;
}

int main() {
  int n = 10;
  // int n = 0;
  // int n = 1;
  std::cout<< "Number of primes " << countPrimes(n) << std::endl;
  return 0;
}
