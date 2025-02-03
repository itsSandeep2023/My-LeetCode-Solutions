class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int li{1};
        int ld{1};

        int ci{1};
        int cd{1};

        int n = nums.size();
        int i{1};
        


        while(i<n)
        {
            if(nums[i]>nums[i-1])
            {
                ci++;
                cd = 0;
                li = max(li, ci);
            }
            else if(nums[i]<nums[i-1])
            {
                cd++;
                ci = 0;
                ld = max(ld, cd);
            }
            else
            {
                ci = cd = 1;
            }
            i++;
        }

        return max(li, ld);
    }
};