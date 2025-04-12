#include <iostream>
#include <string>
#include <regex>

using namespace std;

class Solution {
    public:
        bool isPalindrome(string s) {
            // string filtered;
            // for (char& c : s){
            //     // using a lighter check instead of regex for better performance
            //     if(isalnum(c)){
            //         filtered += tolower(c);
            //     }
            // }

            // Optimize unnecessary operations by validating characters during traversal.
            // instead of filtering the entire string beforehand
            int left = 0;
            int right = s.size() - 1;
            while(left < right){
                while(left < right && !isalnum(s[left])) left++;
                while(left < right && !isalnum(s[right])) right--;
                if(tolower(s[left]) != tolower(s[right])) return false;
                left++;
                right--;
            }
            return true;
        }
    };

int main(){

    Solution s;
    cout << s.isPalindrome("race a car") << endl;

    return 0;
}