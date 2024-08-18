class Solution {
public:
#define ll long long

    long long maxEnergyBoost(vector<int>& energyDrinkA,
                             vector<int>& energyDrinkB) {
        int n = energyDrinkA.size();

        ll dpA = energyDrinkA[0];
        ll dpB = energyDrinkB[0];

        for (int i = 1; i < n; ++i) {
            ll newDpA = max(dpA + energyDrinkA[i], dpB);
            ll newDpB = max(dpB + energyDrinkB[i], dpA);
            dpA = newDpA;
            dpB = newDpB;
        }

        return max(dpA, dpB);
    }
};