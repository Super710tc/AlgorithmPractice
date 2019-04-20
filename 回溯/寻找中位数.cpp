/*给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。

请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。

你可以假设 nums1 和 nums2 不会同时为空。

示例 1:

nums1 = [1, 3]
nums2 = [2]

则中位数是 2.0*/
#define min(a,b) (a<b?a:b)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1=nums1.size(), size2=nums2.size();
        int total=size1+size2, mid=(total-1)/2;
        int i=0, j=0;
        while(i+j<mid)
            if(i>size1-1 || (j<=size2-1 && nums1[i]>nums2[j]))
                ++j;
            else
                ++i;
        double result;
        if(size2<=j || (size1>i && nums1[i]<nums2[j])) 
            result = nums1[i++];
        else 
            result = nums2[j++];

        if(!(total%2))
            if(i>=size1)
                result=(result+nums2[j])/2;
            else if(j>=size2)
                result=(result+nums1[i])/2;
            else
                result=(result+min(nums1[i], nums2[j]))/2;
        return result;  
    }
};