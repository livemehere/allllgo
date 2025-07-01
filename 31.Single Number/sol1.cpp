#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        unordered_map<int, int> m;

        for (int n : nums)
        {
            if (m.find(n) == m.end())
            {
                // first
                m[n] = 1;
            }
            else
            {
                // second
                m.erase(n);
            }
        }

        return m.begin()->first;
    }
};