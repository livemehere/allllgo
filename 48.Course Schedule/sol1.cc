#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> graph(numCourses);
        // 0:미방문, 1:탐생중, 2:탐색끝
        vector<int> visited(numCourses,0);

        // 의존성 그래프 생성
        for (vector<int> courses : prerequisites) {
            graph[courses[1]].push_back(courses[0]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == 0 ) {
                if (hasCycle(graph, visited,i)) {
                    return false; // 사이클 있으니 종료
                }
            }
        }
        return true; // 사이클 없음
    }

    bool hasCycle(vector<vector<int>>& graph, vector<int>& visited, int node) { // TODO: &참조 전달 주의
        if (visited[node] == 1) return true; // 순환도중 사이클 발생
        if (visited[node] == 2) return false; // 이미 정상 탐색이 끝난 노드 -> 안전하게 바로 끝냄

        visited[node] = 1; // 탐색중 임을 마킹
        for (int nei : graph[node]) {
            if (hasCycle(graph, visited, nei)) {
                return true;
            }
        }

        visited[node] = 2; // 안전하게 탐색을 마쳤음을 마킹
        return false;
    }
};

int main()
{

    Solution s;
    vector<vector<int>> input = {
        {1,0},
        {0,1}
    };

    s.canFinish(2,input);


    return 0;
}