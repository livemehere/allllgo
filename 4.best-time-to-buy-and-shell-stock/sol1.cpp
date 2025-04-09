#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int minPrice = prices[0];
            int profit = 0;
            for(int i=1;i<prices.size();i++){
                int cur = prices[i];
                profit  = max(profit, cur - minPrice);
                minPrice = min(minPrice, cur);
            }
            return profit;
        }
};
int main(){

    return 0;
}