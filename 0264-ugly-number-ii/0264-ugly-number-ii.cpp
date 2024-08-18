class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ans(n);

        int i2, i3, i5;
        i2 = i3 = i5 = 0;

        ans[0] = 1;

        for(int i{1};i<n;i++)
        {
            int u2 = ans[i2] * 2; 
            int u3 = ans[i3] * 3; 
            int u5 = ans[i5] * 5;

            ans[i] = min({u2, u3, u5});

            if(ans[i] == u2)
                i2++;
            
            if(ans[i] == u3)
                i3++;
            
            if(ans[i] == u5)
                i5++;
        }

        return ans[n-1];
    }
};