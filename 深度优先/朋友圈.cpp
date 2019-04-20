/*班上有 N 名学生。其中有些人是朋友，有些则不是。他们的友谊具有是传递性。如果已知 A 是 B 的朋友，B 是 C 的朋友，那么我们可以认为 A 也是 C 的朋友。所谓的朋友圈，是指所有朋友的集合。

给定一个 N * N 的矩阵 M，表示班级中学生之间的朋友关系。如果M[i][j] = 1，表示已知第 i 个和 j 个学生互为朋友关系，否则为不知道。你必须输出所有学生中的已知的朋友圈总数。

示例 1:

输入: 
[[1,1,0],
 [1,1,0],
 [0,0,1]]
输出: 2 
说明：已知学生0和学生1互为朋友，他们在一个朋友圈。
第2个学生自己在一个朋友圈。所以返回2。*/
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int result = 0, N = M.size();
        vector<bool> visited(N, false);//标记是否访问
        for (int index = 0; index < N; ++index){
            //寻找没有访问过的学生
            if (visited[index] == false){
                result += 1;
                visited[index] = true;//标记访问
                dfs(M, visited, index);//深度遍历index所在的朋友圈中的所有朋友
            }
        }
        return result;
    }
    //访问所有在nowIndex所在的朋友圈中还未访问的朋友
    void dfs(vector<vector<int>>& M, vector<bool> &visited, int nowIndex){
        int N = M.size();
        //穷举所有的学生
        for (int index = 0; index < N; ++index){
            //nowIndex与index是朋友，且index没有访问过
            if (M[nowIndex][index] == 1 && visited[index] == false){
                visited[index] = true;//标记访问
                dfs(M, visited, index);//深度遍历index的朋友
            }
        }
    }
};