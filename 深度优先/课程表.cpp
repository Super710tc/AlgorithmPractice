/*现在你总共有 n 门课需要选，记为 0 到 n-1。

在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们: [0,1]

给定课程总量以及它们的先决条件，判断是否可能完成所有课程的学习？

示例 1:

输入: 2, [[1,0]] 
输出: true
解释: 总共有 2 门课程。学习课程 1 之前，你需要完成课程 0。所以这是可能的。
示例 2:

输入: 2, [[1,0],[0,1]]
输出: false
解释: 总共有 2 门课程。学习课程 1 之前，你需要先完成​课程 0；并且学习课程 0 之前，你还应先完成课程 1。这是不可能的。
说明:

输入的先决条件是由边缘列表表示的图形，而不是邻接矩阵。详情请参见图的表示法。
你可以假定输入的先决条件中没有重复的边。*/
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int,int>>& prerequisites) {
        vector<vector<int> > graph(numCourses, vector<int>(0));
        vector<int> degree(numCourses, 0);
        for (auto a : prerequisites) {
            graph[a.second].push_back(a.first);
            ++degree[a.first];
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (degree[i] == 0) q.push(i);
        }
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            for (auto a : graph[t]) {
                --degree[a];
                if (degree[a] == 0) q.push(a);
            }
        }
        for (int i = 0; i < numCourses; ++i) {
            if (degree[i] != 0) return false;
        }
        return true;
    }
};