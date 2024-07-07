class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans{numBottles};

        while (numBottles >= numExchange) {
            int cur = numBottles % numExchange;
            numBottles /= numExchange;
            ans += numBottles;
            numBottles += cur;
        }

        return ans;
    }
};