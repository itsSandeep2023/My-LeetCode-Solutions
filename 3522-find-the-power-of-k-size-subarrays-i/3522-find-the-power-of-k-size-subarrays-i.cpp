class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        ios::sync_with_stdio(false);
        
        if (k == 1)
            return nums;

        int acnt{1};

        vector<int> ans;

        for (int i{1}; i < nums.size(); i++) {
            acnt++;

            if (nums[i] - nums[i - 1] != 1)
                acnt = 1;

            if (i + 1 >= k)
                ans.push_back((acnt >= k ? nums[i] : -1));
        }

        return ans;
    }
};