class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int mod=1e9+7;

        int ans{0};
        int evens{1};
        int odds{0};
        bool odd = false;

        for(auto& x : arr)
        {
            if(x&1)
            {
                odd = !odd;
            }
            
            if(odd)
            {
                ans = (ans + evens)%mod;
                odds++;
            }
            else
            {
                ans = (ans + odds)%mod;
                evens++;
            }
        }

        return ans;
    }
};