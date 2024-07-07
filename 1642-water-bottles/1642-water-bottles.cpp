class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int totalDrunk = numBottles; // Start by drinking all initial bottles

        while (numBottles >= numExchange) {
            int newFullBottles =
                numBottles / numExchange; // Full bottles after exchange
            int remainingBottles =
                numBottles %
                numExchange; // Bottles left that cannot be exchanged

            totalDrunk +=
                newFullBottles; // Add the new full bottles to the total drunk
            numBottles =
                newFullBottles + remainingBottles; // Update number of bottles
                                                   // for the next iteration
        }

        return totalDrunk; // Return the total number of bottles drunk
    }
};