class Solution {
public:
    bool isSubset(vector<int>& freq2, vector<int>& temp) {
        for (int i = 0; i < 26; i++) {
            if (temp[i] < freq2[i]) {
                return false;
            }
        }
        return true;
    }

    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        ios::sync_with_stdio(false);
        
        vector<string> result;

        vector<int> freq2(26);
        for (string& word : words2) {
            int temp[26] = {0};

            for (char& ch : word)
                temp[ch - 'a']++;

            for (int i{0}; i < 26; i++) {
                freq2[i] = max(freq2[i], temp[i]);
            }
        }
        for (string& word : words1) {
            vector<int> temp(26, 0);

            for (char& ch : word) {
                temp[ch - 'a']++;
            }

            if (isSubset(freq2, temp) == true) {
                result.push_back(word);
            }
        }

        // T.C : O(n*l1 m*l2) = overall saare characters of words1 and words2
        // S,C : O(26) ~= O(1)

        return result;
    }
};