#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {

        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[0] < b[0]; }); // true = a front, false = a back

        vector<vector<int>> merged;
        merged.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++)
        {
            vector<int> &last = merged.back();
            vector<int> &cur = intervals[i];

            // overlab
            if (cur[0] <= last[1])
            {
                last[1] = max(cur[1], last[1]);
            }
            else
            {
                merged.push_back(cur);
            }
        }

        return merged;
    }
};

int main()
{

    Solution s;

    vector<vector<int>> intervals = {
        {2, 6},
        {1, 3},
        {8, 10}};
    auto merged = s.merge(intervals);

    return 0;
}