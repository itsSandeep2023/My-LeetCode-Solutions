class Solution {
public:
    string answerString(string word, int numFriends) {
        int n = word.size();
        string ans;

        auto helper = [&](string& s){
            if(ans.size()<s.size())
                ans = s;
            else
                ans = s>ans?s:ans;
        };

        if (n == 1 or numFriends == 1)
            return word;

        char target = 'a';
        for(auto c: word)
            if(c>target) target = c;

        for(int i{0}; i<n; i++)
        {
            if(word[i] == target)
            {
                int mxlength = min(n - numFriends + 1, n - i);
                string s = word.substr(i, mxlength);
                helper(s);
            }
        }

        cout<<target;
        
        return ans;
    }
};