class Solution {
public:
    bool canChange(string start, string target) {
        ios::sync_with_stdio(false);
        
        int n = start.size();

        int i{0}, j{0};

        int scnt{0}, tcnt{0};

        for (int i{0}; i < n; i++) {
            if (start[i] == '_')
                scnt++;
            if (target[i] == '_')
                tcnt++;
        }

        if (scnt != tcnt)
            return false;

        while (i < n) {
            if (start[i] == '_')
                i++;

            if (target[j] == '_')
                j++;

            if (start[i] != '_' and target[j] != '_') {
                if (start[i] != target[j])
                    return false;

                if (start[i] == 'L' and i < j)
                    return false;

                if (start[i] == 'R' and i > j)
                    return false;

                i++;
                j++;
            }
        }

        return true;
        ;
    }
};