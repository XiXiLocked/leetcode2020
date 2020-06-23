// 11. Container With Most Water
// 2个思路，暴力，分治。暴力n2， 分治nlogn
// 暴力的TLE了
// 分治也最后归结到暴力解，不行。
// 参考了答案，有线性算法。
// 仔细分析暴力法，给出了一个试错的排序。
// 先列出n行n列，i,j 是下标，i<j 所以划掉i>=j的格子，然后
// 从右上角的[0,n)的尝试开始，假设0是短边，
// 那么n是长边，长边往左同时减少了宽或高，必定非优。排除了所有的[0,j)形式的解答。
// 所以一次能减少n个候选解。
// 类推可以得到另一边长和两边一样长的做法。

// 反正当场是想不出的，总结了下有下面的经验
// 学到的是分开考虑2元函数（此处是乘法），求极值时可以先减少一个分量（此处是宽度）
// 再往后考虑
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_val = 0;
        int i =0;
        int j = height.size()-1;
        while (i<j)
        {
            int size = 0;
            if (height[i]>height[j])
            {
                size = (j-i)*height[j];
                j--;
            }
            else if (height[i]< height[j])
            {
                size = (j-i)*height[i];
                i++;
            }
            else
            {
                size = (j-i) *height[i];
                i++;
                j--;
            }
            

            if (size > max_val)
            {
                max_val = size;
            }
        }
        return max_val;
        
    }
};