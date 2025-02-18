class Solution {
public:
    string smallestNumber(string pattern) {
        string ans;
        int n = pattern.size();

        int i{0};
        int k{1};

        while (i < n) {
            if (pattern[i] == 'I') {
                ans.push_back(k + '0');
                k++;
                i++;
            } else {
                int l = k;
                while (i < n and pattern[i] == 'D') {
                    k++;
                    i++;
                }

                int s = k;
                while (s >= l) {
                    ans.push_back(s + '0');
                    s--;
                }
                k++;
                i++;
            }
        }

        if (ans.size()<=n)
            ans.push_back(k + '0');

        return ans;
    }
};