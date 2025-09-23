#include <vector>
#include <queue>
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {

        int n = nums.size();
        int left = 0;
        int right = n - 1;

        if (n == 1)
        {
            if (target == nums[0])
                return 0;
            return -1;
        };

        int pivotIdx = 1;
        while (nums[0] > nums[pivotIdx++])
        {
        };

        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[left] == target)
                return left;
            if (nums[right] == target)
                return right;

            if (target < nums[right] || target > nums[left])
            {
                left = mid + 1;
                mid = (mid + right) / 2;
            }
            else
            {
                right = mid - 1;
                mid = (left + mid) / 2;
            }
        }

        return -1;
    }
};

int main()
{

    Solution s;

    vector<int> nums = {
        4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    cout << s.search(nums, target) << endl;

    return 0;
}