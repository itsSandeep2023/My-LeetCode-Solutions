class Solution {
public:
    int passThePillow(int n, int time) {
        int c = time / (n - 1);
        int t = time % (n - 1);

        if (c % 2)
            return n - t;

        return 1 + t;
    }
};