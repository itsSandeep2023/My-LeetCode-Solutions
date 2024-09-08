class Solution {
public:
    int maxPossibleScore(vector<int>& start, int d) {
        ios::sync_with_stdio(false);
        sort(start.begin(), start.end());

        auto check = [&](long long lim) {
            long long now = start[0];
            for (int i = 1; i < start.size(); i++) {
                now = max(now + lim, 1LL * start[i]);
                if (now > start[i] + d) return false;
            }
            return true;
        };

        long long head = 0, tail = 2e9;
        while (head < tail) {
            long long mid = (head + tail + 1) >> 1;
            if (check(mid)) head = mid;
            else tail = mid - 1;
        }
        return head;
    }
};