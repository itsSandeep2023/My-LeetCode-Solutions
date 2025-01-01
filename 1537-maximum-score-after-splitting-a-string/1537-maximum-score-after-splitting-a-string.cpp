class Solution {
public:
    int maxScore(string s) {
        int n = s.size();

        int zeros = 0;
        int ones = count(s.begin(), s.end(), '1');

        int maximum = 0;

        for(int i{0};i<n-1;i++)
        {
            if(s[i]=='0')
            {
                zeros++;
            }
            else
            {
                ones--;
            }

            maximum = max(maximum, (ones + zeros));
        }


        return maximum;
    }
};