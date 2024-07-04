class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        unordered_map<int,int> s;
        vector<int> result;

        for(int i{0};i<nums.size();i++)
        {
            int x = target - nums[i];
            if(s.find(x)!=s.end())
            {
                result.push_back(s[x]);
                result.push_back(i);
                return result;
            }

            s[nums[i]]=i;
        }

        return {};
    }
};