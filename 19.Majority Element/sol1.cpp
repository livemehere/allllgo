#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        float v = nums.size() / 2;
        unordered_map<int, int> m;

        for (int n : nums)
        {
            int _v = m.find(n) != m.end() ? m[n] : 1;
            if (_v > v)
                return n;
            m[n] = _v + 1;
        }

        return 0;
    }
};