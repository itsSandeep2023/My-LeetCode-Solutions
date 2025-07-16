class Solution {
    int n;
public:
    int solve(vector<int> &nums, int idx, bool even, bool prevOdd, int cnt=1)
    {
        if(idx>=n) return cnt;

        while(idx<n)
        {
            if((even ? (prevOdd == (nums[idx]%2)) : (prevOdd != (nums[idx]%2))))
            {
                return solve(nums, idx+1, even, nums[idx]%2) + cnt;
            }
            idx++;
        }

        return cnt;
    }

    int maximumLength(vector<int>& nums) {
        n = nums.size();

        int ans{0};

        bool even = false;
        bool odd = false;

        for(int i{0}; i<n-1; i++)
        {
            if((nums[i] % 2 ) ? !odd : !even)
            {
                    ans = max(ans, solve(nums, i+1,true, nums[i]%2));
                    ans = max(ans, solve(nums, i+1,false, nums[i]%2));
                    
                    if(nums[i]%2)
                        odd = true;
                    else
                        even = true;
                    
            }

            if(even and odd) break;
        }

        return ans;
    }
};