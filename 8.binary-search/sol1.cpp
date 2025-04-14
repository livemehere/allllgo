#include <vector>

using namespace std;

class Solution {
    public:
        int search(vector<int>& nums, int target) {
            int left=0,right=nums.size()-1;

            while(left<=right){
                int mid = (left+right)/2;
                int v = nums[mid];
                if(v==target) return mid;
                if(v>target){
                    right=mid-1;
                }else{
                    left=mid+1;
                }
            }
            return -1;
        }
    };
int main(){
    return 0;
}