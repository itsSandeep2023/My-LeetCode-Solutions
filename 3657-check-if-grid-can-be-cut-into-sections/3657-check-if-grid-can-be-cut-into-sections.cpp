class Solution {
private:
    int merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for(int i{1}; i<n; i++)
        {
            if(intervals[i][0] < ans.back()[1])
            {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
            else
            {
                ans.push_back(intervals[i]);
            }
        }

        return ans.size();
    }

public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> ver;
        vector<vector<int>> hor;

        for(auto& rec : rectangles)
        {
            int x1 = rec[0];
            int x2 = rec[2];
            int y1 = rec[1];
            int y2 = rec[3];

            hor.push_back({x1, x2});
            ver.push_back({y1, y2});
        }

        return merge(ver) >= 3 or merge(hor) >= 3;

    }
};