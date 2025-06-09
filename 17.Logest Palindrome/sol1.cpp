#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int longestPalindrome(string s)
    {
        unordered_map<char, int> m;
        int res = 0;

        for (char c : s)
        {
            if (m.find(c) != m.end())
            {
                res += 2;
                m.erase(c);
            }
            else
            {
                m[c]++;
            }
        }

        if (m.size() > 0)
        {
            return res + 1;
        }
        else
        {
            return res;
        }
    }
};