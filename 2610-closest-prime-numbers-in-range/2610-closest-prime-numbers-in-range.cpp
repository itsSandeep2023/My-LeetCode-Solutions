class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> prim(right + 1, true);
        prim[1] = false;

        for (int i{2}, n = right / 2; i <= n; i++) {
            if (prim[i] == false)
                continue;
            for (int j{i + i}; j <= right; j += i) {
                prim[j] = false;
            }
        }

        int a{0};
        int b = INT_MAX;
        int l{0};
        for (int i{left}; i <= right; i++) {
            if (prim[i]) {
                if ((b - a) > i - l) {
                    a = l;
                    b = i;
                }
                l = i;
            }
        }

        if(a!=0)
            return {a, b};

        return {-1, -1};
    }
};