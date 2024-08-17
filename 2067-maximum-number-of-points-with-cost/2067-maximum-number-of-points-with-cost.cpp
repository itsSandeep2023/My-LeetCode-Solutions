class Solution {
public:
#define ll long long

    long long maxPoints(vector<vector<int>>& points) {
        ios::sync_with_stdio(false);

        int m = points.size();
        int n = points[0].size();

        vector<ll> prev(n,0);

        for(int i{0};i<n;i++)
            prev[i] = points[0][i];

        long long ans = 0;
        
        for(int k{1};k<m;k++){

            vector<ll> left(n,0);
            vector<ll> right(n,0);

            left[0] = prev[0];
            right[n-1] = prev[n-1];

            for(int i{1};i<n;i++)
            {
                left[i] = max(left[i-1]-1, prev[i]);
                right[n-1-i] = max(right[n-i]-1, prev[n-1-i]);
            }
            
            for(int i{0}; i<n; i++)
            {
                prev[i] = points[k][i] + max(left[i], right[i]);
            }            
        }

        for(const auto& x: prev)
            if(ans < x)
                ans = x;

        return ans;
    }
};