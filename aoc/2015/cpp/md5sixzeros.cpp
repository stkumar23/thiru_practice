// Santa needs help mining some AdventCoins (very similar to bitcoins) 
// to use as gifts for all the economically forward-thinking little girls and boys.
// To do this, he needs to find MD5 hashes which, in hexadecimal, start 
// with at least six zeroes. The input to the MD5 hash is some secret key 
// (your puzzle input, given below) followed by a number in decimal. 
//
// MD5 is deprecated since OpenSSL 3.0
// Install openssl-dev and link with library -lcrypto

#include <iostream>
#include <string>
#include <openssl/md5.h>
#include <sstream>
#include <iomanip>
#include <climits>  // INT_MAX
#include <string_view>

std::string md5(const std::string& str) {
    unsigned char digest[MD5_DIGEST_LENGTH];
    MD5(reinterpret_cast<const unsigned char*>(str.c_str()), str.length(), digest);

    std::ostringstream ss;
    ss << std::hex << std::setfill('0');
    for (int i = 0; i < MD5_DIGEST_LENGTH; ++i) {
        ss << std::setw(2) << static_cast<unsigned int>(digest[i]);
    }
    return ss.str();
}

int main() {
    std::string secretKey = "iwrupvqb";
    int lowestNumber{0};
    constexpr std::string_view match{"000000"};
    for (long i=0; i<INT_MAX; i++) {
        std::string input = secretKey + std::to_string(i);
        std::string hash = md5(input);
        if (hash.substr(0, match.size()) == match) {
            lowestNumber = i;
            std::cout<<"MD5 hash "<<hash<<std::endl;
            break;
        }
    }

    std::cout<<"Least positive number generating MD5 hash with leading six zeros "<<lowestNumber<<std::endl;

    return 0;
}