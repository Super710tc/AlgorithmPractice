class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        //��ʼ�����������������
        vector<string> mark={"+","-","*","/"};
        stack <int>stk;
        int temp=0;
        for(int i=0;i<tokens.size();i++){
            //�ж��Ƿ�Ϊ���������
            if(!count(mark.begin(), mark.end(), tokens[i])){
                stk.push(stoi(tokens[i]));
            }else{
                //��һ��pop()ȡ������ұ�����
                temp=stk.top();
                stk.pop();
                if(tokens[i]=="+"){
                    //�ڶ���pop()ȡ������ֲ�����
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
                //ȡ��֮�󵯳�ջ��Ԫ�ؽ���������ջ
                    stk.pop();
                    stk.push(temp);
            }
        }
        //���ջ��ֻ��һ��Ԫ�أ�ջ��Ԫ�ؼ�Ϊ���
        return stk.top();
    }
};