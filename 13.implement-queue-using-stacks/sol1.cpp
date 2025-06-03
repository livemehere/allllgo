#include <list>

class MyQueue
{
private:
    std::list<int> stack;

public:
    MyQueue()
    {
    }

    void push(int x)
    {
        this->stack.push_back(x);
    }

    int pop()
    {
        int v = this->stack.front();
        this->stack.pop_front();
        return v;
    }

    int peek()
    {
        return this->stack.front();
    }

    bool empty()
    {
        return this->stack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */