class Solution {
public:
    long halfToPalindrome(long firstHalf, bool odd) {
        long ans = firstHalf;
        if (odd) {
            firstHalf = firstHalf / 10;
        }

        while (firstHalf > 0) {
            int digit = firstHalf % 10;
            ans = (ans * 10) + digit;
            firstHalf /= 10;
        }
        return ans;
    }

    string nearestPalindromic(string n) {
        ios::sync_with_stdio(false);
        int len = n.size();

        int mid = len / 2;
        long firstHalf = stol(n.substr(0, len % 2 == 0 ? mid : mid + 1));
       
        vector<long> possibleAns;

        possibleAns.push_back(halfToPalindrome(firstHalf, len % 2 == 1));
        possibleAns.push_back(halfToPalindrome(firstHalf + 1, len % 2 == 1));
        possibleAns.push_back(halfToPalindrome(firstHalf - 1, len % 2 == 1));
        possibleAns.push_back((long)pow(10, len - 1) - 1);
        possibleAns.push_back((long)pow(10, len) + 1);

        long diff = LONG_MAX;
        long ans = 0;
        long originalNum = stol(n);

        for (long &num : possibleAns) {
            if (num == originalNum) continue;
            if (abs(num - originalNum) < diff) {
                diff = abs(num - originalNum);
                ans = num;
            } else if (abs(num - originalNum) == diff) {
                ans = min(ans, num);
            }
        }

        return to_string(ans);
    }
};