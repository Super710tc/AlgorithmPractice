/*在第一行我们写上一个 0。接下来的每一行，将前一行中的0替换为01，1替换为10。

给定行数 N 和序数 K，返回第 N 行中第 K个字符。（K从1开始）


例子:

输入: N = 1, K = 1
输出: 0

输入: N = 2, K = 1
输出: 0*/
class Solution {
public:
    int kthGrammar(int N, int K) {
        if(N == 1)
            return 0;
        
        //上一列对应的值
        int ret = kthGrammar(N - 1, (K + 1) / 2);
        //本列对应的值
        return dp[ret][(K - 1) % 2];
    }
    
    int dp[2][2] = {{0, 1}, {1, 0}};
};