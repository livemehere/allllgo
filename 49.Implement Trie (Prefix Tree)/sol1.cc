#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::vector;
using std::string;

class Trie {
private:
    vector<string>data;
public:
    Trie() {

    }

    void insert(string word) {
        data.push_back(word);
    }

    bool search(string word) {
        for (auto w : data) {
            if (w == word) {
                return true;
            }
        }
        return false;
    }

    bool startsWith(string prefix) {
        for (auto w : data) {
            if (w.starts_with(prefix)) {
                return true;
            }
        }
        return false;
    }
};



int main()
{
    Trie* obj = new Trie();
    obj->insert(word);
    bool param_2 = obj->search(word);
    bool param_3 = obj->startsWith(prefix);

    return 0;
}