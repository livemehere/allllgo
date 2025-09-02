#include <iostream>
#include <numeric>
#include <vector>
#include <string>
#include <regex>
#include <queue>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::queue;


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::regex n_regex("^-?\\d+$");

        int sum =0;
        queue<int> q;

        for (const string& s : tokens) {
            if (std::regex_match(s,n_regex)) {
                cout << "push" << s << endl;
                q.push(stoi(s));
                if (q.size() == 3) {
                    sum += q.front();
                    q.pop();
                }
            }else {
                cout << "op" << s << endl;
                int acc = q.front();
                q.pop();
                while (!q.empty()) {
                    if (s == "+") return acc+q.front();
                    if (s == "/") return acc/q.front();
                    if (s == "*") return acc*q.front();
                    if (s == "-") return acc-q.front();
                    q.pop();
                }
                cout << "pop" << acc << endl;
                sum+=acc;
                cout << acc << endl;

            }
        }
        return sum;
    }
};

int main() {
    Solution s;
    vector<string> input = {"4","13","5","/","+"};
    auto res = s.evalRPN(input);
    cout << "res :"<< res << endl;

    return 0;
}