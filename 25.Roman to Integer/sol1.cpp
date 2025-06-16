#include <string>
#include <unordered_map>

using std::string;

class Solution
{
public:
    int romanToInt(string s)
    {
        std::unordered_map<char, int> m = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
        };

        std::unordered_map<char, char> subM = {
            {'V', 'I'},
            {'X', 'I'},
            {'L', 'X'},
            {'C', 'X'},
            {'D', 'C'},
            {'M', 'C'},
        };
        int sum = 0;
        char subChar;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            char c = s[i];
            int v = m[c];
            if (subChar == c)
            {
                sum -= v;
            }
            else
            {
                sum += v;
            }
            subChar = subM[c];
        }
        return sum;
    }
};