#include <vector>
#include <iostream>
#include <unordered_map>
#include <map>

using namespace std;

class TimeMap
{
private:
    unordered_map<string, map<int, string>> data;

public:
    TimeMap()
    {
    }

    void set(string key, string value, int timestamp)
    {
        data[key][timestamp] = value;
    }

    string get(string key, int timestamp)
    {
        if (data.find(key) == data.end())
        {
            return "";
        }

        auto &time_map = data[key];                // map 은 key(int) 에 대해 정렬된 상태로 저장됨
        auto it = time_map.upper_bound(timestamp); // key 보다 큰 첫번째 원소의 iterator 반환
        if (it == time_map.begin())                // 만약
        {
            return "";
        }
        --it;
        return it->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

int main()
{
    TimeMap *obj = new TimeMap();
    obj->set("foo", "bar", 1);
    string param_2 = obj->get("foo", 1);
    std::cout << param_2 << std::endl; // should output "bar"
    param_2 = obj->get("foo", 3);
    std::cout << param_2 << std::endl; // should output "bar"
    obj->set("foo", "bar2", 4);
    param_2 = obj->get("foo", 4);
    std::cout << param_2 << std::endl; // should output "bar2"
    param_2 = obj->get("foo", 5);
    std::cout << param_2 << std::endl; // should output "bar2"

    return 0;
}