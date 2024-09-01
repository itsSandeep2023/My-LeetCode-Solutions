class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        priority_queue<int> pq;
        vector<int> ans;

        for (const auto& query : queries) {
            int x = query[0];
            int y = query[1];
            int dist = abs(x) + abs(y);

            if (pq.size() < k) {
                pq.push(dist);
            } else if (dist < pq.top()) {
                pq.pop();
                pq.push(dist);
            }

            if (pq.size() < k) {
                ans.push_back(-1);
            } else {
                ans.push_back(pq.top());
            }
        }

        return ans;
    }
};