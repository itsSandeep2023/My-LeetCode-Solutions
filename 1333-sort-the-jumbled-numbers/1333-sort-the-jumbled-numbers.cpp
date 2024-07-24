class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        set<pair<int, int>> st;

        for (int i{0}; i < nums.size(); i++) {
            int t = nums[i];
            int s{0};
            int p{1};
            do
            {
                s += (mapping[t % 10]) * p;
                t /= 10;
                p *= 10;
            } while (t>0);

            st.insert({s, i});
        }

        vector<int> ans;

        for (auto& x : st) {
            ans.push_back(nums[x.second]);
        }

        return ans;
    }
};