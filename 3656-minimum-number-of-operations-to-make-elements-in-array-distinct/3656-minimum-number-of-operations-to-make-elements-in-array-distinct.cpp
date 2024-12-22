class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;

        int j{-1};

        for(int i{n-1}; i>=0; i--)
        {
            if(st.count(nums[i]))
            {
                j = i;
                break;
            }
            st.insert(nums[i]);
        }

        if(j!=-1)
            return (j+3)/3;

        return 0;
    }
};