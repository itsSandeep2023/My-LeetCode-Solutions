class Solution {
public:
    int minSwaps(string s) {
        int cnt{0};

        for (const auto& x : s) {
            if (x == '[')
                cnt++;
            else if (cnt > 0)
                cnt--;
        }

        cnt++;
        return cnt / 2;
    }
};