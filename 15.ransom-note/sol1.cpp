#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        unordered_map<char, int> m;
        for (char c : magazine)
        {
            m[c]++;
        }

        for (char c : ransomNote)
        {
            auto it = m.find(c);
            if (it == m.end())
                return false;
            int rest = (it->second) - 1;
            if (rest < 0)
                return false;
            m[c] = rest;
        }

        return true;
    };
};

int main()
{
    Solution s;

    bool r = s.canConstruct("aa", "aab");

    cout << r << endl;

    return 0;
}