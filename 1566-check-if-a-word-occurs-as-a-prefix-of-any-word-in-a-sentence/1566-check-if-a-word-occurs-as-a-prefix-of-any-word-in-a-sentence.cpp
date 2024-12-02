class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        string token;
        int ans = 0;
        int n = searchWord.size();

        while (ss >> token) {
            ans++;
            if (token.size() < n)
                continue;

            bool isPrefix = true;
            for (int i = 0; i < n; i++) {
                if (searchWord[i] != token[i]) {
                    isPrefix = false;
                    break;
                }
            }

            if (isPrefix)
                return ans;
        }

        return -1;
    }
};