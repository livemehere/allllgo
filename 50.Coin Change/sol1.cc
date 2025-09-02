#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;

        for (int i=1; i <= amount; i++) {
            for (int coin : coins) {
                int prev = i - coin;
                if (prev >= 0) {
                    dp[i] = std::min(dp[i],dp[prev]+1);
                }
            }
        }

        if (dp[amount] == amount+1) return -1;
        return dp[amount];

    }
};

int main()
{

    Solution s;
    vector<int> coins = {
        1,2,5
    };
    s.coinChange(coins, 11);



    return 0;
}