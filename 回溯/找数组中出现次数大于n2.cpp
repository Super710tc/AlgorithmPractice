/* 输入: [2,2,1,1,1,2,2]
输出: 2*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int num = 0;
        int count = 0;
        for (auto e : nums) {
            if (!count) {
                num = e;
                count++;
            } else if (num == e) {
                count++;
            } else {
                count--;
            }
        }

        return num;
    }
};