#include <vector>
#include <climits>

using std::vector;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int curSum = 0;
        int maxSum = INT_MIN;

        for (int n : nums)
        {
            curSum = std::max(curSum + n, n);
            maxSum = std::max(curSum, maxSum);
        }

        return maxSum;
    }
};