class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int, int>> t;

        for(int i{0}; i<n; i++)
            t.push_back({nums[i]-k, nums[i]+k});

        sort(t.begin(), t.end());      
        queue<int> q;

        int ans{0};

        for(auto [x, y]:t)
        {
            while(!q.empty() and q.front()<x)
                q.pop();

            q.push(y);

            if(ans<q.size())
                ans = q.size();
        }

        return ans;
    }
};