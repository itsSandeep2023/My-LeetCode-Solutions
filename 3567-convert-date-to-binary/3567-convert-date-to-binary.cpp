class Solution {
public:
    string convertDateToBinary(string date) {
        int year = stoi(date.substr(0, 4));
        int mon = stoi(date.substr(5, 2));
        int dt = stoi(date.substr(8, 2));

        string ans;

        while (dt > 0) {
            ans = (dt & 1 ? "1" : "0") + ans;
            dt /= 2;
        }
        ans = "-" + ans;
        while (mon > 0) {
            ans = (mon & 1 ? "1" : "0") + ans;
            mon /= 2;
        }
        ans = "-" + ans;
        while (year > 0) {
            ans = (year & 1 ? "1" : "0") + ans;
            year/=2;
        }
        return ans;
    }
};