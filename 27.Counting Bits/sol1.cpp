#include <iostream>

#include <vector>
#include <bitset>
#include <algorithm>
#include <string>

using std::string;
using std::vector;

template <typename T>
void print_vector(const std::vector<T> &vec)
{
    std::cout << "[";
    for (size_t i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i];
        if (i != vec.size() - 1)
            std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> res;
        for (int i = 0; i <= n; i++)
        {
            std::bitset<64> b(i);
            std::string b_str = b.to_string();
            int cnt = std::count(b_str.begin(), b_str.end(), '1');
            std::cout << cnt << std::endl;
            res.push_back(cnt);
        }
        return res;
    }
};

int main()
{
    Solution s;
    print_vector(s.countBits(5));
    return 0;
}