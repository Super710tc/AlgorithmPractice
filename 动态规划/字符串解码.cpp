/*
一条包含字母 A-Z 的消息通过以下方式进行了编码：

'A' -> 1
'B' -> 2
...
'Z' -> 26
给定一个只包含数字的非空字符串，请计算解码方法的总数。

示例 1:

输入: "12"
输出: 2
解释: 它可以解码为 "AB"（1 2）或者 "L"（12）。
示例 2:

输入: "226"
输出: 3
解释: 它可以解码为 "BZ" (2 26), "VF" (22 6), 或者 "BBF" (2 2 6) 。
*/
class Solution {
public:
    int numDecodings(string s) {
        int pre2 = 1, pre1 = 1, ans;//pre2=f(i-2); pre1=f(i-1); ans=f(i);
        if (s[0] == '0') return 0;//s的前置0要先处理
        if (s.size() == 1) return 1;//i从1开始，所以s.size()==1的情况要考虑到
        for (int i = 1; i < s.size(); i++) {
            ans = 0;//初始化f(i)=0;
            int num = (s[i-1]-'0')*10+(s[i]-'0');//计算前一个元素与当前元素合并的十进制值
            if (s[i] == '0') {//当前元素为'0'，不满足编码，向前看一个元素
                if (num != 10 && num != 20) break;//不是10也不是20，直接退出
                else ans += pre2;//10或者20，可以编码
            } else {//当前元素为'1'~'9'
                ans += pre1;//满足编码，f(i) += f(i-1) 
                if (10 <= num && num<= 26) ans += pre2;//向前看也满足编码f(i) += f(i-2)
            }
            pre2 = pre1;//记下f(i-2), f(i-1)
            pre1 = ans;
        }
        return ans;
    }
};