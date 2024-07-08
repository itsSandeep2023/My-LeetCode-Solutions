class Solution {
public:
    int go(int n, int k) {
        if (n == 1)
            return 0;

        int i = go(n - 1, k);
        i = (i + k) % n;

        return i;
    }

    int findTheWinner(int n, int k) { 
        return go(n, k) + 1;
    }
};