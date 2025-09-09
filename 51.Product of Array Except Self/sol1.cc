#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int size = nums.size();
        vector<int> answer(size, 1);

        long long left = 1;
        for (int i = 0; i < size; i++)
        {
            answer[i] = left;
            left *= nums[i];
        }

        long long right = 1;
        for (int i = size; i >= 0; i--)
        {
            answer[i] *= right;
            right *= nums[i];
        }

        return answer;
    }
};

int main()
{
    Solution s;
    vector<int> input = {1, 2, 3, 4};

    vector<int> res = s.productExceptSelf(input);
}