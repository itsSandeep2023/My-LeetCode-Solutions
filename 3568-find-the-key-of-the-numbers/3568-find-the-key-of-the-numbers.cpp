class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        int a1 = (num1/1000)%10, a2 = (num1/100)%10, a3 = (num1/10)%10, a4 = num1%10;
        int b1 = (num2/1000)%10, b2 = (num2/100)%10, b3 = (num2/10)%10, b4 = num2%10;
        int c1 = (num3/1000)%10, c2 = (num3/100)%10, c3 = (num3/10)%10, c4 = num3%10;

        int ans {0};

        ans += min({a1, b1, c1,})*1000;
        cout<<ans;
        ans += min({a2, b2, c2})*100;
        ans += min({a3, b3, c3})*10;
        ans += min({a4, b4, c4});

        return ans;
    }
};