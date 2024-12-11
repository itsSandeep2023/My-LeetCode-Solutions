class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int i{0}, j{1};

        int ans{1};

        while(j<n)
        {
            while(i<j and nums[j] - nums[i] > k*2)
            {
                i++;
            }

            j++;
            if(ans < j-i)
            {
                ans = j-i;
            }
        }

        return ans;
    }
};