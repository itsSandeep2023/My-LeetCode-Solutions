class Solution {
public:
    int myAtoi(string s) {
        long result{0};
        bool neg=false;
        bool pos=false;
        bool fn = false;

        char p = ' ';
        for(auto c : s)
        {

            if(c==' ' and (neg or pos))
            {
                return neg==false?result:-result;
            }

            if(fn and (c<'0' or c>'9'))
            {
                cout<<"1"<<endl;
                return neg==false?result:-result;
            }
            if(c=='-' and p == ' ')
            {
                if(pos or neg)
                {
                    return neg==false?result:-result;
                }
                neg = true;
                cout<<"2"<<endl;
                continue;
            }
            else if(c=='+' and p == ' ')
            {
                if(pos or neg)
                {
                    return neg==false?result:-result;
                }
                pos = true;
                continue;
            }
           
            if(c<'0' or c>'9')
            {
                if(c!=' ')
                {
                    cout<<"3"<<endl;
                    return neg==false?result:-result;
                }
                continue;
            }
            
            result*=10;
            

            result += c - '0';
            
            if(c >= '0' and c <= '9')
            {
                fn = true;
            }
            
            if(result>INT_MAX)
            {
                if(neg)
                {
                    cout<<"4"<<endl;
                    return INT_MIN;
                }
                else 
                    return INT_MAX;
            }

            p = c;
        }
            
        if(neg)
        {
            cout<<"5"<<endl;
            return -result;
        }


        return result;
    }
};