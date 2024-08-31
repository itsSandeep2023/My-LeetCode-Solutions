class Solution {
public:
    string stringHash(string s, int k) {
        unordered_map<int, std::string> mp = {
            {0, "a"},  {1, "b"},  {2, "c"},  {3, "d"},  {4, "e"},  {5, "f"},
            {6, "g"},  {7, "h"},  {8, "i"},  {9, "j"},  {10, "k"}, {11, "l"},
            {12, "m"}, {13, "n"}, {14, "o"}, {15, "p"}, {16, "q"}, {17, "r"},
            {18, "s"}, {19, "t"}, {20, "u"}, {21, "v"}, {22, "w"}, {23, "x"},
            {24, "y"}, {25, "z"}};

        string ans;

        for (int i{0}; i < s.size();) {
            int t = 0;
            int cnt{0};
            while (t++ < k) {
                cnt += s[i] - 'a';
                i++;
            }
            ans+=mp[cnt%26];
        }

        return ans;
    }
};