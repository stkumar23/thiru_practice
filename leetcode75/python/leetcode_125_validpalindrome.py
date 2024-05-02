# LeetCode - 125 - Valid Palindrome
# A phrase is a palindrome if, after converting all uppercase letters into
# lowercase letters and removing all non-alphanumeric characters, it reads the
# same forward and backward. Alphanumeric characters include letters and
# numbers. Given a string s, return true if it is a palindrome,
# or false otherwise.
# Ex: s = "A man, a plan, a canal: Panama" => true
#
# Author: Thiru
#
# Time complexity O(n)
# Space complexity O(1)

class Solution:
    # Function to check given string a palindrome or not
    # Use tow pointers, increment/decrement the counter if it encounters
    # non alphanumeric character. Compare the character at either end
    def isPalindrome(self, s: str) -> bool:
        i, j = 0, len(s)-1

        while i<j:
            while i<j and not s[i].isalnum():
                i+=1

            while i<j and not s[j].isalnum():
                j-=1

            if s[i].lower() != s[j].lower():
                return False
            i, j = i+1, j-1
        return True

# main
obj = Solution()

s = "A man, a plan, a canal: Panama"
print("Given string is palindrome", obj.isPalindrome(s))
