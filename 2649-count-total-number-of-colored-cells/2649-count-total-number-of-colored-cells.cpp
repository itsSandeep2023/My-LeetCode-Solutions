class Solution {
public:
    long long coloredCells(int n) {
        return 1 + ((8 + (--n-1)*4)*1ll*(n))/2;
    }
};