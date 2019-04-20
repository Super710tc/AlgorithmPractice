/*给定一个仅包含数字 0-9 的字符串和一个目标值，在数字之间添加二元运算符（不是一元）+、- 或 * ，返回所有能够得到目标值的表达式。

示例 1:

输入: num = "123", target = 6
输出: ["1+2+3", "1*2*3"] 
示例 2:

输入: num = "232", target = 8
输出: ["2*3+2", "2+3*2"]*/
class Solution {
public:
	vector<string> addOperators(string num, int target) {
		vector<string> result;
		addOperatorsDFS(num, target, 0, 0, "", result);
		return result;
	}
    //lastOperaNum上一次添加的操作数（用于*法回退）
	void addOperatorsDFS(string num, int target, long long lastOperaNum, long long curNum, string tempRes, vector<string> &result) {
		if (num.size() == 0 && curNum == target) {//此次运算符添加成功
			result.push_back(tempRes);
			return;
		}
        //对添加运算符的位置穷举
		for (int i = 1; i <= num.size(); ++i)
		{
			string cur = num.substr(0, i);
			if (cur.size() > 1 && cur[0] == '0') {//剪枝   cur不能出现“012”这种，即不能出现前导零
				return;
			}
			string next = num.substr(i);//cur之后的字符串
			if (tempRes.size() > 0) {//如果cur不是第一个操作数
				//尝试添加加，这次添加的操作数lastOperaNum == stoll(cur)
				addOperatorsDFS(next, target, stoll(cur), curNum + stoll(cur), tempRes + "+" + cur, result);
				//尝试添加减，这次添加的操作数lastOperaNum == -stoll(cur)
				addOperatorsDFS(next, target, -stoll(cur), curNum - stoll(cur), tempRes + "-" + cur, result);
				//尝试添加乘
				//由于乘法的优先级比加、减法高，所以需要回退到上一步，即把上一步的操作数与乘法进行运算
				//这次添加的操作数lastOperaNum == lastOperaNum * stoll(cur)
				//(curNum - lastOperaNum)是退回上一次的操作数，然后在进行乘法运算   + lastOperaNum * stoll(cur)
				addOperatorsDFS(next, target, lastOperaNum * stoll(cur), (curNum - lastOperaNum) + lastOperaNum * stoll(cur), tempRes + "*" + cur, result);
			}
			else {//如果是第一个操作数
				addOperatorsDFS(next, target, stoll(cur), stoll(cur), cur, result);
			}
		}
	}
};