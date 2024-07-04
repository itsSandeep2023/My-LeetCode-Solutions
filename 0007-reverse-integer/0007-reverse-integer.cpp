class Solution {
public:
    int reverse(int x) {
        long out=0;

        while(x)
        {
            out*=10;
            out+=(x%10);
            x/=10;
        }
        
        if(out>INT_MAX or out < INT_MIN)
         {  return 0;
         }

        return out;
    }
};