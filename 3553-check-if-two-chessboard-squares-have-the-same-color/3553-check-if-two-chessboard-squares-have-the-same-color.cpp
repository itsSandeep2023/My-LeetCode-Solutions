class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        int a = coordinate1[0] - 'a' + 1;
        int b = coordinate2[0] - 'a' + 1;

        int c = coordinate1[1] - '0' ;
        int d = coordinate2[1] - '0' ;

        if(a%2 == b%2)
        {
            return c%2 == d%2;
        }

        return c%2 !=d%2;

    }
};