class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> st;

        for(int &x : banned)
        {
            st.insert(x);
        }

        int ans{0};
        int sum{0};
        
        for(int i{1}; i<=n; i++)
        {
            if(!st.count(i))
            {
                sum += i;

                if(sum > maxSum)
                {
                    return ans;
                }

                ans++;
            }
        }

        return ans;
    }
};