class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n = nums.size();

        if(n&1) return false;

        unordered_map<int, int> st;

        for(auto& x : nums)
        {
            st[x]++;
        }

        for(auto& x : st)
        {
            if(x.second&1) return false;
        }
                
        return true;
    }
};