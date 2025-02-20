class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums[0].size();
        unordered_set<string> st;
        for(auto& s: nums)
            st.insert(s);

        string s(n, '0');

        if(!st.count(s))
            return s;

        for(int i{1}, m = pow(2,n); i<m; i++)
        {
            s = bitset<16>(i).to_string().substr(16 - n);
            if(!st.count(s))
                return s;
        }
        
        return "";
    }
};