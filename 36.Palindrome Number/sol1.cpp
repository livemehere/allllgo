#include <string>
#include <iostream>
#include <algorithm>

class Solution
{
public:
    bool isPalindrome(int x)
    {
        std::string str = std::to_string(x);
        std::string reversed;
        std::copy(str.rbegin(), str.rend(), std::back_inserter(reversed));
        return str == reversed;
    }
};

int main()
{
    Solution s;
    std::cout << s.isPalindrome(1212);
}