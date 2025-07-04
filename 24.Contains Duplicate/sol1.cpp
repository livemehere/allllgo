#include <vector>
#include <set>

using std::vector;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        std::set<int> s;

        for (int n : nums)
        {
            if (s.find(n) != s.end())
            {
                return true;
            }
            s.insert(n);
        }
        return false;
    }
};