#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            map<int,int> m;

            for(int i=0;i<nums.size();i++){
                int cur = nums[i];
                // target = cur + x
                int x = target - cur;
                if(m.find(x) != m.end()){
                    return {m[x],i};
                }
                m[cur] = i;
            }
            return {-1,-1};
        }
};

int main(){
    Solution s;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = s.twoSum(nums,target);
    cout << "Result: " << result[0] << ", " << result[1] << endl;

    return 0;
}