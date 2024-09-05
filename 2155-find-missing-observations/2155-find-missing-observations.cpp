class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        long long sum{0};

        for (const auto& x : rolls)
            sum += x;

        int m = rolls.size();

        long long exp = mean * (m + n);

        long long left = exp - sum;

        int dis = left / n;
        int rem = left % n;

        cout << exp << " " << left << " " << dis << " " << rem;

        if (dis > 6 or left < n or left > 6 * n)
            return {};

        vector<int> ans;

        cout << " run";

        while (n--) {
            int curr = dis;
            int d = 6 - curr;
            if (rem > d) {
                curr += d;
                rem -= d;
            } else {
                curr += rem;
                rem = 0;
            }

            ans.push_back(curr);
        }

        return ans;
    }
};