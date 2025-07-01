#include <vector>
#include <numeric>

using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        return sumToN(nums.size()) - sum;
    }

    int sumToN(int n)
    {
        if (n == 0 || n == 1)
            return n;
        return n + sumToN(n - 1);
    }
};