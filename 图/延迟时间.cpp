
/*有 N 个网络节点，标记为 1 到 N。

给定一个列表 times，表示信号经过有向边的传递时间。 times[i] = (u, v, w)，其中 u 是源节点，v 是目标节点， w 是一个信号从源节点传递到目标节点的时间。

现在，我们向当前的节点 K 发送了一个信号。需要多久才能使所有节点都收到信号？如果不能使所有节点收到信号，返回 -1。

注意:

N 的范围在 [1, 100] 之间。
K 的范围在 [1, N] 之间。
times 的长度在 [1, 6000] 之间。
所有的边 times[i] = (u, v, w) 都有 1 <= u, v <= N 且 0 <= w <= 100。*/
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
         vector<vector<int> > edge(N+1,vector<int>(N+1,-1));
        vector<bool> visited(N+1,false);
        for(auto e:times) edge[e[0]][e[1]]=e[2];
        queue<int> q;
        vector<int> dis(N+1,INT_MAX);
        dis[K]=0;
        int res=0;
        for(int j=1;j<=N;j++)
        {
            int u=-1,min=INT_MAX;
            for(int i=1;i<=N;i++)
            {
                if(dis[i]<min&&visited[i]==false)
                {
                    u=i;
                    min=dis[u];
                }
            }
            if(u==-1) break;//若都被访问了，就break循环
            visited[u]=true;//标记已被访问，这步很重要，
            for(int v=1;v<=N;v++)
            {
                if(edge[u][v]!=-1&&!visited[v]&&dis[v]>edge[u][v]+dis[u])
                {
                    dis[v]=dis[u]+edge[u][v];
                }
            }
            
        }
            
        for(int i=1;i<=N;i++)
        {
            
            res=max(res,dis[i]);
        }
        return res==INT_MAX?-1:res;
    }
};