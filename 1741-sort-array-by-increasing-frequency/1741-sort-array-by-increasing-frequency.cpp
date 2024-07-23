class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        // ios::sync_with_stdio(false);

        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        
        sort(nums.begin(), nums.end(), [&freq](int a, int b) {
            if (freq[a] == freq[b]) {
                return a > b;
            }
            return freq[a] < freq[b];
        });
    
        return nums;
    }
};