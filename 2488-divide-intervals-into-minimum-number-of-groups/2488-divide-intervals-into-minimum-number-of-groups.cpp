class Solution {
public:
    int minGroups(vector<vector<int>>& itv) {
        ios::sync_with_stdio(false);

        int n = itv.size();
        if(n==1) return 1;
        sort(itv.begin(), itv.end());

        priority_queue<int, vector<int>, greater<int>> b;
        b.push(itv[0][1]);

        for(int i{1}; i<n; i++)
        {
            if(b.top() < itv[i][0])
                b.pop();
            b.push(itv[i][1]);
        }

        return b.size();
    }
};