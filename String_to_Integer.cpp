// 8. String to Integer (atoi)
// 迭代10x+r
// 错4次
// 字符串处理1次, ifelseif 写成2个if ,粗心可改
// 溢出处理3次
// 觉得写的麻烦了,又是换思路, 最后没有全体改代码+笔误


// 10x+r溢出处理
// 有6个区间
// {正,负}x {直接溢出,可能溢出,不会溢出}
// 依据是否溢出处理为 溢出处理和非溢出处理
// 可以缩减到以下模版
// if (x>214748364 || (x == 214748364 && append>7)) { }
// else if (x < -214748364 || (x == -214748364 && append>8 )) {}
// else {}

class Solution {
public:
    int myAtoi(string str) {
        int i =0;
        int x  = 0;
        int sign = 0;
        for(i =0;i< str.length();++i)
        {
            if (str[i] !=  ' ')
                break;
        }
        if (i==str.length())
        {
            return  0 ;
        }
        if (str[i]=='+')
        {
            sign = 1;
            i++;
        }
        else if (str[i]=='-')
        {
            sign = -1;
            i++;
        }

        for (;i<str.length();++i)
        {
            if (str[i] > '9' || str[i] <'0')
            {
                break;
            }
            int append = (str[i]-'0');
            if (x>214748364 || (x == 214748364 && append>7))
            {
                return 2147483647;
            }
            else if (x < -214748364 || (x == -214748364 && append>8 ))
            {
                return  -2147483648;
            }
            else
            {
                if (sign>=0)
                {
                    x = x*10 + append;
                }
                else
                {
                    x = x*10 - append;
                }
            }
        }
        return x;
    }
};