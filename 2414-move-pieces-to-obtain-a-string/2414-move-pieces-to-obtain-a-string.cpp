class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size();

        int i{0}, j{0};

        while (i < n or j < n) {
            while(i<n and start[i] == '_')
                i++;

            while(j<n and target[j] == '_')
                j++;

            if (i==n or j==n)
                return (i==n and j==n);

            if (start[i] != target[j])
                return false;

            if (start[i] == 'L' and i < j)
                return false;

            if (start[i] == 'R' and i > j)
                return false;

            i++;
            j++;
        }

        return true;
        ;
    }
};