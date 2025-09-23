#include <vector>
#include <queue>
#include <iostream>
#include <unordered_set>

using namespace std;

struct pair_hash
{
    inline std::size_t operator()(const std::pair<int, int> &v) const
    {
        return v.first * 31 + v.second;
    }
};

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int depth = 0;
        queue<pair<int, int>> q;

        int rowLen = grid.size();
        int colLen = grid[0].size();
        int fresh = 0;

        pair<int, int> dirs[4] = {
            {-1, 0}, // top
            {1, 0},  // bottom
            {0, -1}, // left
            {0, 1}   // right
        };

        for (int i = 0; i < rowLen; i++)
        {
            for (int j = 0; j < colLen; j++)
            {
                int v = grid[i][j];
                if (v == 2)
                {
                    q.push({i, j});
                }
                else if (v == 1)
                {
                    fresh++;
                }
            }
        }

        if (fresh == 0)
            return 0;

        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                pair<int, int> pos = q.front();

                for (auto dir : dirs)
                {
                    int row = pos.first + dir.first;
                    int col = pos.second + dir.second;

                    if (row < 0 || row >= rowLen || col < 0 || col >= colLen)
                        continue;

                    int v = grid[row][col];

                    if (v != 1)
                        continue;

                    grid[row][col] = 2;
                    q.push({row, col});
                    fresh--;
                }
                q.pop();
            }
            if (!q.empty())
            {
                depth++;
            }
        }

        return fresh != 0 ? -1 : depth;
    }
};

int main()
{

    Solution s;

    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1},
    };

    cout << s.orangesRotting(grid) << endl;

    return 0;
}