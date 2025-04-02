class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> t(n, vector<int>(n));

        for(int L{1}; L<=n; L++)
        {
            for(int i{0}; i<n-L+1; i++)
            {
                int j = i + L - 1;

                t[i][j] = min(nums[i], nums[j]);
                if(i+1 <= j-1)
                    t[i][j] = min(t[i][j], t[i+1][j-1]);
            }
        }

        long long ans{0};

        for(int i{0}; i<n-2; i++)
        {
            for(int j{i+2}; j<n; j++)
            {
                ans = max(ans, (nums[i]-t[i+1][j-1])*1LL*nums[j]);
            }
        }

        return ans;
    }
};