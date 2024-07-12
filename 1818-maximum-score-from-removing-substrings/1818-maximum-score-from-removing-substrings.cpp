class Solution {
public:
    string removeSubstr(string& s, string& match) {
        int i{0};

        for(int j{0}; j<s.size();j++){
            s[i++] = s[j];
            
            if(i>=2 and s[i-2]==match[0] and s[i-1]==match[1])
            {
                i-=2;
            }
        }

        s.erase(i, s.length());

        return s;
    }

    int maximumGain(string s, int x, int y) {
        int n = s.size();
        int ans{0};

        string maxs = x > y ? "ab" : "ba";
        string mins = x > y ? "ba" : "ab";

        string maxr = removeSubstr(s, maxs);
        int l1 = maxr.length();

        int cr = (n - l1);
        ans += (cr / 2) * max(x, y);
        cout << ans;

        string minr = removeSubstr(maxr, mins);
        int l2 = minr.length();

        cr = (l1 - l2);
        ans += (cr / 2) * min(x, y);

        return ans;
    }
};