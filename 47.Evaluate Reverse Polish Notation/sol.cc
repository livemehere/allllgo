#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::vector;
using std::string;


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
       vector<int> stack;

        for (const string& t : tokens) {
            if (t == "+" || t == "-" || t == "*" || t == "/") {
                // 연산자 인 경우 2개를 꺼냄
                int b = stack.back(); // 나눗셈 때문에 순서가 역순
                stack.pop_back();
                int a = stack.back();
                stack.pop_back();

                // 연산후에 결과를 다시 push

                if (t == "+") {
                    stack.push_back(a+b);
                }else if (t=="-") {
                    stack.push_back(a-b);
                }else if (t=="/") {
                    stack.push_back(a/b);
                }else if (t == "*") {
                    stack.push_back(a*b);
                }
            }else {
                // 숫자인 경우 int 전환 후 push
                stack.push_back(stoi(t));
            }
        }

        return stack.back(); // 가장 마지막에는 1개의 연산결과만 남아있을 것
    }
};

int main() {
    Solution s;
    vector<string> input = {"4","13","5","/","+"};
    auto res = s.evalRPN(input);
    cout << "res :"<< res << endl;

    return 0;
}