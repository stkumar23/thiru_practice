# LeetCode - 204 - Count Primes
# Given an integer n, return the number of prime numbers that are
# strictly less than n.
#
# ex: n = 10 => 4 (2,3,5,7)
# ex: n = 1 => 0
# ex: n = 0 => 0
#
# Author: Thiru
#
# Time complexity: O(nlog(logn))
# Space complexity: O(n)

from typing import List
import math

class CountPrimes204:

  # Function to count the number of primes less than n
  # Using Sieve of Eratosthenes algorithm to count the primes
  # Initialize array of n boolean set to true
  # Iterate through the loop, starting from i (2) and in multiples of i (2...),
  # which is less than n, set the bool array index to false.
  # This is because all these indices are divisible by that i, which is not prime.
  # Finally, count the prime entries (which is set to true in boolean array).
  def countPrimes(self, n: int) -> int:
      if n <= 1:
          return 0

      isPrime = [True]*n
      isPrime[0] = isPrime[1] = False

      for i in range(2, int(math.sqrt(n))+1):
          if isPrime[i]:
              for j in range(i+i, n, i):
                  isPrime[j] = False

      return isPrime.count(True)

# main
obj = CountPrimes204()

n = 10
print("Number of primes ", obj.countPrimes(n))
