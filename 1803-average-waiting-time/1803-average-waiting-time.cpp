class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        ios::sync_with_stdio(false);
        
        double ans = {0};
        double twt = customers[0][0];
        double ewt{0};
        for (const auto& vec : customers) {
            ewt = twt - vec[0];
            twt += vec[1];
            if (ewt > 0)
                ans += ewt;
            else
                twt -= ewt;

            ans += vec[1];
        }

        return ans / customers.size();
    }
};