class Solution {
public:
    string convertDateToBinary(string date) {
        auto gao = [&](int x) {
            string ret;
            for (; x; x >>= 1)
                ret.push_back((x & 1) + '0');
            reverse(ret.begin(), ret.end());
            return ret;
        };
        return gao(stoi(date.substr(0, 4))) + "-" +
               gao(stoi(date.substr(5, 2))) + "-" +
               gao(stoi(date.substr(8, 2)));
    }
};