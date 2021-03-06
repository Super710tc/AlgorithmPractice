/*
给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。

示例 1:

输入: coins = [1, 2, 5], amount = 11
输出: 3 
解释: 11 = 5 + 5 + 1
示例 2:

输入: coins = [2], amount = 3
输出: -1
*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> MIN(amount+1);
		MIN[0] = 0;
		for (int j = 1; j <= amount; ++j) {
			MIN[j] = 9999;
			for (int i = 0; i < coins.size(); ++i) {
				if (coins[i] <= j && MIN[j - coins[i]] + 1 < MIN[j])
					MIN[j] = MIN[j - coins[i]] + 1;
			}
		}
		if (MIN[amount] == 9999)
			return -1;
		return MIN[amount];
    }
};