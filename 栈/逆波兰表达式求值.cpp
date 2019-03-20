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