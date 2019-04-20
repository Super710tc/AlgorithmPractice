/*n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。*/

class Solution {
public:
    vector<vector<string>> vvs;
    vector<string> vs;
    int len;
    bool isvalid(int**a,int x,int y)
    {
        for(int i=0;i<y;i++)
            if(a[x][i]==1)
                return false;
        for(int i=x-1,j=y-1;i>=0&&j>=0;i--,j--)
            if(a[i][j]==1)
                return false;
        for(int i=x+1,j=y-1;i<len&&j>=0;i++,j--)
            if(a[i][j]==1)
                return false;
        return true;
    }
    void dfs(int**a,int index)
    {
        if(index==len)
        {    
            vs.clear();
            for(int i=0;i<len;i++)
            {
                string s = "";
                for(int j=0;j<len;j++)
                    if(a[i][j]==1)
                        s += 'Q';
                    else
                        s += '.';
                vs.push_back(s);
            }
            vvs.push_back(vs);
            return;
        }
        for(int i=0;i<len;i++)
        {
            if(isvalid(a,i,index))
            {
                a[i][index] = 1;
                dfs(a,index+1);
                a[i][index] = 0;
            }
            
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        int** a = new int*[n];
        len = n;
        for(int i=0;i<n;i++)
        {
            a[i] = new int[n];
            fill(a[i],a[i]+n,0);            
        }
        dfs(a,0);
        return vvs;
    }
};