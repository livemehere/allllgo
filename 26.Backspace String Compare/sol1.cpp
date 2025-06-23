#include <string>
#include <iostream>

using std::string;

class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        int si = 0;
        int ti = 0;
        char sc = s[si];
        char tc = t[ti];
        int sLen = s.size();
        int tLen = t.size();
        string sr = "";
        string tr = "";
        while (sc || tc)
        {
            std::cout << sc << std::endl;

            if (sc == '#' && !sr.empty())
            {
                sr.pop_back();
            }
            else if (sc && sc != '#')
            {
                sr += sc;
            }

            if (tc == '#' && !tr.empty())
            {
                tr.pop_back();
            }
            else if (tc && tc != '#')
            {
                tr += tc;
            }

            std::cout << "cur: " << sr << std::endl;

            sc = (si < sLen) ? s[++si] : '\0';
            tc = (ti < tLen) ? t[++ti] : '\0';
        }

        std::cout << sr << " | " << tr << std::endl;

        return sr == tr;
    }
};