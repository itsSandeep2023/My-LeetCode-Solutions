class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> st;
        int ans{1};

        for(auto& x : nums)
        {
            st.insert(x);
        }

        int size = st.size();
        
        while(size--)
        {
            if(!st.count(ans))
                return ans;
            ans++;
        }

        return ans;
    }
};