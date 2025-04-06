class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> LIS(n, 1);
        vector<int> preIdx(n, -1);
        
        int maxL{1};
        int LCI{0};
        for(int i{0}; i<n; i++)
        {
            for(int j{0}; j<i; j++)
            {
                if(nums[i]%nums[j] == 0)
                {
                    if(LIS[i] <= LIS[j])
                    {
                        LIS[i] = 1 + LIS[j];
                        preIdx[i] = j;

                        if(maxL < LIS[i])
                        {
                            maxL = LIS[i];
                            LCI = i;
                        }
                    }
                }
            }
        }

        vector<int> result;

        while(LCI != -1)
        {
            result.push_back(nums[LCI]);
            LCI = preIdx[LCI];
        }

        return result;
    }
};