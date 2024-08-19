class Solution {
public:
    int minSteps(int n) {
        if(n<=1)
            return 0;
        
        int ans{1};
        int sz{1};
        int cp{1};
        n;
        while(sz!=n)
        {
            if(n%sz==0 and sz>cp)
            {
                cp=sz;
                ans++;
            }

            sz+=cp;
            ans++;
        }

        return ans;
    }
};