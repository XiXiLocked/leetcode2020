// 12. Integer to Roman
// 找模式咯。。，
// 没有一次过，笔误
class Solution {
public:
    string intToRoman(int num) {
        char rst[17];
        int len =0;
        for(int i =0;i< 17;++i)
        {
            rst[i] = 0;
        }
        int digit4= num/1000;
        len = fill(digit4,' ',' ','M', rst,len);

        num = num%1000;
        int digit3 = num/100;
        len = fill(digit3, 'M','D','C',rst,len);
        
        num = num%100;
        int digit2 = num /10;
        len = fill(digit2, 'C','L','X',rst,len);

        num = num%10;
        int digit1 = num;
        len = fill(digit1, 'X','V','I', rst, len);
        return string(rst,len);

        
    }
    int fill(int digit, char ten, char five, char one, char * rst, int len)
    {
        switch (digit)
        {
            case 1: {
                rst[len++] = one;
                break;
            }
            case 2: {
                rst[len++] = one;
                rst[len++] = one;
                break;
            }
            case 3: {
                rst[len++] = one;

                rst[len++] = one;
                rst[len++] = one;
                break;
            } 
            case 4: {
                rst[len++] = one;
                rst[len++] = five;
                break;
            }
            case 5: {
                rst[len++] = five;
                break;
            }
            case 6: {
                rst[len++] = five;
                rst[len++] =one;
                break;
            }
            case 7: {
                rst[len++] =five;
                rst[len++] =one;
                rst[len++] =one;
                break;
            }
            case 8: {
                rst[len++] =five;
                rst[len++] =one;
                rst[len++] =one;
                rst[len++] =one;
                break;
            }
            case 9:
            {
                rst[len++] = one;
                rst[len++] =ten;
                break;
            }
            default:
            {
                break;
            }
        }
        return len;

    }
};