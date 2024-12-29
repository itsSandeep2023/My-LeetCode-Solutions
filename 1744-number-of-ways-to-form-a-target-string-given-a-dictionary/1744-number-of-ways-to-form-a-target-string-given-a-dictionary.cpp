#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int numWays(vector<string>& words, string target) {
        const int MOD = 1e9 + 7;
        int n = words[0].size(); // Number of columns
        int m = target.size();   // Length of the target

        // Step 1: Precompute character frequencies for each column
        vector<vector<int>> charFrequency(n, vector<int>(26, 0));
        for (const string& word : words) {
            for (int j = 0; j < n; ++j) {
                charFrequency[j][word[j] - 'a']++;
            }
        }

        // Step 2: Initialize a DP array
        vector<int> dp(m + 1, 0);
        dp[0] = 1; // Base case: 1 way to form an empty target

        // Step 3: Iterate through columns
        for (int col = 0; col < n; ++col) {
            // Step 4: Update DP array in reverse to avoid overwriting
            for (int targetIndex = m - 1; targetIndex >= 0; --targetIndex) {
                char targetChar = target[targetIndex];
                int count = charFrequency[col][targetChar - 'a'];

                if (count > 0) {
                    dp[targetIndex + 1] =
                        (dp[targetIndex + 1] +
                         (long long)dp[targetIndex] * count % MOD) %
                        MOD;
                }
            }
        }

        // Step 5: Return the result
        return dp[m];
    }
};