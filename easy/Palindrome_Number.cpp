// 9. Palindrome Number
// 思路:尝试了直接比较x == reverse(x), 发现int 存不下reverse(x),感觉还是字符串方式最好写
// 参考答案给的是 x和reverse(x)做到一半的时候比较x == reverse(x),比较巧的.
class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0) return false;
        if (x==0) return true;
        int digit[10] = {0,0,0,0,0,0,0,0,0,0};
        int i =0;
        while(x>0)
        {
            digit[i++] = x%10;
            x =x/10;
        }
        for (int k =0;k < i;++k)
        {
            if (digit[k]!= digit[i-k-1])
            {
                return false;
            }
        }
        return true;

        
    }
};