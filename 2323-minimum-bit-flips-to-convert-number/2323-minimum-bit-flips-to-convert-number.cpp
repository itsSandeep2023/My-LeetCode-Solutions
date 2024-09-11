class Solution {
public:
    int minBitFlips(int start, int goal) {
        ios::sync_with_stdio(false);
        
        int ans{0};

        while (start or goal) {
            ans += ((start & 1) != (goal & 1));
            start>>=1;
            goal>>=1 ;
        }

        return ans;
    }
};