#include <iostream>
#include <string>
#include <regex>

using namespace std;

class Solution {
    public:
        bool isPalindrome(string s) {
            string filtered;
            for (char& c : s){
                // using a lighter check instead of regex for better performance
                if(isalnum(c)){
                    filtered += tolower(c);
                }
            }
            int left = 0;
            int right = filtered.size() - 1;
            bool result = true;
            while(left < right){
                if(filtered[left] != filtered[right]){
                    result = false;
                    break;
                }
                left++;
                right--;
            }
            return result;
        }
    };

int main(){

    Solution s;
    cout << s.isPalindrome("race a car") << endl;

    return 0;
}