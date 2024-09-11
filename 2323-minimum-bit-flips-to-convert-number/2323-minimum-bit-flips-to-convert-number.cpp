class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans{0};

        while (start or goal) {
            ans += ((start & 1) != (goal & 1));
            start>>=1;
            goal>>=1 ;
        }

        return ans;
    }
};