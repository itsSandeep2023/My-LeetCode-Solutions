class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefsum(n-k+1);

        prefsum[0] = accumulate(nums.begin(), nums.begin()+k, 0);

        for(int i{0}; i<n-k; i++)
        {
            prefsum[i+1] = prefsum[i] - nums[i] + nums[i+k];
        }

        vector<int> mx1(n-k+1);
        mx1[0] = 0;
        for(int i{1}; i<n-k; i++)
        {
            mx1[i] = prefsum[i] > prefsum[mx1[i-1]] ? i : mx1[i-1];
        }

        vector<int> mx3(n-k+1);
        mx3[n-k] = n-k;
        for(int i{n-k-1}; i>=0; i--)
        {
            mx3[i] = prefsum[i] >= prefsum[mx3[i+1]] ? i : mx3[i+1] ;
        }

        int a,b,c;
        int maxsum{0};
        for(int i{k}; i<=n-k*2; i++)
        {
            int csum = prefsum[mx1[i-k]] + prefsum[i] + prefsum[mx3[i+k]];
            if(csum > maxsum)
            {
                maxsum = csum;
                a=mx1[i-k];
                b=i;
                c=mx3[i+k];
            }
        }

        return {a, b, c};
    }
};