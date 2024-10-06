class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        if(s1.size()< s2.size()) swap(s1, s2);

        vector<string> ws1;
        vector<string> ws2;

        stringstream ss1(s1);
        stringstream ss2(s2);
        string token;

        while(getline(ss1, token, ' '))
            ws1.push_back(token);
        
        while(getline(ss2, token, ' '))
            ws2.push_back(token);

        int n = ws1.size();
        int m = ws2.size();

        int i{0}, j{n-1};
        int k{0}, l{m-1};

        while(i<n and k<m and ws1[i]==ws2[k])
        {
            i++; 
            k++;
        }

        while(j>=i and l>=k and ws1[j]==ws2[l])
        {
            j--;
            l--;
        }

        return k>l;
    }
};