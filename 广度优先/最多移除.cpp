/*在二维平面上，我们将石头放置在一些整数坐标点上。每个坐标点上最多只能有一块石头。

现在，move 操作将会移除与网格上的某一块石头共享一列或一行的一块石头。

我们最多能执行多少次 move 操作？

 

示例 1：

输入：stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
输出：5*/
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        vector<bool> v(stones.size(),false);
        int count = 0;
        for(int i =0;i<stones.size();i++){
            if(v[i]){
                continue;
            }
            f(stones,v,i);
            count++;
        }
        return stones.size()-count;
    }
    
    void f(vector<vector<int>>& stone,vector<bool>& visited,int start){
        visited[start] = true;
        queue<pair<int, int>> q;
        q.emplace(stone[start][0],stone[start][1]);
        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            for(int j = start+1;j<stone.size();j++){
                if((p.first==stone[j][0] || p.second==stone[j][1])&&!visited[j]){
                    q.emplace(stone[j][0],stone[j][1]);
                    visited[j] = true;
                }
            }
        }
    }
};