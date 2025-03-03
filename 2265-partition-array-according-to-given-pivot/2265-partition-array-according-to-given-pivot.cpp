class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> ans;
        vector<int> ans1;
        int ps{0};

        for(auto& x : nums)
        {
            if(x==pivot) ps++;
            else if(x<pivot) ans.push_back(x);
            else ans1.push_back(x);
        }

        while(ps--)
            ans.push_back(pivot);
        
        for(auto& x : ans1)
            ans.push_back(x);

        return ans;
    }
};