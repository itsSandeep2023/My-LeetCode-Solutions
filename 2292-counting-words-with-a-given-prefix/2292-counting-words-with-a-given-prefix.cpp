class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n = pref.size();
        int ans{0};

        for(auto& s : words)
        {
            if(s.size() >= n)
            {
                int i{0};

                while(i<n and s[i] == pref[i])
                    i++;
                
                if(i==n)
                    ans++;
            }
        }

        return ans;
    }
};