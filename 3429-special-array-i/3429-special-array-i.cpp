class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        for(int i{1}, n = nums.size(); i<n; i++)
            if((nums[i]&1) == (nums[i-1]&1))
                return false;

        return true;
    }
};