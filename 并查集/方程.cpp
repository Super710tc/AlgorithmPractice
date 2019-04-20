
/*给定一个由表示变量之间关系的字符串方程组成的数组，每个字符串方程 equations[i] 的长度为 4，并采用两种不同的形式之一："a==b" 或 "a!=b"。在这里，a 和 b 是小写字母（不一定不同），表示单字母变量名。

只有当可以将整数分配给变量名，以便满足所有给定的方程时才返回 true，否则返回 false。 

 

示例 1：

输入：["a==b","b!=a"]
输出：false
解释：如果我们指定，a = 1 且 b = 1，那么可以满足第一个方程，但无法满足第二个方程。没有办法分配变量同时满足这两个方程。*/
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
    // union_find
        vector<int> poss_parents(26,0);
        for(int i=0;i<poss_parents.size();i++)
        {
            poss_parents[i] = i;
        }
        for(auto equ:equations)
        {
            if(equ[1]=='=')
                poss_parents[find(equ[0]-'a',poss_parents)] = find(equ[3]-'a',poss_parents);
        }
        
        // for(int i=0;i<poss_parents.size();i++)
        // {
        //     char out='a'+i;
        //     cout<<out<<" "<<poss_parents[i]<<endl;
        // }
        for(auto equ:equations)
        {
            if(equ[1]=='!')
                if(find(equ[0]-'a',poss_parents)==find(equ[3]-'a',poss_parents))
                    return false;
        }
        return true;
        
    }
    int find(int x,vector<int> &poss_parents){
        if(x!=poss_parents[x])
        {
            poss_parents[x] = find(poss_parents[x],poss_parents);
        }
        return poss_parents[x];
    }

};