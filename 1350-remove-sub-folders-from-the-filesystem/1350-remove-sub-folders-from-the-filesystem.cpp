class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        ios::sync_with_stdio(false);
        sort(folder.begin(), folder.end());
        vector<string> ans;
        
        ans.push_back(folder[0]);

        for(int i{1}; i<folder.size(); i++)
        {
            if(folder[i].find(ans.back()+'/'))
            {
                ans.push_back(folder[i]);
            }
        }

        return ans;
    }
};