#include <string>
#include <unordered_map>

using namespace std;

class Solution {
    public:
        bool isAnagram(string s, string t) {
            if(s.size() != t.size()) return false;
            unordered_map<char,short> m;
            for(char c : s){
                m[c] = m[c] ? m[c]+1 : 1;
            }
            for(char c : t){
                if(m.find(c) != m.end() && m[c] > 0){
                    m[c] -= 1;
                }else{
                    return false;
                }
            }
            return true;
        }
};

int main(){
    return 0;
}