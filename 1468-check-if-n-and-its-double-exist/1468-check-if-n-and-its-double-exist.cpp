class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> st;

        for(const auto& x : arr)
        {
            if(st.count(x * 2) or ((x&1)==0 and st.count(x/2)))
            {
                return true;
            }
            st.insert(x);
        }

        return false;
    }
};