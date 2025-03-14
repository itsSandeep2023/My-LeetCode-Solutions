class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans{0};

        for(auto& x: nums)
        {
            if(x%3)
                ans++;
        }

        return ans;
    }
};