class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> ans(n);
        unordered_set<int> st;

        for(int i{0}; i<n; i++)
        {
            if(i>0) ans[i] += ans[i-1];

            if(st.count(A[i]))
                ans[i]++;
            else
                st.insert(A[i]);
            
            if(st.count(B[i]))
                ans[i]++;
            else
                st.insert(B[i]);
        }

        return ans;
    }
};