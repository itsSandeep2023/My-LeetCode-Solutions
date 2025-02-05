class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int cnt{0};
        int mp[26] = {0};

        for (int i{0}, n = s1.size(); i < n; i++) {
            mp[s1[i]-'a']++;
            mp[s2[i]-'a']--;
            if (s1[i] != s2[i])
                cnt++;
        }

        for(auto& x : mp)
            if(x!=0)
                return false;


        if (cnt != 0 and cnt != 2)
            return false;

        return true;
    }
};