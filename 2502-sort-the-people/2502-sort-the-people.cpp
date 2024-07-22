class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        ios::sync_with_stdio(false);
        
        priority_queue<pair<int, string>> hp;
        for(int i{0};i<heights.size();i++)
            hp.push({heights[i], names[i]});

        vector<string> ans;

        while(!hp.empty())
        {
            ans.push_back(hp.top().second);
            hp.pop();
        }

        return ans;
    }
};