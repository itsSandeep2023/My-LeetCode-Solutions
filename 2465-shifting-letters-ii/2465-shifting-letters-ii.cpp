class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> diff(n, 0);

        for (const auto& shift : shifts) {
            int start = shift[0];
            int end = shift[1];
            int direction = shift[2];

            if (direction == 1) {
                diff[start] += 1;
                if (end + 1 < n)
                    diff[end + 1] -= 1;
            } else {
                diff[start] -= 1;
                if (end + 1 < n)
                    diff[end + 1] += 1;
            }
        }

        int currentShift = 0;
        for (int i = 0; i < n; i++) {
            currentShift = (currentShift + diff[i]) % 26;
            s[i] = 'a' + (s[i] - 'a' + currentShift + 26) % 26; 
        }

        return s;
    }
};
