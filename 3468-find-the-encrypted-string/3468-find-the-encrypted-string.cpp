class Solution {
public:
    string getEncryptedString(string s, int k) {
        int n = s.size();
        k= k%n;
        string ans;


        for(int i{0};i<n;i++)
        {
            ans.push_back(s[(i+k)%n]);
            cout<<(i+k)%n;

        }

        return ans;
    }
};