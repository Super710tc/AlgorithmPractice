/*
对于一个具有树特征的无向图，我们可选择任何一个节点作为根。图因此可以成为树，在所有可能的树中，具有最小高度的树被称为最小高度树。给出这样的一个图，写出一个函数找到所有的最小高度树并返回他们的根节点。

格式

该图包含 n 个节点，标记为 0 到 n - 1。给定数字 n 和一个无向边 edges 列表（每一个边都是一对标签）。

你可以假设没有重复的边会出现在 edges 中。由于所有的边都是无向边， [0, 1]和 [1, 0] 是相同的，因此不会同时出现在 edges 里。

示例 1:

输入: n = 4, edges = [[1, 0], [1, 2], [1, 3]]

        0
        |
        1
       / \
      2   3 

输出: [1]*/
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if (edges.empty()) return {0};
        vector<set<int>> graph(n, set<int>());
        for (auto& edge:edges) {
            graph[edge.first].insert(edge.second);
            graph[edge.second].insert(edge.first);
        }
        vector<int> res;
        int u, v;
        int orig_n = n;
        vector<bool> nb(n, true);
        while (n > 2) {
            vector<pair<int, int>> l;
            for (u = 0; u < orig_n; ++u) {
                if (graph[u].size() == 1) {
                    v = *graph[u].begin();
                    l.push_back(make_pair(u, v));
                }
            }
            for (auto& lp:l) {
                u = lp.first;
                v = lp.second;
                graph[u].erase(v);
                graph[v].erase(u);
                n -= 1;
                nb[u] = false;
            }
        }
        
        for (int i = 0; i < orig_n; ++i) {
            if (nb[i]) res.push_back(i);
        }
        
        return res;
    }
};