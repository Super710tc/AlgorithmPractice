/*题目描述
根据逆波兰表示法，求表达式的值。

有效的运算符包括 +, -, *, / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。

说明：

整数除法只保留整数部分。
给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。
示例 1：

输入: ["2", "1", "+", "3", "*"]
输出: 9
解释: ((2 + 1) * 3) = 9
示例 2：

输入: ["4", "13", "5", "/", "+"]
输出: 6
解释: (4 + (13 / 5)) = 6
示例 3：

输入: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
输出: 22
解释: 
  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
*/
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        //初始化算术运算符向量集
        vector<string> mark={"+","-","*","/"};
        stack <int>stk;
        int temp=0;
        for(int i=0;i<tokens.size();i++){
            //判断是否为算术运算符
            if(!count(mark.begin(), mark.end(), tokens[i])){
                stk.push(stoi(tokens[i]));
            }else{
                //第一次pop()取运算符右边数字
                temp=stk.top();
                stk.pop();
                if(tokens[i]=="+"){
                    //第二次pop()取左边数字并计算
                    temp=stk.top()+temp;
                }else if(tokens[i]=="-"){
                    temp=stk.top()-temp;
                }
                else if(tokens[i]=="*"){
                   temp=stk.top()*temp;
                }
                else if(tokens[i]=="/"){
                    temp=stk.top()/temp;
                }
                //取完之后弹出栈顶元素将计算结果入栈
                    stk.pop();
                    stk.push(temp);
            }
        }
        //最后栈中只有一个元素，栈顶元素即为结果
        return stk.top();
    }
};