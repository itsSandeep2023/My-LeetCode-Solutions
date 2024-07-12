class Solution {
public:
    string removeSubstr(string& s, string& match) {
        stack<char> st;

        for (char& ch : s) {
            if (ch == match[1] and !st.empty() and st.top() == match[0]) {
                st.pop();
            } else {
                st.push(ch);
            }
        }

        string temp;

        while (!st.empty()) {
            temp.push_back(st.top());
            st.pop();
        }

        reverse(begin(temp), end(temp));
        return temp;
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
        cout<<ans;

        string minr = removeSubstr(maxr, mins);
        int l2 = minr.length();

        cr = (l1 - l2);
        ans += (cr / 2) * min(x, y);

        return ans;
    }
};