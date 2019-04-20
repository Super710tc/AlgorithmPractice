
/*有 N 个房间，开始时你位于 0 号房间。每个房间有不同的号码：0，1，2，...，N-1，并且房间里可能有一些钥匙能使你进入下一个房间。

在形式上，对于每个房间 i 都有一个钥匙列表 rooms[i]，每个钥匙 rooms[i][j] 由 [0,1，...，N-1] 中的一个整数表示，其中 N = rooms.length。 钥匙 rooms[i][j] = v 可以打开编号为 v 的房间。

最初，除 0 号房间外的其余所有房间都被锁住。

你可以自由地在房间之间来回走动。

如果能进入每个房间返回 true，否则返回 false。

示例 1：

输入: [[1],[2],[3],[]]
输出: true
解释:  
我们从 0 号房间开始，拿到钥匙 1。
之后我们去 1 号房间，拿到钥匙 2。
然后我们去 2 号房间，拿到钥匙 3。
最后我们去了 3 号房间。
由于我们能够进入每个房间，我们返回 true。*/
class Solution {
public:
    bool dfs(int key, vector<int>& marked, vector<vector<int>>& rooms, int& count)
    {
        marked[key] = 1;    // 标志这个房间已经访问过了
        ++count;        // 访问过的房间数目加1
        if(count == rooms.size()) // 计算如果访问房间的数目已经等于总的房间数目 那么说明已经全部访问完毕了 
            return true;
        for(auto i : rooms[key])
        {
            if(!marked[i])
            {               
                if(dfs(i, marked, rooms, count))
                    return true;
            }            
        }
        return false;
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> marked(rooms.size(), 0);
        int count = 0;
        return dfs(0, marked, rooms, count);
    }
};