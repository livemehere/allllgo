#include <iostream>
#include <string>
#include <regex>

using namespace std;

class Solution {
    public:
        bool isPalindrome(string s) {
            for (char& c : s){
                c = tolower(c);
            }
            regex r = regex("[^0-9a-zA-Z]");
            s = regex_replace(s,r,"");
            int size = s.size();

            int left = 0;
            int right = size - 1;
            bool result = true;
            while(left < right){
                if(s[left] != s[right]){
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