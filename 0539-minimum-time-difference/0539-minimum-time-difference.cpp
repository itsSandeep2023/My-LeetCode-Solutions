class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        ios::sync_with_stdio(false);
        
        vector<int> times;
        for(auto& x : timePoints)
            times.push_back(stoi(x.substr(0,2))*60 + stoi(x.substr(3,2)));

        sort(times.begin(), times.end());

        int ans = INT_MAX;
        
        for(int i{1}; i< times.size(); i++)
            ans = min(ans, times[i] - times[i-1]);

        return min(ans, (24*60 - times[times.size()-1]) + times[0]);
    }
};