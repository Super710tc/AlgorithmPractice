
/*在给定的二维二进制数组 A 中，存在两座岛。（岛是由四面相连的 1 形成的一个最大组。）

现在，我们可以将 0 变为 1，以使两座岛连接起来，变成一座岛。

返回必须翻转的 0 的最小数目。（可以保证答案至少是 1。）

 

示例 1：

输入：[[0,1],[1,0]]
输出：1*/
class Solution {
public:
    int shortestBridge(vector<vector<int>>& A) {
        if(A.empty()||A[0].empty())return 0;
        int m=A.size(),n=A[0].size();
        queue<pair<int,int>> q;
        bool find=false;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!find&&A[i][j]==1){
                    dfs(A,i,j);//把另一座岛全改为-1（dfs染色）
                    find=true;
                }
                if(find&&A[i][j]==1){
                    q.push(pair(i,j));//现在有一座全为1的岛和全为-1的岛，把为1的岛加入队列
                    // cout<<"("<<i<<","<<j<<") "<<endl;
                }
            }
        }
        while(!q.empty()){
            int dr[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
            pair<int,int> p=q.front();q.pop();
            int x=p.first,y=p.second;
            for(int i=0;i<4;i++){
                int nx=x+dr[i][0];
                int ny=y+dr[i][1];
                if(nx>=0&&nx<m&&ny>=0&&ny<n){
                    if(A[nx][ny]==0){//使得bfs只向一个方向进行
                        A[nx][ny]=A[x][y]+1;
                        q.push(pair(nx,ny));
                    }
                    else if(A[nx][ny]==-1) return A[x][y]-1;//终点
                }
            }
        }
        return 1;
    }
    
    void dfs(vector<vector<int>>& A,int i,int j){
        int m=A.size(),n=A[0].size();
        if(i<0||i>=m||j<0||j>=n)return;
        if(A[i][j]==-1||A[i][j]==0)return;
        A[i][j]=-1;
        dfs(A,i+1,j);dfs(A,i-1,j);dfs(A,i,j+1);dfs(A,i,j-1);
    }
};