#include <vector>
#include <unordered_map>
#include <utility>

using namespace std;

class Solution
{
public:
    void dfs(int x, int y, vector<vector<char>> &grid, vector<vector<bool>> &visited)
    {

        int m = grid.size();
        int n = grid[0].size();

        visited[x][y] = true; // check visited

        vector<pair<int, int>> dirs = {
            {0, -1},
            {1, 0},
            {0, 1},
            {-1, 0}};
        // 상하좌우 1인지 체크
        for (pair<int, int> dir : dirs)
        {
            int nx = x + dir.first;
            int ny = y + dir.second;

            // overflow case
            if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                continue;

            int v = grid[nx][ny];
            if (v == '1' && !visited[nx][ny])
            { // if land
              // and if not visited

                dfs(nx, ny, grid, visited); // deep into
            }
            else
            {
                // water
            }
        }
        // 아니면 끝냄
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1' && !visited[i][j])
                {

                    dfs(i, j, grid, visited);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};