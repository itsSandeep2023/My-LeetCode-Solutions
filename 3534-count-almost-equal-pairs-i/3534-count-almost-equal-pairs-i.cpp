class Solution {
public:
    bool isAlmostEqual(int x, int y) {
        string s1 = to_string(x);
        string s2 = to_string(y);

        while (s1.length() < s2.length()) {
            s1 = "0" + s1;
        }
        while (s2.length() < s1.length()) {
            s2 = "0" + s2;
        }

        int dc = 0;
        vector<int> di;

        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i]) {
                dc++;
                di.push_back(i);
                if (dc > 2) {
                    return false;
                }
            }
        }

        if (dc == 0) {
            return true;
        }
        if (dc == 2) {
            swap(s1[di[0]], s1[di[1]]);

            return s1 == s2;
        }

        return false;
    }

    int countPairs(vector<int>& nums) {
        ios::sync_with_stdio(false);

        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isAlmostEqual(nums[i], nums[j])) {
                    ans++;
                }
            }
        }

        return ans;
    }
};