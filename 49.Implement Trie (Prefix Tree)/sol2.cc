#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::array;

struct Node {
    array<Node*,26> child{}; // 알파뱃 소문자 갯수 (문제 제약)
    bool isEnd = false;
    Node() {
      child.fill(nullptr);
    }
};

class Trie {
private:
    Node * root;
public:
    Trie() : root(new Node()) {}
    ~Trie() {
        delete root;
    }

    void insert(string word) {
        Node* cur = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!cur->child[idx]) {
                cur->child[idx] = new Node(); // 문자열 트리를 만들어감
            }
            cur = cur->child[idx];
        };
        cur->isEnd = true;
    }

    bool search(string word) {
        Node* cur = root;
        for (char c : word) {
            int idx = c - 'a';
            cur = cur->child[idx];
            if (!cur) return false;
        }
        return cur->isEnd; // 더이상 없어야함.
    }

    bool startsWith(string prefix) {
        Node* cur = root;
        for (char c : prefix) {
            int idx = c - 'a';
            cur = cur->child[idx];
            if (!cur) return false;
        }
        return true; // 있든 없든, prefix 만큼 찾았으면 끝
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