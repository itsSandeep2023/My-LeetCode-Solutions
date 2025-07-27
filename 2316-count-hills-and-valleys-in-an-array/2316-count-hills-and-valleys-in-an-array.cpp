class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();

        int ans{0};

        int c{1};
        int r{2};

        while(r<n)
        {
            if(nums[c] != nums[r])
            {
                if(nums[c] > nums[c-1] and nums[c] > nums[r] or (nums[c]< nums[c-1] and nums[c] < nums[r]))
                    ans++;
                c = r;
            }
            r++;
        }       

        return ans;
    }
};