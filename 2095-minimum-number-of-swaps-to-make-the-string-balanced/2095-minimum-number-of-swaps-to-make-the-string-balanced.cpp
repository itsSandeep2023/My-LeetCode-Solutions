class Solution {
public:
    int minSwaps(string s) {
        ios::sync_with_stdio(false);
        
        int n = s.size();

        int i{0}, j = n-1;

        int ans{0};

        int l{0}, r{0};

        while(i<j)
        {
           while(i<j and (s[i] == '[' or l>0))
           {
                if(s[i] == '[')
                    l++;
                else
                    l--;
                i++;
           }

           while(i<j and (s[j] == ']' or r>0))
           {
                if(s[j] == ']')
                    r++;
                else
                    r--;
                j--;
           }

           if(i>=j)
                break;

           l++;
           r++;
           i++;
           j--;
           ans++;
        }

        return ans;
    }
};