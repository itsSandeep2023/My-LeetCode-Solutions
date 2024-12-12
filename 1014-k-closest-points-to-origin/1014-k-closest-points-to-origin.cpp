class Solution {
    #define P pair<float, int>
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        ios::sync_with_stdio(false);
        
        priority_queue<P, vector<P>, greater<P>> pq;

        for(int i{0}; i<points.size(); i++)
        {
            int a = points[i][0]*points[i][0];
            int b = points[i][1]*points[i][1];

            float out = sqrt(a+b);

            pq.push({out, i});
        }

        vector<vector<int>> ans;
    
        while(k-- and !pq.empty())
        {
            int c = pq.top().second;
            pq.pop();
            ans.push_back(points[c]);
        }
        
        return ans;
    }
};