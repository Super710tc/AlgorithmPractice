
/*
定一个包含了一些 0 和 1的非空二维数组 grid , 一个 岛屿 是由四个方向 (水平或垂直) 的 1 (代表土地) 构成的组合。你可以假设二维矩阵的四个边缘都被水包围着。

找到给定的二维数组中最大的岛屿面积。(如果没有岛屿，则返回面积为0。)

示例 1:

[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
*/
class Solution {
private:
    int m,n;
    int maxa = 0,count = 0;;
    //由某个点dfs的四个方向
    int d[4][2] = {{0,-1},{1,0},{0,1},{-1,0}};
    
    vector<vector<bool>> visited;
    
    bool inArea(int x,int y){//判断是否出边界
        return x>=0&&x<m&&y>=0&&y<n;
    }
    //dfs
    void dfs(int x,int y,vector<vector<int>>& grid){
        count++;
        visited[x][y] = true;
        for(int k = 0;k<4;k++){
            int newx = x+d[k][0];
            int newy = y+d[k][1];
            if(inArea(newx,newy)&&!visited[newx][newy]&&grid[newx][newy])
                dfs(newx,newy,grid);
        }
    }
    
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        //创建一个记录是否被访问的数组
        if(grid.size()==0) return 0;
        m = grid.size();
        if(grid[0].size()==0) return 0;
        n = grid[0].size();
        //初始化visited
        for(int i=0;i<m;i++) visited.push_back(vector<bool>(n,false));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j]&&grid[i][j]){//遍历数组 如果该点没有被访问过 并且为1 则开始dfs
                    count = 0;
                    dfs(i,j,grid);
                    maxa = max(maxa,count);
                }
            }
        }
        return maxa;
    }
};