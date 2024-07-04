class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n==0)
        {
            return 0;
        }
        else if(n==1)
        {
            return 1;
        }

        int largest = 1;
        int k = -1;

        for(int i {1};i<n;i++)
        {
            for(int j{i-1};j>k;j--)
            {
                if(s[j]==s[i])
                {
                    k=j;
                    break;
                }
            }
            largest = max(largest,(i-k));

        }

        return largest;
    }
};