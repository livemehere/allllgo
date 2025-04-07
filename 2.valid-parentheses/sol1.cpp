#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution {
    public:
        bool isValid(string s) {
            if(s.size() % 2 !=0) return false;
            unordered_map<char,char> map = {
                {'(',')'},
                {'[',']'},
                {'{','}'}
            };
            stack<char> stack;

            for(char c : s){
                if(map.find(c) != map.end()){
                    stack.push(map[c]);
                } else {
                    if(stack.empty() || stack.top() != c) return false;
                    stack.pop();
                }
            }

            return stack.empty();
        }
};


int main(){
    Solution s;
    string s1 = "()";
    string s2 = "()[]{}";
    string s3 = "(]";
    string s4 = "([)]";
    string s5 = "{[]}";
    string s6 = "){";

    cout << "Result: " << s.isValid(s1) << endl;
    cout << "Result: " << s.isValid(s2) << endl;
    cout << "Result: " << s.isValid(s3) << endl;
    cout << "Result: " << s.isValid(s4) << endl;
    cout << "Result: " << s.isValid(s5) << endl;
    cout << "Result: " << s.isValid(s6) << endl;
     

    return 0;
}