#include <bitset>
#include <iostream>
#include <string>
#include <algorithm>

class Solution
{
public:
    int hammingWeight(int n)
    {
        std::bitset<32> b(n);
        std::string bits = b.to_string();
        int cnt = std::count(bits.begin(), bits.end(), '1');
        return cnt;
    }
};

int main()
{
    Solution s;
    s.hammingWeight(11);
}