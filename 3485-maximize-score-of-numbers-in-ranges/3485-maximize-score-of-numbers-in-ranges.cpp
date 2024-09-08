class Solution {
public:
    bool canChooseWithScore(const vector<int>& start, int d, int score) {
        int n = start.size();
        long long pc = start[0];

        for (int i = 1; i < n; ++i) {
            long long lb = pc + score;
            if (lb <= start[i] + d) {
                pc = max(lb, (long long)(start[i]));
            } else {
                return false;
            }
        }
        return true;
    }

    int maxPossibleScore(vector<int>& start, int d) {
        sort(start.begin(), start.end());
        int low = 0, high = 2e9, ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canChooseWithScore(start, d, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};