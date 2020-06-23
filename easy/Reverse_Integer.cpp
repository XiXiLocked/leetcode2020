// 7. Reverse Integer
// 一开始想的是字符串操作,有点蠢,
// 10进制转换大概这种是正统?
// 没有一次AC, 理解错了溢出条件.
// happy path 写了多遍,  参考答案是把条件反过来写,就只要写一遍 实际操作,剩下的都是return 0, 可以参考一下.
class Solution {
public:
    int reverse(int x) {
        int r = 0;
        // 123   0
        // 12    3
        //  1    32
        //  0    321

        while (x!= 0)
        {
            if (r< 214748364 && r > -214748364)
            {
                r = r*10 + x%10;
                x = x/10;
            }
            else if (r==214748364 && x<=7)
            {
                r = r*10 + x%10;
                x = x/10;
            }
            else if (r == -214748364 && x<-8)
            {
                r = r*10 + x%10;
                x = x/10;
            }
            else
            {
                return 0;
            }
        }
        return r;
    }
};