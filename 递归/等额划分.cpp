class Solution {

/*给定一个整数数组  nums 和一个正整数 k，找出是否有可能把这个数组分成 k 个非空子集，其总和都相等。

示例 1：

输入： nums = [4, 3, 2, 3, 5, 2, 1], k = 4
输出： True
说明： 有可能将其分成 4 个子集（5），（1,4），（2,3），（2,3）等于总和。*/
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for_each(nums.begin(), nums.end(), [&] (int n){
            sum += n;
        });
        cout << sum;
        int target = sum / k;
        int rem = sum % k;
        if(rem) return false;
        sort(nums.begin(), nums.end());
        if(nums.back() > target) return false;
        while(nums.size() && (nums.back()==target)){
                nums.pop_back();
                k -= 1;
            }
        vector<int> groups(k,0);
        return Partition(groups, nums, target);
    }
    bool Partition(vector<int> groups, vector<int> nums, int target ){
        if (!nums.size()) return true;
        int v = nums.back();
        nums.pop_back();
        
        for(vector<int>::iterator pr = groups.begin(); pr != groups.end(); pr++){
            if( v + *pr <= target){
                *pr += v;
                if(Partition(groups, nums, target)) return true;
                *pr -= v;
            }
            if(*pr == 0) break;
        }
        return false;
    };
};