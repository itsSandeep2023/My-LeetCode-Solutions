class Solution {
public:
    bool helper(vector<int> nums, int target, int MO)
    {
        for(int i{0}; i<nums.size(); i++)
        {
            if(nums[i] > target)
            {
                int t = (nums[i] / target) + (nums[i]%target>0?1:0) - 1;
                if(MO<t)
                {
                    return false;
                }

                MO-=t;
            }
        }

        return true;
    }

    int minimumSize(vector<int>& nums, int maxOperations) {
        int l{1};
        int h = *max_element(nums.begin(), nums.end());

        while (l <= h) {
            int mid = l + (h - l) / 2;

            if (helper(nums, mid, maxOperations)) {
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return l;
    }
};