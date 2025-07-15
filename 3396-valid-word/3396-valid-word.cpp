class Solution {
public:
    bool isValid(string word) {
        bool v = false, c = false;
        int cnt{0};

        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u',
                                      'A', 'E', 'I', 'O', 'U'};

        for (char& ch : word) {
            if (vowels.count(ch)) {
                v = true;
                cnt++;
            } else if (isdigit(ch)) {
                cnt++;
            } else if (isalpha(ch)) {
                c = true;
                cnt++;
            }
            else{
                return false;
            }
        }

        return v && c && (cnt > 2);
    }
};