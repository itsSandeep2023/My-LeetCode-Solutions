class Solution {
public:
    int findComplement(int num) {
        int ans{0};
        int mask{1};

        if ((num & mask) == 0)
            ans ^= mask;

        for (int i{0}; i < (int)(log2(num)); i++) {
            mask <<= 1;
            if ((num & mask) == 0)
                ans ^= mask;
            cout << mask << " " << ans << endl;
        }

        return ans;
    }
};