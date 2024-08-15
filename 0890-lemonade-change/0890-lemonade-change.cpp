class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fcnt{0};
        int tcnt{0};
        
        for(const auto& b : bills)
        {
            if(b==5)
                fcnt++;
            else if(b==10)
            {
                if(fcnt>0)
                    fcnt--;
                else
                    return false;
                
                tcnt++;
            }
            else
            {
                if(tcnt>0 and fcnt>0)
                {
                    tcnt--;
                    fcnt--;
                }
                else if(fcnt>=3)
                    fcnt-=3;
                else
                    return false;
            }
        }

        return true;
    }
};