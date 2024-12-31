class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int t[366+30] = {0};

        unordered_set<int> st;

        for(auto& d : days)
            st.insert(d);

        int n = days.back();

        for(int i{30}; i<=n+29; i++)
        {
            if(!st.count(i-29))
                t[i] = t[i - 1];
            else
                t[i] = min({t[i - 1] + costs[0], t[i - 7] + costs[1], t[i - 30] + costs[2]});

                cout<<t[i]<<" ";
        }

        return t[n+29];
    }
};