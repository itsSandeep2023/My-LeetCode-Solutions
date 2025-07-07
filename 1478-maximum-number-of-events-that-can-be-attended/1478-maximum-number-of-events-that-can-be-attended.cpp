class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(), events.end());

        int day = 0;
        int i{0};
        int ans{0};
        priority_queue<int, vector<int>, greater<int>> pq;

        while (i < n or !pq.empty()) {
            while (i < n and events[i][0] == day) {
                pq.push(events[i][1]);
                i++;
            }

            if (!pq.empty()) {
                pq.pop();
                ans++;
            }

            day++;

            while (!pq.empty() and pq.top() < day) {
                pq.pop();
            }
        }

        return ans;
    }
};