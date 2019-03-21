给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
说明：你不能倾斜容器，且 n 的值至少为 2。
示例:
输入: [1,8,6,2,5,4,8,3,7]
输出: 49

/**
遍历数组，先从左至右取离当前点最远且大于当前点值的点计算两者之间的值，数组循环完成后得到最大值Max1，翻转数组后重新调用函数得到最大值Max2，比较得出最大值max
*/
class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int max=0,temp=0;
        max=localMax(height);
        reverse(height.begin(),height.end());
        temp=localMax(height);
        return max>temp?max:temp; 
    }
    int localMax(vector<int>& height){
        int total = height.size();
        int max=0;
        for(int i=0;i<total;i++)
            for(int j=total-1;j>i;j--){
                if(height[i]<=height[j]){
                max=(j-i)*(height[i])>max?(j-i)*(height[i]):max;
                continue;  
            }
        
        }
        return max;
    }
};
/**
改进：循环数组，循环过程中左右两个指针分别从begin和end处向当前点靠近，两边靠近过程中，取离当前节点最远且大于当前节点的值，结算比较得出当前节点最优解，循环完成得出最大值
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int total = height.size();
        int max=0;
        for(int i=0;i<total;i++)
        {
           //从右往节点靠近
          for(int j=total-1;j>i;j--)
          {
            if(height[i]<=height[j])
            {
                max=(j-i)*(height[i])>max?(j-i)*(height[i]):max;
                break;  
            } 
          }
          //从左往节点靠近
          for(int k=0;k<i;k++)
          {
            if(height[i]<=height[k])
            {
                max=(i-k)*(height[i])>max?(i-k)*(height[i]):max;
                break;  
            }
          } 
          
        }
        return max;
    }
};

