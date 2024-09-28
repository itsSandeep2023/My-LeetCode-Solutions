class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());        
        int n = points.size();

        if(n==1) return 1;
        vector<int> prev = points[0];
        
        int ans{1};

        for(int i{1}; i<n; i++)
        {
            int currStart = points[i][0];
            int currEnd = points[i][1];

            if(currStart > prev[1])
            {
                ans++;
                prev = points[i];
            }
            else
            {
                prev[0] = max(prev[0], currStart);
                prev[1] = min(prev[1], currEnd);
            }
        }

        return ans;
    }
};