#include <cmath>

// The API isBadVersion is defined for you.
bool isBadVersion(int version);

class Solution
{
public:
    int firstBadVersion(int n)
    {
        if (isBadVersion(1))
            return 1;

        unsigned int left = 1;
        unsigned int right = n;
        unsigned int latestGood = left;
        unsigned int latestBad = n;

        while (left < right)
        {
            unsigned int mid = std::floor((left + right) / 2);
            if (isBadVersion(mid))
            {
                right = mid;
                latestBad = mid;
            }
            else
            {
                left = mid;
                latestGood = mid;
            }
            if (latestBad - latestGood <= 1)
                return latestBad;
        }
        return latestBad;
    }
};