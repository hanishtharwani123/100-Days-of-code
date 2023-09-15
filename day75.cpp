// 75. Course Schedule
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> inDegree(numCourses, 0);

        // Build the adjacency list and calculate in-degrees for each course
        for (const auto& pre : prerequisites) {
            int course = pre[0];
            int prerequisite = pre[1];
            graph[prerequisite].push_back(course);
            inDegree[course]++;
        }

        queue<int> q;

        // Add courses with no prerequisites to the queue
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        int coursesTaken = 0;

        // Perform topological sort
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            coursesTaken++;

            for (int neighbor : graph[course]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return coursesTaken == numCourses;
    }
};

int main() {
    Solution solution;

    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1, 0}};

    bool result = solution.canFinish(numCourses, prerequisites);

    if (result) {
        cout << "It is possible to finish all courses." << endl;
    } else {
        cout << "It is not possible to finish all courses." << endl;
    }

    return 0;
}
