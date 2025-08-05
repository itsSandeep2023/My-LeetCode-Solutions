class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();

        unordered_set<int> st;

        int cnt{0};

        for(int i{0}; i<n; i++)
        {
            for(int j{0}; j<n; j++)
            {
                if(baskets[j] >= fruits[i] and !st.count(baskets[j]))
                {
                    st.insert(baskets[j]);
                    cnt++;
                    break;
                }
            }
        }

        return n - cnt;
    }
};