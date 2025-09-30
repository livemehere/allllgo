#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<int> candidates;
    vector<vector<int>> res;
    vector<int> path;

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        this->candidates = candidates;
        sort(candidates.begin(), candidates.end());
        dfs(0, target);
    }

    void dfs(int startIdx, int remain)
    {
        if (remain == 0)
        {
            this->res.push_back(path);
            return;
        }
        for (int i = startIdx; i < this->candidates.size(); i++)
        {
            int v = this->candidates[i];
            if (v > remain)
            {
                break;
            }

            dfs(i, remain - v);
            this->path.pop_back();
        }
    }
};

int main()
{

    Solution s;

    return 0;
}